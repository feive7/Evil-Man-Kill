bl_info = {
    "name": "Evil Man Kill exporter",
    "author": "Roland Baker",
    "version": (1, 0),
    "blender": (3, 0, 0),
    "description": "Addon for my game",
    "warning": "",
    "category": "Import-Export",
}

import bpy
import os
import mathutils
from math import atan2
import re

# ---------------- Settings ----------------
surface_materials = {"regular", "bouncy", "lava", "mud", "ladder"}

# ---------------- Utilities ----------------
def getAttributes(obj):
    """Grab custom object attributes except RNA_UI"""
    return {k: obj[k] for k in obj.keys() if k not in "_RNA_UI"}

def FormatColor(bpyColor):
    return [int(channel * 255) for channel in bpyColor]

def FormatText(string, *replacements):
    for r in replacements:
        if isinstance(r, (list, tuple)):
            for item in r:
                string = FormatText(string, item)
        else:
            repl = str(round(r, 3)) if isinstance(r, (int, float)) else str(r)
            string = string.replace("%", repl, 1)
    return string

def getPolyNormal(obj, poly):
    mesh = obj.data
    mat = obj.matrix_world
    normal = poly.normal
    fixed = (mat.inverted_safe().transposed().to_3x3() @ normal).normalized()
    return fixed

def argsort(seq):
    #http://stackoverflow.com/questions/3382352/equivalent-of-numpy-argsort-in-basic-python/3382369#3382369
    #by unutbu
    #https://stackoverflow.com/questions/3382352/equivalent-of-numpy-argsort-in-basic-python 
    # from Boris Gorelik
    return sorted(range(len(seq)), key=seq.__getitem__)

def rotational_sort(list_of_xy_coords, clockwise=True):
    centre_of_rotation_xy_coord = [0,0]
    for p in list_of_xy_coords:
        centre_of_rotation_xy_coord[0] += p[0]
        centre_of_rotation_xy_coord[1] += p[1]
    centre_of_rotation_xy_coord[0] /= len(list_of_xy_coords)
    centre_of_rotation_xy_coord[1] /= len(list_of_xy_coords)
    cx,cy=centre_of_rotation_xy_coord
    angles = [atan2(x-cx, y-cy) for x,y,z in list_of_xy_coords]
    indices = argsort(angles)
    if clockwise:
        return [list_of_xy_coords[i] for i in indices]
    else:
        return [list_of_xy_coords[i] for i in indices[::-1]]

# ---------------- Wall Class ----------------
class Wall:
    def __init__(self):
        self.name = ""
        self.points = []
        self.z = 0
        self.height = 0
        self.texture = ""
        self.color = []
        self.surfaceMaterial = "regular" 
        self.canSpawn = False
        self.hide = False
        self.ignoreCollisions = False
        self.stretchTexture = False
        self.tickFunction = ""
        self.attributes = {}

    def fromPoly(self, obj, poly):
        self.name = obj.name
        mesh = obj.data
        matrix = obj.matrix_world

        verts_world = [matrix @ mesh.vertices[i].co for i in poly.vertices]
        unsorted_points = [(-round(v.x, 2), round(v.y, 2), round(v.z, 2)) for v in verts_world]
        center = obj.location
        
        self.points = rotational_sort(unsorted_points,False)

        all_z = [matrix @ v.co for v in mesh.vertices]
        z_vals = [v.z for v in all_z]
        self.height = round(max(z_vals) - min(z_vals), 2)
        self.z = verts_world[0].z

        self.texture = obj.game_props.texture
        self.color = FormatColor(obj.color)

        self.canSpawn = obj.game_props.can_spawn
        self.surfaceMaterial = obj.game_props.surface_material
        self.hide = obj.display_type == 'WIRE'
        self.ignoreCollisions = obj.game_props.ignore_collisions
        self.stretchTexture = obj.game_props.stretch_texture
        
        if obj.game_props.script_file: self.tickFunction = bpy.data.texts[obj.game_props.script_file].as_string()

    def export(self):
        cpp = FormatText("{ // %\n", self.name)

        # Required
        cpp += "\t\t\t.points = {{%f,%f},{%f,%f},{%f,%f},{%f,%f}},\n"
        for v in self.points:
            cpp = FormatText(cpp, v[0], v[1])

        cpp += FormatText("\t\t\t.z = %f,\n", self.z)
        cpp += FormatText("\t\t\t.height = %f,\n", self.height)

        if self.texture: cpp += FormatText("\t\t\t.texture = &TEX_%,\n", self.texture.upper())

        cpp += FormatText("\t\t\t.tint = {%,%,%,%},\n", self.color)
        if self.surfaceMaterial: cpp += FormatText("\t\t\t.surfaceMaterial = SURFACE_%,\n", self.surfaceMaterial.upper())

        if self.canSpawn: cpp += "\t\t\t.canSpawn = true,\n"
        if self.hide: cpp += "\t\t\t.hide = true,\n"
        if self.ignoreCollisions: cpp += "\t\t\t.ignoreCollisions = true,\n"
        if self.stretchTexture: cpp += "\t\t\t.stretchTexture = true,\n"
        
        if self.tickFunction: 
            cpp += "\t\t\t.tickFunction = [](Wall* self) {\n"
            cpp += "\t\t\t\t" + self.tickFunction.replace("\n","\n\t\t\t\t") + "\n"
            cpp += "\t\t\t},\n"

        return cpp + "\t\t},\n"


