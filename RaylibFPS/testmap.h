static GameMap testmap = {
	{ // Walls
		{ // Cube
			.points = {{10.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &GRASS,
			.tint = {0,70,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{-1.0f,7.0f},{-3.0f,7.0f},{-3.0f,5.0f},{-1.0f,5.0f}},
			.z = 0.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
		{ // Empty.001
			.position = {-0.0f,0.0f,6.0f},
			.size = 2.0,
			.texture = &obj_barrel,
		},

		{ // Empty.002
			.position = {1.751f,0.0f,6.0f},
			.size = 2.0,
			.texture = &npc_john,
		},

	},
};