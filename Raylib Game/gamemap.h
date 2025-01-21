Model MDL_CUBE;
Model MDL_DISCARD;
struct Cube {
	Vector3 center;
	Vector3 size;
	Color color;
};
struct Map {
	int num_of_cubes;
	Cube cubes[10];
};
void DrawCubeStruct(Cube cube) {
	rlScalef(cube.size.x, cube.size.y, cube.size.z);
	DrawModel(MDL_CUBE, Vector3Divide(cube.center, cube.size), 1, cube.color);
	rlScalef(1.0f / cube.size.x, 1.0f / cube.size.y, 1.0f / cube.size.z);
}
/*
void draw_texture_cube(Vector3 center, Vector3 size, Color tint, int textureID, int flags) {
	Vector3 fixedposition = { -center.x / size.x,center.y / (size.y),-center.z / size.z };
	if (flags & (1 << 2)) {
		float sx = size.x;
		if (sx < size.z) sx = size.z;
		rlScalef(-size.x, sx, -size.z);
		int repeat = size.y / sx;
		for (int i = 0; i < repeat; i++) {
			DrawModel(models["CUBE"], Vector3Add(fixedposition, { 0, (float)i, 0 }), 1, tint);
		}
		rlScalef(1.0 / -size.x, 1.0 / (sx), 1.0 / -size.z);
	}
	else {
		rlScalef(-size.x, size.y, -size.z);
		DrawModel(models["CUBE"], fixedposition, 1, tint);
		rlScalef(1.0 / -size.x, 1.0 / size.y, 1.0 / -size.z);
	}
}
*/
void InitModels() {
	MDL_CUBE = LoadModelFromMesh(GenMeshCube(1, 1, 1));
	MDL_CUBE.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = TXT_BRICK;
}
Map map = {
	1,
	{ 
		{ 
			{0, 10, 20}, {20,20,2}, WHITE,
		} 
	},
};