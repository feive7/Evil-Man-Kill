static GameMap testmap = {
	{ // Sky Color
		12,12,12,255,
	},
	{ // Walls
		{ // Ceiling
			.points = {{10.0f,-10.0f},{10.0f,30.0f},{-70.0f,30.0f},{-70.0f,-10.0f}},
			.z = 10.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Collision box
			.points = {{10.1f,-0.3f},{10.1f,1.9f},{7.9f,1.9f},{7.9f,-0.3f}},
			.z = 0.0f,
			.height = 4.5f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube
			.points = {{10.0f,-10.0f},{10.0f,30.0f},{-30.0f,30.0f},{-30.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_NOISE_1,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{10.0f,-12.0f},{10.0f,-10.0f},{-30.0f,-10.0f},{-30.0f,-12.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,99,10,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.002
			.points = {{12.0f,-10.0f},{12.0f,30.0f},{10.0f,30.0f},{10.0f,-10.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,99,10,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.003
			.points = {{-13.9f,-9.0f},{-13.9f,7.0f},{-14.1f,7.0f},{-14.1f,-9.0f}},
			.z = 1.5f,
			.height = 0.2f,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.004
			.points = {{-1.3f,-10.7f},{-1.3f,-9.7f},{-1.7f,-9.7f},{-1.7f,-10.7f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_NOISE_1,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.005
			.points = {{1.7f,-10.7f},{1.7f,-9.7f},{1.3f,-9.7f},{1.3f,-10.7f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_NOISE_1,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.006
			.points = {{1.3f,-10.7f},{1.3f,-9.7f},{-1.3f,-9.7f},{-1.3f,-10.7f}},
			.z = 5.6f,
			.height = 0.4f,
			.texture = &TEX_NOISE_1,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.007
			.points = {{3.0f,8.8f},{3.0f,10.8f},{1.0f,10.8f},{1.0f,8.8f}},
			.z = 2.1f,
			.height = 0.4f,
			.texture = &TEX_PLASTER,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.008
			.points = {{2.85f,9.7f},{2.85f,10.6f},{2.35f,10.6f},{2.35f,9.7f}},
			.z = 2.5f,
			.height = 0.4f,
			.texture = &TEX_PLASTER,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.009
			.points = {{10.0f,9.0f},{10.0f,11.0f},{-6.0f,11.0f},{-6.0f,9.0f}},
			.z = 0.0f,
			.height = 1.8f,
			.texture = &TEX_PLASTER,
			.tint = {67,67,67,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.010
			.points = {{10.0f,8.6f},{10.0f,11.0f},{-6.0f,11.0f},{-6.0f,8.6f}},
			.z = 1.8f,
			.height = 0.3f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.011
			.points = {{-13.7f,-9.2f},{-13.7f,7.2f},{-14.3f,7.2f},{-14.3f,-9.2f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.hide = true,
		},

		{ // Cube.012
			.points = {{2.82f,9.71f},{2.82f,10.52f},{2.38f,10.52f},{2.38f,9.71f}},
			.z = 2.88f,
			.height = 0.04f,
			.texture = &TEX_NOISE_1,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.013
			.points = {{1.8f,9.7f},{1.8f,9.9f},{1.6f,9.9f},{1.6f,9.7f}},
			.z = 2.5f,
			.height = 0.4f,
			.texture = &TEX_PLASTER,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.014
			.points = {{2.28f,9.7f},{2.28f,9.9f},{1.12f,9.9f},{1.12f,9.7f}},
			.z = 2.9f,
			.height = 0.8f,
			.texture = &TEX_PLASTER,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.015
			.points = {{-11.0f,9.0f},{-11.0f,11.0f},{-15.0f,11.0f},{-15.0f,9.0f}},
			.z = 0.0f,
			.height = 1.8f,
			.texture = &TEX_PLASTER,
			.tint = {67,67,67,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.016
			.points = {{-11.0f,8.6f},{-11.0f,11.0f},{-15.0f,11.0f},{-15.0f,8.6f}},
			.z = 1.8f,
			.height = 0.3f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.017
			.points = {{2.22f,9.73f},{2.22f,9.93f},{1.18f,9.93f},{1.18f,9.73f}},
			.z = 2.94f,
			.height = 0.72f,
			.texture = &TEX_FABRIC,
			.tint = {127,255,236,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.018
			.points = {{3.6f,8.9f},{3.6f,9.1f},{0.4f,9.1f},{0.4f,8.9f}},
			.z = 0.18f,
			.height = 1.44f,
			.texture = &TEX_FABRIC,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.019
			.points = {{-30.0f,-10.0f},{-30.0f,30.0f},{-31.0f,30.0f},{-31.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.020
			.points = {{-31.0f,-12.0f},{-31.0f,-10.0f},{-69.0f,-10.0f},{-69.0f,-12.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.021
			.points = {{-31.0f,30.1f},{-31.0f,31.9f},{-69.0f,31.9f},{-69.0f,30.1f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_FABRIC,
			.tint = {11,11,11,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Cube.022
			.points = {{-69.0f,-10.0f},{-69.0f,30.0f},{-70.0f,30.0f},{-70.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.023
			.points = {{-31.0f,-10.0f},{-31.0f,9.5f},{-69.0f,9.5f},{-69.0f,-10.0f}},
			.z = -1.1f,
			.height = 0.9f,
			.texture = &TEX_FABRIC,
			.tint = {11,11,11,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Cube.024
			.points = {{-31.0f,10.5f},{-31.0f,30.0f},{-69.0f,30.0f},{-69.0f,10.5f}},
			.z = -1.1f,
			.height = 0.9f,
			.texture = &TEX_FABRIC,
			.tint = {11,11,11,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Cube.025
			.points = {{-31.0f,9.5f},{-31.0f,10.5f},{-69.0f,10.5f},{-69.0f,9.5f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.026
			.points = {{-23.5f,14.0f},{-23.5f,30.0f},{-24.5f,30.0f},{-24.5f,14.0f}},
			.z = -0.0f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.027
			.points = {{-23.5f,-10.0f},{-23.5f,6.0f},{-24.5f,6.0f},{-24.5f,-10.0f}},
			.z = -0.0f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.030
			.points = {{10.0f,30.0f},{10.0f,32.0f},{-30.0f,32.0f},{-30.0f,30.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,99,10,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.031
			.points = {{-30.0f,-12.0f},{-30.0f,-10.0f},{-70.0f,-10.0f},{-70.0f,-12.0f}},
			.z = 9.0f,
			.height = 1.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.032
			.points = {{-69.0f,-12.0f},{-69.0f,-10.0f},{-70.0f,-10.0f},{-70.0f,-12.0f}},
			.z = -2.0f,
			.height = 11.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.033
			.points = {{-30.0f,-12.0f},{-30.0f,-10.0f},{-31.0f,-10.0f},{-31.0f,-12.0f}},
			.z = -2.0f,
			.height = 11.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.034
			.points = {{-31.0f,-12.0f},{-31.0f,-10.2f},{-69.0f,-10.2f},{-69.0f,-12.0f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_FABRIC,
			.tint = {11,11,11,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Cube.035
			.points = {{2.25f,10.0f},{2.25f,10.7f},{1.1f,10.7f},{1.1f,10.0f}},
			.z = 2.5f,
			.height = 0.1f,
			.texture = &TEX_BRICK,
			.tint = {76,76,76,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.036
			.points = {{-30.0f,30.0f},{-30.0f,32.0f},{-31.0f,32.0f},{-31.0f,30.0f}},
			.z = -2.0f,
			.height = 11.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.037
			.points = {{-69.0f,30.0f},{-69.0f,32.0f},{-70.0f,32.0f},{-70.0f,30.0f}},
			.z = -2.0f,
			.height = 11.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.038
			.points = {{-30.0f,30.0f},{-30.0f,32.0f},{-70.0f,32.0f},{-70.0f,30.0f}},
			.z = 9.0f,
			.height = 1.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.039
			.points = {{-31.0f,30.0f},{-31.0f,32.0f},{-69.0f,32.0f},{-69.0f,30.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.040
			.points = {{-23.5f,-10.0f},{-23.5f,6.0f},{-24.5f,6.0f},{-24.5f,-10.0f}},
			.z = 9.5f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.041
			.points = {{-23.5f,14.0f},{-23.5f,30.0f},{-24.5f,30.0f},{-24.5f,14.0f}},
			.z = 9.5f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.042
			.points = {{-23.5f,13.5f},{-23.5f,14.0f},{-24.5f,14.0f},{-24.5f,13.5f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.043
			.points = {{-23.5f,6.0f},{-23.5f,6.5f},{-24.5f,6.5f},{-24.5f,6.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_PLASTIC,
			.tint = {51,51,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.044
			.points = {{10.0f,-0.2f},{10.0f,1.8f},{8.0f,1.8f},{8.0f,-0.2f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.045
			.points = {{10.0f,-0.2f},{10.0f,1.8f},{8.0f,1.8f},{8.0f,-0.2f}},
			.z = 4.0f,
			.height = 0.4f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.046
			.points = {{10.0f,-0.2f},{10.0f,1.8f},{8.4f,1.8f},{8.4f,-0.2f}},
			.z = 2.0f,
			.height = 2.0f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.047
			.points = {{9.9f,-0.1f},{9.9f,1.7f},{8.3f,1.7f},{8.3f,-0.1f}},
			.z = 2.55f,
			.height = 1.35f,
			.texture = &TEX_FABRIC,
			.tint = {0,12,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.048
			.points = {{8.4f,-0.2f},{8.4f,0.6f},{8.16f,0.6f},{8.16f,-0.2f}},
			.z = 2.0f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.049
			.points = {{8.18f,1.25f},{8.18f,1.65f},{8.14f,1.65f},{8.14f,1.25f}},
			.z = 2.175f,
			.height = 0.15f,
			.texture = &TEX_PLASTIC,
			.tint = {0,17,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.050
			.points = {{8.4f,1.0f},{8.4f,1.8f},{8.16f,1.8f},{8.16f,1.0f}},
			.z = 2.0f,
			.height = 0.5f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.051
			.points = {{8.4f,0.6f},{8.4f,1.0f},{8.16f,1.0f},{8.16f,0.6f}},
			.z = 2.4f,
			.height = 0.1f,
			.texture = &TEX_PLASTIC,
			.tint = {17,17,17,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.052
			.points = {{8.33f,0.6f},{8.33f,1.0f},{8.23f,1.0f},{8.23f,0.6f}},
			.z = 2.0f,
			.height = 0.24f,
			.texture = &TEX_BRICK,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.053
			.points = {{8.17f,1.29f},{8.17f,1.61f},{8.13f,1.61f},{8.13f,1.29f}},
			.z = 2.225f,
			.height = 0.05f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.054
			.points = {{-69.15f,-10.0f},{-69.15f,30.0f},{-69.85f,30.0f},{-69.85f,-10.0f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_FABRIC,
			.tint = {11,11,11,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Cube.055
			.points = {{-69.0f,-10.0f},{-69.0f,30.0f},{-70.0f,30.0f},{-70.0f,-10.0f}},
			.z = 9.0f,
			.height = 1.0f,
			.texture = &TEX_PLASTIC,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // door
			.points = {{1.3f,-10.8f},{1.3f,-9.8f},{-1.3f,-9.8f},{-1.3f,-10.8f}},
			.z = 0.0f,
			.height = 5.6f,
			.texture = &TEX_PLASTER,
			.tint = {14,8,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // knob
			.points = {{-0.65f,-9.8f},{-0.65f,-9.6f},{-0.85f,-9.6f},{-0.85f,-9.8f}},
			.z = 2.4f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {55,54,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // poles
			.points = {{-13.8f,-9.2f},{-13.8f,-8.8f},{-14.2f,-8.8f},{-14.2f,-9.2f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_CARDBOARD,
			.tint = {94,94,94,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // poles
			.points = {{-13.8f,-5.2f},{-13.8f,-4.8f},{-14.2f,-4.8f},{-14.2f,-5.2f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_CARDBOARD,
			.tint = {94,94,94,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // poles
			.points = {{-13.8f,-1.2f},{-13.8f,-0.8f},{-14.2f,-0.8f},{-14.2f,-1.2f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_CARDBOARD,
			.tint = {94,94,94,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // poles
			.points = {{-13.8f,2.8f},{-13.8f,3.2f},{-14.2f,3.2f},{-14.2f,2.8f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_CARDBOARD,
			.tint = {94,94,94,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // poles
			.points = {{-13.8f,6.8f},{-13.8f,7.2f},{-14.2f,7.2f},{-14.2f,6.8f}},
			.z = 0.0f,
			.height = 2.0f,
			.texture = &TEX_CARDBOARD,
			.tint = {94,94,94,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.028
			.points = {{-23.75f,-10.0f},{-23.75f,6.0f},{-24.25f,6.0f},{-24.25f,-10.0f}},
			.z = 0.5f,
			.height = 9.0f,
			.texture = &TEX_NOISE_1,
			.tint = {139,228,255,25},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.029
			.points = {{-23.75f,14.0f},{-23.75f,30.0f},{-24.25f,30.0f},{-24.25f,14.0f}},
			.z = 0.5f,
			.height = 9.0f,
			.texture = &TEX_NOISE_1,
			.tint = {139,228,255,25},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
	},
};