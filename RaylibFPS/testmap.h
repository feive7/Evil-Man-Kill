static GameMap testmap = {
	{ // Sky Color
		12,12,12,255,
	},
	{ // Walls
		{ // Cube
			.points = {{60.0f,-45.0f},{60.0f,75.0f},{-60.0f,75.0f},{-60.0f,-45.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{1.0f,39.0f},{1.0f,41.0f},{-1.0f,41.0f},{-1.0f,39.0f}},
			.z = -1.0f,
			.height = 2.0f,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.002
			.points = {{8.0f,19.0f},{8.0f,21.0f},{-8.0f,21.0f},{-8.0f,19.0f}},
			.z = 0.0f,
			.height = 16.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.003
			.points = {{8.0f,-21.0f},{8.0f,-19.0f},{-8.0f,-19.0f},{-8.0f,-21.0f}},
			.z = 0.0f,
			.height = 16.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.004
			.points = {{8.0f,-7.0f},{8.0f,-5.0f},{-8.0f,-5.0f},{-8.0f,-7.0f}},
			.z = 0.0f,
			.height = 16.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.005
			.points = {{10.0f,-21.0f},{10.0f,-5.0f},{8.0f,-5.0f},{8.0f,-21.0f}},
			.z = 0.0f,
			.height = 16.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
	},
};