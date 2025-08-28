static GameMap testmap = {
	{ // Walls
		{ // Cube
			.points = {{-5.0f,1.0f},{-7.0f,1.0f},{-7.0f,-1.0f},{-5.0f,-1.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.005
			.points = {{7.0f,1.0f},{5.0f,1.0f},{5.0f,-1.0f},{7.0f,-1.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.006
			.points = {{1.0f,-7.0f},{1.0f,-5.0f},{-1.0f,-5.0f},{-1.0f,-7.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.007
			.points = {{1.0f,5.0f},{1.0f,7.0f},{-1.0f,7.0f},{-1.0f,5.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.008
			.points = {{-39.0f,1.0f},{-41.0f,1.0f},{-41.0f,-1.0f},{-39.0f,-1.0f}},
			.z = -1.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.008
			.points = {{39.0f,1.0f},{39.0f,-1.0f},{41.0f,-1.0f},{41.0f,1.0f}},
			.z = 1.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.008
			.points = {{1.0f,41.0f},{-1.0f,41.0f},{-1.0f,39.0f},{1.0f,39.0f}},
			.z = 1.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.008
			.points = {{1.0f,-41.0f},{1.0f,-39.0f},{-1.0f,-39.0f},{-1.0f,-41.0f}},
			.z = -1.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Plane
			.points = {{5.0f,-5.0f},{5.0f,5.0f},{-5.0f,5.0f},{-5.0f,-5.0f}},
			.z = -10.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane
			.points = {{-5.0f,5.0f},{-45.0f,5.0f},{-45.0f,-5.0f},{-5.0f,-5.0f}},
			.z = -10.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane
			.points = {{5.0f,5.0f},{5.0f,45.0f},{-5.0f,45.0f},{-5.0f,5.0f}},
			.z = -10.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane
			.points = {{5.0f,-5.0f},{45.0f,-5.0f},{45.0f,5.0f},{5.0f,5.0f}},
			.z = -10.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane
			.points = {{-5.0f,-5.0f},{-5.0f,-45.0f},{5.0f,-45.0f},{5.0f,-5.0f}},
			.z = -10.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
};