static GameMap testmap = {
	{ // Sky Color
		12,12,12,255,
	},
	{ // Walls
		{ // bounce
			.points = {{-9.0f,-1.0f},{-9.0f,1.0f},{-11.0f,1.0f},{-11.0f,-1.0f}},
			.z = -1.0f,
			.height = 2.0f,
			.texture = &TEX_FABRIC,
			.tint = {0,255,0,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // concretewall.005
			.points = {{6.0f,8.0f},{6.0f,18.0f},{-6.0f,18.0f},{-6.0f,8.0f}},
			.z = 4.0f,
			.height = 6.0f,
			.texture = &TEX_BRICK,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // concretewall.007
			.points = {{6.0f,-52.0f},{6.0f,-42.0f},{-6.0f,-42.0f},{-6.0f,-52.0f}},
			.z = -14.0f,
			.height = 12.0f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // concretewall.008
			.points = {{6.0f,-18.0f},{6.0f,-8.0f},{-6.0f,-8.0f},{-6.0f,-18.0f}},
			.z = -14.0f,
			.height = 12.0f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // concretewall.014
			.points = {{-6.0f,8.0f},{-6.0f,18.0f},{-18.0f,18.0f},{-18.0f,8.0f}},
			.z = 8.0f,
			.height = 2.0f,
			.texture = &TEX_BRICK,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // concretewall.024
			.points = {{-20.0f,8.0f},{-20.0f,18.0f},{-32.0f,18.0f},{-32.0f,8.0f}},
			.z = 8.0f,
			.height = 2.0f,
			.texture = &TEX_BRICK,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // crate_c
			.points = {{0.25f,-42.0f},{0.25f,-18.0f},{-0.25f,-18.0f},{-0.25f,-42.0f}},
			.z = -0.5f,
			.height = 0.5f,
			.texture = &TEX_FABRIC,
			.tint = {120,120,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // crate_c.033
			.points = {{-1.01f,-42.0f},{-1.01f,-18.0f},{-1.51f,-18.0f},{-1.51f,-42.0f}},
			.z = -0.5f,
			.height = 0.5f,
			.texture = &TEX_FABRIC,
			.tint = {120,120,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // crate_c.034
			.points = {{-2.53f,-42.0f},{-2.53f,-18.0f},{-3.03f,-18.0f},{-3.03f,-42.0f}},
			.z = -0.5f,
			.height = 0.5f,
			.texture = &TEX_FABRIC,
			.tint = {120,120,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // crate_c.035
			.points = {{1.91f,-42.0f},{1.91f,-18.0f},{1.41f,-18.0f},{1.41f,-42.0f}},
			.z = -0.5f,
			.height = 0.5f,
			.texture = &TEX_FABRIC,
			.tint = {120,120,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // crate_c.036
			.points = {{3.54f,-42.0f},{3.54f,-18.0f},{3.04f,-18.0f},{3.04f,-42.0f}},
			.z = -0.5f,
			.height = 0.5f,
			.texture = &TEX_FABRIC,
			.tint = {120,120,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // ladder
			.points = {{-4.0f,-18.5f},{-4.0f,-18.0f},{-6.0f,-18.0f},{-6.0f,-18.5f}},
			.z = -12.0f,
			.height = 12.0f,
			.texture = &TEX_WOOD,
			.tint = {173,119,64,255},
			.surfaceMaterial = SURFACE_LADDER,
		},

		{ // scifi_floortile
			.points = {{6.0f,16.0f},{6.0f,18.0f},{4.0f,18.0f},{4.7f,16.7f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.013
			.points = {{-16.7f,16.7f},{-16.0f,18.0f},{-18.0f,18.0f},{-18.0f,16.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.014
			.points = {{-4.7f,-7.3f},{-4.0f,-6.0f},{-6.0f,-6.0f},{-6.0f,-8.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.014
			.points = {{-4.0f,-6.0f},{-4.7f,-4.7f},{-6.0f,-4.0f},{-6.0f,-6.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.014
			.points = {{-6.0f,-6.0f},{-6.0f,-4.0f},{-7.3f,-4.7f},{-8.0f,-6.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.015
			.points = {{-4.0f,-42.0f},{-4.7f,-40.7f},{-6.0f,-40.0f},{-6.0f,-42.0f}},
			.z = -12.0f,
			.height = 22.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.020
			.points = {{-6.0f,-44.0f},{-6.0f,-42.0f},{-8.0f,-42.0f},{-7.3f,-43.3f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.020
			.points = {{-4.7f,-43.3f},{-4.0f,-42.0f},{-6.0f,-42.0f},{-6.0f,-44.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.021
			.points = {{-28.7f,-43.3f},{-28.0f,-42.0f},{-30.0f,-42.0f},{-30.0f,-44.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.022
			.points = {{-28.0f,-54.0f},{-28.7f,-52.7f},{-30.0f,-52.0f},{-30.0f,-54.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.023
			.points = {{6.0f,-54.0f},{6.0f,-52.0f},{4.7f,-52.7f},{4.0f,-54.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.024
			.points = {{-20.0f,16.0f},{-20.0f,18.0f},{-22.0f,18.0f},{-21.3f,16.7f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.025
			.points = {{-30.7f,16.7f},{-30.0f,18.0f},{-32.0f,18.0f},{-32.0f,16.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // scifi_floortile.026
			.points = {{-30.0f,-6.0f},{-30.7f,-4.7f},{-32.0f,-4.0f},{-32.0f,-6.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.tint = {32,32,32,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.001
			.points = {{6.0f,18.0f},{6.0f,20.0f},{-6.0f,20.0f},{-6.0f,18.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.003
			.points = {{8.0f,-6.0f},{8.0f,6.0f},{6.0f,6.0f},{6.0f,-6.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.004
			.points = {{-6.0f,6.0f},{-6.0f,8.0f},{-18.0f,8.0f},{-18.0f,6.0f}},
			.z = 2.5f,
			.height = 7.5f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.005
			.points = {{-18.0f,6.0f},{-18.0f,18.0f},{-20.0f,18.0f},{-20.0f,6.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.006
			.points = {{8.0f,6.0f},{8.0f,18.0f},{6.0f,18.0f},{6.0f,6.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.007
			.points = {{-6.0f,18.0f},{-6.0f,20.0f},{-18.0f,20.0f},{-18.0f,18.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.008
			.points = {{-6.0f,-8.0f},{-6.0f,-6.0f},{-18.0f,-6.0f},{-18.0f,-8.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.009
			.points = {{8.0f,-18.0f},{8.0f,-6.0f},{6.0f,-6.0f},{6.0f,-18.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.010
			.points = {{-20.0f,6.0f},{-20.0f,8.0f},{-32.0f,8.0f},{-32.0f,6.0f}},
			.z = 5.0f,
			.height = 5.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.011
			.points = {{-20.0f,18.0f},{-20.0f,20.0f},{-32.0f,20.0f},{-32.0f,18.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.012
			.points = {{-32.0f,6.0f},{-32.0f,18.0f},{-34.0f,18.0f},{-34.0f,6.0f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.013
			.points = {{-32.0f,-6.0f},{-32.0f,6.0f},{-34.0f,6.0f},{-34.0f,-6.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.014
			.points = {{-18.0f,-8.0f},{-18.0f,-6.0f},{-20.0f,-6.0f},{-20.0f,-8.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.015
			.points = {{-6.0f,-18.0f},{-6.0f,-8.0f},{-8.0f,-8.0f},{-8.0f,-18.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.016
			.points = {{8.0f,-42.0f},{8.0f,-18.0f},{6.0f,-18.0f},{6.0f,-42.0f}},
			.z = -14.0f,
			.height = 24.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.017
			.points = {{-6.0f,-42.0f},{-6.0f,-18.0f},{-8.0f,-18.0f},{-8.0f,-42.0f}},
			.z = -14.0f,
			.height = 24.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.018
			.points = {{8.0f,-54.0f},{8.0f,-42.0f},{6.0f,-42.0f},{6.0f,-54.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.019
			.points = {{-6.0f,-56.0f},{-6.0f,-54.0f},{-18.0f,-54.0f},{-18.0f,-56.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.020
			.points = {{6.0f,-56.0f},{6.0f,-54.0f},{-6.0f,-54.0f},{-6.0f,-56.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.021
			.points = {{-18.0f,-56.0f},{-18.0f,-54.0f},{-30.0f,-54.0f},{-30.0f,-56.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.022
			.points = {{-18.0f,-42.0f},{-18.0f,-40.0f},{-30.0f,-40.0f},{-30.0f,-42.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.023
			.points = {{-8.0f,-42.0f},{-8.0f,-40.0f},{-18.0f,-40.0f},{-18.0f,-42.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.024
			.points = {{-30.0f,-54.0f},{-30.0f,-42.0f},{-32.0f,-42.0f},{-32.0f,-54.0f}},
			.z = -0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // stone.029
			.points = {{-20.0f,-8.0f},{-20.0f,-6.0f},{-32.0f,-6.0f},{-32.0f,-8.0f}},
			.z = 0.0f,
			.height = 10.0f,
			.texture = &TEX_BRICK,
			.tint = {60,60,60,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.001
			.points = {{-6.0f,-6.0f},{-6.0f,6.0f},{-18.0f,6.0f},{-18.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.002
			.points = {{-6.0f,6.0f},{-6.0f,18.0f},{-18.0f,18.0f},{-18.0f,6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.003
			.points = {{-18.0f,-6.0f},{-18.0f,6.0f},{-20.0f,6.0f},{-20.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.004
			.points = {{-20.0f,-6.0f},{-20.0f,6.0f},{-32.0f,6.0f},{-32.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.005
			.points = {{-20.0f,6.0f},{-20.0f,18.0f},{-32.0f,18.0f},{-32.0f,6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.006
			.points = {{6.0f,6.0f},{6.0f,18.0f},{-6.0f,18.0f},{-6.0f,6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{-0.0f,-6.0f},{-0.0f,6.0f},{-2.0f,6.0f},{-2.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{6.0f,-6.0f},{6.0f,6.0f},{4.0f,6.0f},{4.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{4.0f,-6.0f},{4.0f,6.0f},{2.0f,6.0f},{2.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{2.0f,-6.0f},{2.0f,6.0f},{-0.0f,6.0f},{-0.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{-2.0f,-6.0f},{-2.0f,6.0f},{-4.0f,6.0f},{-4.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.009
			.points = {{-4.0f,-6.0f},{-4.0f,6.0f},{-6.0f,6.0f},{-6.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.012
			.points = {{6.0f,-18.0f},{6.0f,-6.0f},{-6.0f,-6.0f},{-6.0f,-18.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.013
			.points = {{6.0f,-30.0f},{6.0f,-18.0f},{-6.0f,-18.0f},{-6.0f,-30.0f}},
			.z = -14.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.014
			.points = {{6.0f,-42.0f},{6.0f,-30.0f},{-6.0f,-30.0f},{-6.0f,-42.0f}},
			.z = -14.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.015
			.points = {{6.0f,-54.0f},{6.0f,-42.0f},{-6.0f,-42.0f},{-6.0f,-54.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.016
			.points = {{-6.0f,-54.0f},{-6.0f,-42.0f},{-18.0f,-42.0f},{-18.0f,-54.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.017
			.points = {{-18.0f,-54.0f},{-18.0f,-42.0f},{-30.0f,-42.0f},{-30.0f,-54.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {180,180,180,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.019
			.points = {{6.0f,-54.0f},{6.0f,-42.0f},{-30.0f,-42.0f},{-30.0f,-54.0f}},
			.z = 10.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {113,113,113,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.025
			.points = {{6.0f,-42.0f},{6.0f,-6.0f},{-6.0f,-6.0f},{-6.0f,-42.0f}},
			.z = 10.0f,
			.height = 2.0f,
			.texture = &TEX_STONE,
			.tint = {113,113,113,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // woodfloor.027
			.points = {{6.0f,-6.0f},{6.0f,8.0f},{-32.0f,8.0f},{-32.0f,-6.0f}},
			.z = 10.0f,
			.height = 2.0f,
			.texture = &TEX_METAL,
			.tint = {113,113,113,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
	{ // Things
	},
};