# ---------------- Export Logic ----------------
def ObjectToStructs(obj):
    mesh = obj.data
    walls = []

    for poly in mesh.polygons:
        if round(getPolyNormal(obj, poly).z) == -1 and len(poly.vertices) == 4:
            wall = Wall()
            wall.fromPoly(obj, poly)
            walls.append(wall)

    print(f"{obj.name} generated {len(walls)} walls")
    return walls

def EmptyToStruct(empty):
    pos = empty.location
    size = empty.empty_display_size
    texture = re.match(r'.+?(?=\.)', empty.data.name)[0]
    cpp_struct = FormatText("{ // %\n", empty.name)
    cpp_struct += FormatText("\t\t\t.position = {%f,%f,%f},\n", -pos.x, pos.z, pos.y)
    cpp_struct += FormatText("\t\t\t.size = %f,\n", size)
    cpp_struct += FormatText("\t\t\t.texture = &TEX_%,\n", texture.upper())
    cpp_struct += "\t\t},\n"
    return cpp_struct

def export_to_file(filepath, map_name, walls, things):
    walls = sorted(walls, key=lambda wall: 255 - wall.color[3])
    with open(filepath, "w") as f:
        f.write(f"static GameMap {map_name} = {{\n")
        f.write("\t{ // Sky Color\n" + FormatText("\t\t%,%,%,255,\n", FormatColor(bpy.context.scene.world.color)) + "\t},\n")
        f.write("\t{ // Walls\n" + ''.join(f"\t\t{s.export()}\n" for s in walls) + "\t},\n")
        f.write("\t{ // Things\n" + ''.join(f"\t\t{s}\n" for s in things) + "\t},\n")
        f.write("};")

# ---------------- Operator ----------------
class GameProps(bpy.types.PropertyGroup):
    surface_material: bpy.props.EnumProperty(
        name="Surface Material",
        items=[
            ('regular', 'None', ''),
            ('bouncy', 'Bouncy', ''),
            ('lava', 'Lava', ''),
            ('ladder', 'Ladder', ''),
        ],
        default='regular'
    )
    texture: bpy.props.StringProperty(
        name="Texture",
        default=""
    )
    script_file: bpy.props.StringProperty(
        name="Script File"
    )
    can_spawn: bpy.props.BoolProperty(
        name="Can Spawn"
    )
    ignore_collisions: bpy.props.BoolProperty(
        name="Ignore Collisions"
    )
    stretch_texture: bpy.props.BoolProperty(
        name="Stretch Texture"
    )

