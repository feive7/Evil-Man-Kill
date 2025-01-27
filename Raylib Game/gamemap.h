#define MAX_CUBES 100
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
	Cube cubes[MAX_CUBES];
	int num_of_cubes;
	void init() {
		int i;
		for (i = 0; i < MAX_CUBES; i++) {
			if (cubes[i].flags) {
				this->num_of_cubes = i + 1;
			}
		}
		printf("Map initialized with %i cubes\n", num_of_cubes);
	}
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
enum CUBEFLAGS {
	COLLISIONS = 1,
	VISIBLE = 2,
};
Map hub = {
	{ 
		{ 
			{0, -5, 0}, {100,10,100}, GRAY, 2,
		},// Floor
		{
			{50, 10, 0}, {2,20,100}, RED, 3,
		},
		{
			{-50, 10, 0}, {2,20,100}, RED, 3,
		},
		{
			{0, 10, 50}, {100,20,2}, RED, 3,
		},
		{
			{0, 10, -50}, {100,20,2}, RED, 3,
		},
		{
			{0, 25, 0}, {100,10,100}, GRAY, 2,
		},// Ceiling

		{
			{0, 5, 0}, {2,2,2}, BLUE, 3,
		},
	},
};
Map map = {
	{
		{
			{0,-5,0}, {60,10,60}, GRAY, VISIBLE,
		},
		{
			{0,5,0}, {5,10,5}, RED, VISIBLE + COLLISIONS,
		},
	}
};
