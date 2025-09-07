static GameMap MAP_ABSTRACTIONS = {
	{ // Sky Color
		255,255,255,255,
	},
	{ // Walls
		{ // Cube
			.points = {{30.49f,22.04f},{29.71f,23.88f},{27.87f,23.1f},{28.64f,21.26f}},
			.z = 1.24f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{-100.0f,-100.0f},{-100.0f,100.0f},{-102.0f,100.0f},{-102.0f,-100.0f}},
			.z = 0.0f,
			.height = 40.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube.002
			.points = {{100.0f,100.0f},{100.0f,102.0f},{-100.0f,102.0f},{-100.0f,100.0f}},
			.z = -0.0f,
			.height = 40.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube.003
			.points = {{102.0f,-100.0f},{102.0f,100.0f},{100.0f,100.0f},{100.0f,-100.0f}},
			.z = -0.0f,
			.height = 40.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube.004
			.points = {{100.0f,-102.0f},{100.0f,-100.0f},{-100.0f,-100.0f},{-100.0f,-102.0f}},
			.z = -0.0f,
			.height = 40.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube.005
			.points = {{31.7f,19.29f},{30.93f,21.14f},{29.08f,20.36f},{29.86f,18.52f}},
			.z = 2.24f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.006
			.points = {{34.13f,13.72f},{33.36f,15.56f},{31.51f,14.78f},{32.29f,12.94f}},
			.z = 4.24f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.007
			.points = {{32.92f,16.55f},{32.14f,18.4f},{30.3f,17.62f},{31.08f,15.78f}},
			.z = 3.24f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.008
			.points = {{32.68f,9.35f},{33.51f,11.17f},{31.68f,12.0f},{30.86f,10.18f}},
			.z = 4.949f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.009
			.points = {{31.26f,6.75f},{32.09f,8.57f},{30.27f,9.4f},{29.44f,7.57f}},
			.z = 5.894f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.010
			.points = {{29.75f,3.75f},{30.57f,5.57f},{28.75f,6.4f},{27.92f,4.58f}},
			.z = 6.949f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.011
			.points = {{28.36f,1.02f},{29.19f,2.84f},{27.37f,3.66f},{26.54f,1.84f}},
			.z = 7.855f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.012
			.points = {{26.98f,-1.72f},{27.8f,0.11f},{25.98f,0.93f},{25.16f,-0.89f}},
			.z = 8.89f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.013
			.points = {{23.53f,11.65f},{23.53f,12.65f},{22.53f,12.65f},{22.53f,11.65f}},
			.z = 11.5f,
			.height = 1.0f,
			.texture = &TEX_TILE_6,
			.tint = {255,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.stretchTexture = true,
			.tickFunction = [](Wall* self) {
				self->rotate(GetFrameTime());
			},
		},

		{ // Floor
			.points = {{100.0f,-100.0f},{100.0f,100.0f},{-100.0f,100.0f},{-100.0f,-100.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Plane.001
			.points = {{-17.49f,9.06f},{-18.9f,16.57f},{-28.44f,18.03f},{-31.25f,7.54f}},
			.z = 0.0f,
			.height = 14.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.002
			.points = {{23.95f,-3.54f},{32.39f,13.14f},{27.2f,24.82f},{11.84f,11.1f}},
			.z = 0.0f,
			.height = 11.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.003
			.points = {{-3.01f,-28.95f},{0.86f,-16.82f},{-13.97f,-19.99f},{-10.2f,-26.6f}},
			.z = 0.0f,
			.height = 12.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.004
			.points = {{2.42f,12.83f},{7.73f,26.15f},{-2.52f,32.78f},{-13.39f,19.08f}},
			.z = 0.0f,
			.height = 15.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-25.71f,-20.13f},{-20.4f,-6.81f},{-33.64f,-5.58f},{-34.99f,-16.86f}},
			.z = 0.0f,
			.height = 13.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.006
			.points = {{23.39f,-26.17f},{25.49f,-16.66f},{14.42f,-14.27f},{11.49f,-26.81f}},
			.z = 0.0f,
			.height = 11.0f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
	},
};