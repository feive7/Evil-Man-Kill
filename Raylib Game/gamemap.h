Model MDL_CUBE;
Model MDL_DISCARD;
struct Cube {
	Vector3 center;
	Vector3 size;
	Color color;
	int flags;
	BoundingBox boundingBox() {
		BoundingBox b = {
			Vector3Subtract(center, Vector3Scale(size,.5)),
			Vector3Add(center, Vector3Scale(size,.5)),
		};
		return b;
	}
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
void InitModels() {
	MDL_CUBE = LoadModelFromMesh(GenMeshCube(1, 1, 1));
	MDL_CUBE.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = TXT_DEBUGTILE;
}
Map map = {
	5,
	{ 
		{ 
			{0, -5, 0}, {100,10,100}, GRAY, 0,
		},// Floor
		{
			{50, 10, 0}, {2,20,100}, RED, 1,
		},
		{
			{-50, 10, 0}, {2,20,100}, RED, 1,
		},
		{
			{0, 10, 50}, {100,20,2}, RED, 1,
		},
		{
			{0, 10, -50}, {100,20,2}, RED, 1,
		},
	},
};