# Define a panel so it shows up in the UI
class OBJECT_PT_GamePropsPanel(bpy.types.Panel):
    bl_label = "Game Properties"
    bl_idname = "OBJECT_PT_game_props_panel"
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'WINDOW'
    bl_context = "object"  # Shows up in the Object Properties tab

    def draw(self, context):
        layout = self.layout
        props = context.object.game_props   # get the PropertyGroup

        layout.prop(props, "surface_material")
        layout.prop(props, "texture")
        layout.prop(props, "script_file")
        layout.prop(props, "can_spawn")
        layout.prop(props, "ignore_collisions")
        layout.prop(props, "stretch_texture")
        
class EXPORT_OT_walls_to_cpp(bpy.types.Operator):
    """Export Walls to C++ Map"""
    bl_idname = "export_scene.walls_to_cpp"
    bl_label = "Export Walls to C++ Map"
    bl_options = {"REGISTER", "UNDO"}

    filepath: bpy.props.StringProperty(
        name="File Path",
        description="Where to export the C++ header",
        subtype="FILE_PATH",
        default="C:/Users/rolan/OneDrive/Documents/Roland C++/RaylibFPS/RaylibFPS/maps/"
    )

    map_name: bpy.props.StringProperty(
        name="Map Name",
        description="Name of the exported GameMap",
        default="placeholder"
    )
    def getMapVariableName(self, context):
        collectionname = context.scene.collection.children[0].name
        underscored = collectionname.replace(" ","_")
        variablename = "MAP_" + underscored.upper()
        return variablename
    def execute(self, context):
        walls = []
        things = []
        for obj in bpy.data.objects:
            if obj and obj.visible_get():
                if obj.type == 'MESH':
                    walls.extend(ObjectToStructs(obj))
                elif obj.type == 'EMPTY' and obj.data:
                    things.append(EmptyToStruct(obj))
        export_to_file(self.filepath + self.getMapVariableName(context) + ".h", self.getMapVariableName(context), walls, things)
        self.report({'INFO'}, f"Exported {len(walls)} walls and {len(things)} things to {self.filepath}")
        return {"FINISHED"}
# ---------------- Misc Tools ------------------
class MatchMaterials(bpy.types.Operator):
    bl_idname = "object.match_material"
    bl_label = "Match Game Material"
    bl_options = {'REGISTER','UNDO'}
    
    def execute(self,context):
        active_object = context.active_object
        for obj in context.selected_objects:
            obj.game_props.texture = active_object.game_props.texture
            obj.color = active_object.color
        return {'FINISHED'}


# ---------------- Registration ----------------
def menu_func_export(self, context):
    self.layout.operator(EXPORT_OT_walls_to_cpp.bl_idname, text="Walls to C++ Map (.h)")
def menu_func_match_material(self,context):
    self.layout.operator(MatchMaterials.bl_idname)

def register():
    bpy.utils.register_class(EXPORT_OT_walls_to_cpp)
    bpy.utils.register_class(OBJECT_PT_GamePropsPanel)
    bpy.utils.register_class(GameProps)
    bpy.utils.register_class(MatchMaterials)
    bpy.types.TOPBAR_MT_file_export.append(menu_func_export)
    bpy.types.VIEW3D_MT_object.append(menu_func_match_material)
    bpy.types.Object.game_props = bpy.props.PointerProperty(type=GameProps)

def unregister():
    bpy.types.TOPBAR_MT_file_export.remove(menu_func_export)
    bpy.types.VIEW3D_MT_object.remove(menu_func_match_material)
    bpy.utils.unregister_class(EXPORT_OT_walls_to_cpp)
    bpy.utils.unregister_class(OBJECT_PT_GamePropsPanel)
    bpy.utils.unregister_class(GameProps)
    bpy.utils.unregister_class(MatchMaterials)
    del bpy.types.Object.game_props  # clean up property on unregister

if __name__ == "__main__":
    register()
