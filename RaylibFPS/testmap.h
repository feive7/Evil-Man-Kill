static GameMap testmap = {
	{ // Walls
		{ // Cube
			.points = {{10.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_GRASS,
			.tint = {0,76,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
		{ // Empty
			.position = {-0.0f,-0.2f,6.0f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE,
		},

	},
};