static GameMap MAP_EXAMPLE = {
	{ // Sky Color
		102,191,255,255,
	},
	{ // Walls
		{ // Cube
			.points = {{58.93f,-107.38f},{58.93f,-107.18f},{57.33f,-107.18f},{57.33f,-107.38f}},
			.z = 0.201f,
			.height = 1.3f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{59.13f,-107.38f},{59.13f,-103.38f},{57.13f,-103.38f},{57.13f,-107.38f}},
			.z = -0.0f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.ignoreCollisions = true,
		},

		{ // Cube.002
			.points = {{-31.44f,-59.11f},{-32.09f,-58.34f},{-32.85f,-58.98f},{-32.21f,-59.75f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.003
			.points = {{-23.78f,-52.68f},{-24.43f,-51.91f},{-25.19f,-52.55f},{-24.55f,-53.32f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.004
			.points = {{-30.21f,-45.02f},{-30.86f,-44.25f},{-31.62f,-44.89f},{-30.98f,-45.66f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.005
			.points = {{-37.87f,-51.45f},{-38.52f,-50.68f},{-39.28f,-51.32f},{-38.64f,-52.09f}},
			.z = 0.0f,
			.height = 6.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.006
			.points = {{-32.4f,-60.23f},{-32.09f,-59.97f},{-39.48f,-51.16f},{-39.79f,-51.42f}},
			.z = 6.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.007
			.points = {{-23.3f,-52.86f},{-23.56f,-52.56f},{-32.37f,-59.95f},{-32.11f,-60.25f}},
			.z = 6.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.008
			.points = {{-30.7f,-44.05f},{-30.95f,-43.75f},{-39.76f,-51.14f},{-39.51f,-51.44f}},
			.z = 6.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.009
			.points = {{-23.59f,-52.84f},{-23.28f,-52.58f},{-30.67f,-43.77f},{-30.98f,-44.03f}},
			.z = 6.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.010
			.points = {{-23.59f,-52.84f},{-23.28f,-52.58f},{-25.21f,-50.28f},{-25.51f,-50.54f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.011
			.points = {{-30.7f,-44.05f},{-30.95f,-43.75f},{-33.25f,-45.67f},{-32.99f,-45.98f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.012
			.points = {{-29.82f,-58.33f},{-30.07f,-58.02f},{-32.37f,-59.95f},{-32.11f,-60.25f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.013
			.points = {{-37.86f,-53.72f},{-37.55f,-53.46f},{-39.48f,-51.16f},{-39.79f,-51.42f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.014
			.points = {{-32.4f,-60.23f},{-32.09f,-59.97f},{-34.02f,-57.67f},{-34.32f,-57.93f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.015
			.points = {{-23.3f,-52.86f},{-23.56f,-52.56f},{-25.86f,-54.48f},{-25.6f,-54.79f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.016
			.points = {{-37.21f,-49.52f},{-37.46f,-49.21f},{-39.76f,-51.14f},{-39.51f,-51.44f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.017
			.points = {{-29.05f,-46.33f},{-28.74f,-46.07f},{-30.67f,-43.77f},{-30.98f,-44.03f}},
			.z = 8.25f,
			.height = 4.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.018
			.points = {{-23.59f,-52.84f},{-23.28f,-52.58f},{-30.67f,-43.77f},{-30.98f,-44.03f}},
			.z = 12.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.019
			.points = {{-30.7f,-44.05f},{-30.95f,-43.75f},{-39.76f,-51.14f},{-39.51f,-51.44f}},
			.z = 12.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.020
			.points = {{-23.3f,-52.86f},{-23.56f,-52.56f},{-32.37f,-59.95f},{-32.11f,-60.25f}},
			.z = 12.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.021
			.points = {{-32.4f,-60.23f},{-32.09f,-59.97f},{-39.48f,-51.16f},{-39.79f,-51.42f}},
			.z = 12.25f,
			.height = 2.0f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.022
			.points = {{-23.08f,-52.74f},{-30.79f,-43.55f},{-39.99f,-51.26f},{-32.27f,-60.45f}},
			.z = 14.25f,
			.height = 0.5f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.023
			.points = {{58.93f,-103.58f},{58.93f,-103.38f},{57.33f,-103.38f},{57.33f,-103.58f}},
			.z = 0.201f,
			.height = 1.3f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.024
			.points = {{57.31f,-107.18f},{57.31f,-103.58f},{57.13f,-103.58f},{57.13f,-107.18f}},
			.z = 0.201f,
			.height = 1.3f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.025
			.points = {{59.13f,-107.18f},{59.13f,-103.58f},{58.93f,-103.58f},{58.93f,-107.18f}},
			.z = 0.205f,
			.height = 1.3f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.026
			.points = {{58.93f,-107.18f},{58.93f,-103.58f},{57.33f,-103.58f},{57.33f,-107.18f}},
			.z = 0.201f,
			.height = 0.7f,
			.texture = &TEX_GRAVEL,
			.tint = {255,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.027
			.points = {{60.13f,-107.18f},{60.13f,-103.58f},{59.33f,-103.58f},{59.33f,-107.18f}},
			.z = 1.74f,
			.height = 0.16f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.028
			.points = {{-37.32f,4.52f},{-37.32f,4.68f},{-37.48f,4.68f},{-37.48f,4.52f}},
			.z = 0.0f,
			.height = 1.0f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.029
			.points = {{64.35f,34.08f},{64.26f,34.36f},{54.27f,31.12f},{54.36f,30.83f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.030
			.points = {{67.62f,24.0f},{67.53f,24.28f},{57.55f,21.04f},{57.64f,20.75f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.031
			.points = {{57.39f,20.88f},{57.67f,20.97f},{56.59f,24.3f},{56.31f,24.21f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.032
			.points = {{67.47f,24.16f},{67.75f,24.25f},{64.51f,34.23f},{64.22f,34.14f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.033
			.points = {{55.22f,27.54f},{55.51f,27.63f},{54.43f,30.96f},{54.14f,30.87f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.034
			.points = {{56.31f,24.21f},{56.59f,24.3f},{55.51f,27.63f},{55.22f,27.54f}},
			.z = 6.4f,
			.height = 1.6f,
			.texture = &TEX_WOOD,
			.tint = {255,242,51,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.035
			.points = {{56.59f,24.3f},{56.88f,24.39f},{55.79f,27.72f},{55.51f,27.63f}},
			.z = 6.4f,
			.height = 1.6f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.036
			.points = {{55.51f,27.63f},{55.79f,27.72f},{54.71f,31.05f},{54.43f,30.96f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.037
			.points = {{67.18f,24.06f},{67.47f,24.16f},{64.22f,34.14f},{63.94f,34.05f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.038
			.points = {{57.67f,20.97f},{57.96f,21.07f},{56.88f,24.39f},{56.59f,24.3f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.039
			.points = {{67.53f,24.28f},{67.44f,24.57f},{57.45f,21.32f},{57.55f,21.04f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.040
			.points = {{64.44f,33.79f},{64.35f,34.08f},{54.36f,30.83f},{54.46f,30.55f}},
			.z = 0.0f,
			.height = 8.0f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.042
			.points = {{-42.52f,4.52f},{-42.52f,4.68f},{-42.68f,4.68f},{-42.68f,4.52f}},
			.z = 0.0f,
			.height = 1.0f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.043
			.points = {{-42.52f,-0.68f},{-42.52f,-0.52f},{-42.68f,-0.52f},{-42.68f,-0.68f}},
			.z = 0.0f,
			.height = 1.0f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.044
			.points = {{-37.32f,-0.68f},{-37.32f,-0.52f},{-37.48f,-0.52f},{-37.48f,-0.68f}},
			.z = 0.0f,
			.height = 1.0f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.045
			.points = {{-39.0f,-5.15f},{-39.0f,-4.85f},{-41.0f,-4.85f},{-41.0f,-5.15f}},
			.z = -0.2f,
			.height = 20.2f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_LADDER,
		},

		{ // Cube.046
			.points = {{-41.35f,-4.85f},{-41.35f,-4.55f},{-41.65f,-4.55f},{-41.65f,-4.85f}},
			.z = 0.0f,
			.height = 20.0f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.047
			.points = {{-38.35f,-4.85f},{-38.35f,-4.55f},{-38.65f,-4.55f},{-38.65f,-4.85f}},
			.z = 0.0f,
			.height = 20.0f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.048
			.points = {{-39.0f,-4.85f},{-39.0f,-1.25f},{-41.0f,-1.25f},{-41.0f,-4.85f}},
			.z = 19.7f,
			.height = 0.3f,
			.texture = &TEX_PLASTER,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.049
			.points = {{-41.0f,-4.85f},{-41.0f,-4.55f},{-41.35f,-4.55f},{-41.35f,-4.85f}},
			.z = 19.7f,
			.height = 0.3f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.050
			.points = {{-38.65f,-4.85f},{-38.65f,-4.55f},{-39.0f,-4.55f},{-39.0f,-4.85f}},
			.z = 19.7f,
			.height = 0.3f,
			.texture = &TEX_METAL,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.051
			.points = {{-28.62f,-53.91f},{-29.91f,-52.38f},{-31.44f,-53.67f},{-30.15f,-55.2f}},
			.z = 6.0f,
			.height = 0.4f,
			.tint = {255,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.052
			.points = {{-39.1f,-3.45f},{-39.1f,-1.65f},{-40.9f,-1.65f},{-40.9f,-3.45f}},
			.z = 19.75f,
			.height = 0.4f,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.canSpawn = true,
		},

		{ // Cube.053
			.points = {{60.13f,-103.58f},{60.13f,-103.38f},{59.33f,-103.38f},{59.33f,-103.58f}},
			.z = 1.9f,
			.height = 1.6f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.054
			.points = {{60.13f,-107.38f},{60.13f,-107.18f},{59.33f,-107.18f},{59.33f,-107.38f}},
			.z = 1.9f,
			.height = 1.6f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.055
			.points = {{60.13f,-107.18f},{60.13f,-103.58f},{59.33f,-103.58f},{59.33f,-107.18f}},
			.z = 3.5f,
			.height = 0.2f,
			.texture = &TEX_WOOD,
			.tint = {34,16,2,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.056
			.points = {{60.33f,-107.38f},{60.33f,-103.38f},{60.13f,-103.38f},{60.13f,-107.38f}},
			.z = 1.7f,
			.height = 2.0f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.057
			.points = {{60.13f,-107.38f},{60.13f,-107.18f},{59.13f,-107.18f},{59.13f,-107.38f}},
			.z = 1.7f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.058
			.points = {{60.13f,-107.38f},{60.13f,-107.18f},{59.13f,-107.18f},{59.13f,-107.38f}},
			.z = 3.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.059
			.points = {{60.13f,-103.58f},{60.13f,-103.38f},{59.13f,-103.38f},{59.13f,-103.58f}},
			.z = 3.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.060
			.points = {{60.13f,-103.58f},{60.13f,-103.38f},{59.13f,-103.38f},{59.13f,-103.58f}},
			.z = 1.7f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.061
			.points = {{59.13f,-103.58f},{59.13f,-103.38f},{58.93f,-103.38f},{58.93f,-103.58f}},
			.z = 0.2f,
			.height = 1.5f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.062
			.points = {{57.33f,-103.58f},{57.33f,-103.38f},{57.13f,-103.38f},{57.13f,-103.58f}},
			.z = 0.2f,
			.height = 1.5f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.063
			.points = {{57.33f,-107.38f},{57.33f,-107.18f},{57.13f,-107.18f},{57.13f,-107.38f}},
			.z = 0.2f,
			.height = 1.5f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.064
			.points = {{59.13f,-107.38f},{59.13f,-107.18f},{58.93f,-107.18f},{58.93f,-107.38f}},
			.z = 0.2f,
			.height = 1.5f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.065
			.points = {{59.33f,-107.18f},{59.33f,-103.58f},{59.13f,-103.58f},{59.13f,-107.18f}},
			.z = 3.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.066
			.points = {{59.33f,-107.18f},{59.33f,-103.58f},{59.13f,-103.58f},{59.13f,-107.18f}},
			.z = 1.7f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.067
			.points = {{59.33f,-107.38f},{59.33f,-107.18f},{59.13f,-107.18f},{59.13f,-107.38f}},
			.z = 1.9f,
			.height = 1.6f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.068
			.points = {{59.33f,-103.58f},{59.33f,-103.38f},{59.13f,-103.38f},{59.13f,-103.58f}},
			.z = 1.9f,
			.height = 1.6f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.069
			.points = {{59.13f,-107.18f},{59.13f,-103.58f},{58.93f,-103.58f},{58.93f,-107.18f}},
			.z = 1.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.070
			.points = {{57.33f,-107.18f},{57.33f,-103.58f},{57.13f,-103.58f},{57.13f,-107.18f}},
			.z = 1.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.071
			.points = {{58.93f,-107.38f},{58.93f,-107.18f},{57.33f,-107.18f},{57.33f,-107.38f}},
			.z = 1.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.072
			.points = {{58.93f,-103.58f},{58.93f,-103.38f},{57.33f,-103.38f},{57.33f,-103.58f}},
			.z = 1.5f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.073
			.points = {{59.63f,-105.53f},{59.63f,-105.23f},{59.03f,-105.23f},{59.03f,-105.53f}},
			.z = 3.7f,
			.height = 0.2f,
			.texture = &TEX_NOISE_1,
			.tint = {15,15,15,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // door
			.points = {{56.42f,24.25f},{56.48f,24.26f},{55.39f,27.59f},{55.34f,27.57f}},
			.z = 0.0f,
			.height = 6.4f,
			.texture = &TEX_WOOD,
			.tint = {255,62,24,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.tickFunction = [](Wall* self) {
				const static float zInit = self->z;
				const static float heightInit = self->height;
				static float time = 0.0f;
				static bool opening = true;
				if (self->interact) {
				    if (self->z < zInit + heightInit && opening) {
				        self->z += 0.1f;
				        self->height -= 0.1f;
				    }
				    else if (time < 1.0f) {
				        self->z = zInit + heightInit;
				        self->height = 0.0f;
				        opening = false;
				        time += GetFrameTime();
				    }
				    else if (self->z > zInit) {
				        self->z -= 0.1f;
				        self->height += 0.1f;
				    }
				    else {
				        self->z = zInit;
				        self->height = heightInit;
				        self->interact = false;
				        opening = true;
				        time = 0.0f;
				    }
				}
			},
		},

		{ // floor
			.points = {{67.25f,24.35f},{64.16f,33.86f},{54.27f,30.64f},{57.36f,21.13f}},
			.z = -0.1f,
			.height = 0.2f,
			.texture = &TEX_WOOD_FLOOR,
			.tint = {255,122,43,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Grass
			.points = {{84.0f,-134.0f},{84.0f,116.0f},{-116.0f,116.0f},{-116.0f,-134.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &TEX_GRASS,
			.tint = {2,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{5.0f,-5.0f},{5.0f,5.0f},{-5.26f,4.99f},{-4.74f,-4.99f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-4.74f,-4.99f},{-5.26f,4.99f},{-21.81f,2.66f},{-16.12f,-5.56f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-17.48f,-9.04f},{-16.12f,-5.56f},{-21.81f,2.66f},{-27.45f,-8.24f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-15.54f,-14.42f},{-17.48f,-9.04f},{-27.45f,-8.24f},{-24.19f,-19.44f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-10.06f,-20.65f},{-15.54f,-14.42f},{-24.19f,-19.44f},{-19.35f,-24.35f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-9.79f,-28.96f},{-10.06f,-20.65f},{-19.35f,-24.35f},{-19.45f,-31.56f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-5.5f,-36.66f},{-9.79f,-28.96f},{-19.45f,-31.56f},{-12.44f,-43.86f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-3.02f,-48.91f},{2.72f,-40.72f},{-5.5f,-36.66f},{-12.44f,-43.86f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{12.53f,-62.5f},{10.84f,-48.58f},{1.93f,-53.13f},{2.76f,-60.35f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{10.84f,-48.58f},{2.72f,-40.72f},{-3.02f,-48.91f},{1.93f,-53.13f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{6.92f,-71.72f},{12.53f,-62.5f},{2.76f,-60.35f},{-2.02f,-61.4f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{6.92f,-71.72f},{-2.02f,-61.4f},{-9.59f,-72.48f},{-5.49f,-77.33f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-9.59f,-72.48f},{-2.02f,-61.4f},{-16.24f,-60.31f},{-22.2f,-72.32f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-5.49f,-77.33f},{-9.59f,-72.48f},{-18.11f,-79.78f},{-13.91f,-88.86f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-13.91f,-88.86f},{-18.11f,-79.78f},{-26.65f,-78.11f},{-28.01f,-88.02f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-28.01f,-88.02f},{-26.65f,-78.11f},{-52.81f,-74.17f},{-57.7f,-82.9f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-57.7f,-82.9f},{-52.81f,-74.17f},{-58.23f,-68.16f},{-67.88f,-70.79f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-58.23f,-68.16f},{-55.7f,-56.9f},{-65.38f,-54.37f},{-67.88f,-70.79f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-55.7f,-56.9f},{-53.04f,-48.72f},{-63.01f,-47.96f},{-65.38f,-54.37f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-53.04f,-48.72f},{-55.11f,-37.72f},{-63.96f,-42.36f},{-63.01f,-47.96f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-60.27f,-32.45f},{-64.14f,-20.31f},{-74.05f,-19.0f},{-68.87f,-37.56f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-55.11f,-37.72f},{-60.27f,-32.45f},{-68.87f,-37.56f},{-63.96f,-42.36f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-64.14f,-20.31f},{-62.46f,-18.3f},{-70.19f,-11.95f},{-74.05f,-19.0f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-62.46f,-18.3f},{-55.66f,-11.75f},{-64.42f,-6.93f},{-70.19f,-11.95f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-55.66f,-11.75f},{-53.08f,2.44f},{-62.97f,1.02f},{-64.42f,-6.93f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-53.08f,2.44f},{-58.29f,13.4f},{-66.82f,8.18f},{-62.97f,1.02f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-58.29f,13.4f},{-61.88f,17.27f},{-71.78f,15.88f},{-66.82f,8.18f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-61.88f,17.27f},{-57.74f,27.91f},{-64.86f,34.93f},{-71.78f,15.88f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-46.71f,31.81f},{-48.71f,41.6f},{-64.86f,34.93f},{-57.74f,27.91f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-33.08f,32.52f},{-29.63f,41.9f},{-48.71f,41.6f},{-46.71f,31.81f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-27.15f,27.55f},{-24.99f,37.31f},{-29.63f,41.9f},{-33.08f,32.52f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{7.04f,39.84f},{5.23f,49.67f},{-14.72f,41.14f},{-11.25f,31.76f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-11.25f,31.76f},{-14.72f,41.14f},{-24.99f,37.31f},{-27.15f,27.55f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{31.46f,38.76f},{34.66f,48.24f},{5.23f,49.67f},{7.04f,39.84f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{37.05f,34.71f},{43.65f,42.22f},{34.66f,48.24f},{31.46f,38.76f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{51.56f,33.27f},{43.65f,42.22f},{37.05f,34.71f},{42.73f,28.57f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{53.68f,25.37f},{51.56f,33.27f},{42.73f,28.57f},{44.14f,22.38f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{56.55f,17.71f},{53.68f,25.37f},{44.14f,22.38f},{46.81f,15.45f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{57.43f,8.48f},{56.55f,17.71f},{46.81f,15.45f},{47.43f,8.57f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-29.71f,-43.37f},{-33.66f,-42.97f},{-39.6f,-47.93f},{-39.92f,-51.89f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{-22.2f,-72.32f},{-16.24f,-60.31f},{-29.71f,-43.37f},{-39.92f,-51.89f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{54.96f,-7.37f},{57.43f,8.48f},{47.43f,8.57f},{47.01f,-1.3f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{54.96f,-7.37f},{47.01f,-1.3f},{36.57f,-4.72f},{39.31f,-14.34f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{39.31f,-14.34f},{36.57f,-4.72f},{23.99f,-7.65f},{20.47f,-17.01f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{20.47f,-17.01f},{23.99f,-7.65f},{18.84f,-0.09f},{11.03f,-6.34f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Gravel Path
			.points = {{11.03f,-6.34f},{18.84f,-0.09f},{5.0f,5.0f},{5.0f,-5.0f}},
			.z = -1.9f,
			.height = 2.0f,
			.texture = &TEX_GRAVEL,
			.tint = {178,178,178,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane
			.points = {{-26.09f,-55.38f},{-23.02f,-52.81f},{-30.74f,-43.61f},{-33.8f,-46.18f}},
			.z = 5.75f,
			.height = 0.5f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.001
			.points = {{-37.0f,-1.0f},{-37.0f,5.0f},{-43.0f,5.0f},{-43.0f,-1.0f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_FABRIC,
			.tint = {10,10,10,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Plane.001
			.points = {{-37.9f,-1.5f},{-37.0f,-1.0f},{-43.0f,-1.0f},{-42.1f,-1.5f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_FABRIC,
			.tint = {10,10,10,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Plane.001
			.points = {{-36.5f,-0.1f},{-36.5f,4.1f},{-37.0f,5.0f},{-37.0f,-1.0f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_FABRIC,
			.tint = {10,10,10,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Plane.001
			.points = {{-37.0f,5.0f},{-37.9f,5.5f},{-42.1f,5.5f},{-43.0f,5.0f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_FABRIC,
			.tint = {10,10,10,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Plane.001
			.points = {{-43.0f,-1.0f},{-43.0f,5.0f},{-43.5f,4.1f},{-43.5f,-0.1f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_FABRIC,
			.tint = {10,10,10,255},
			.surfaceMaterial = SURFACE_BOUNCY,
		},

		{ // Plane.002
			.points = {{-32.22f,-60.52f},{-29.15f,-57.95f},{-36.87f,-48.75f},{-39.93f,-51.33f}},
			.z = 5.75f,
			.height = 0.5f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.003
			.points = {{-33.41f,-46.65f},{-33.8f,-46.18f},{-36.87f,-48.75f},{-36.47f,-49.22f}},
			.z = 5.75f,
			.height = 0.5f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.004
			.points = {{-29.15f,-57.95f},{-26.09f,-55.38f},{-30.91f,-49.63f},{-33.97f,-52.2f}},
			.z = 5.75f,
			.height = 0.5f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-43.5f,-0.1f},{-43.5f,4.1f},{-43.98f,4.23f},{-43.98f,-0.23f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-42.23f,-1.98f},{-42.1f,-1.5f},{-43.0f,-1.0f},{-43.35f,-1.35f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-42.1f,5.5f},{-42.23f,5.98f},{-43.35f,5.35f},{-43.0f,5.0f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-37.77f,-1.98f},{-37.9f,-1.5f},{-42.1f,-1.5f},{-42.23f,-1.98f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-37.0f,5.0f},{-36.65f,5.35f},{-37.77f,5.98f},{-37.9f,5.5f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-37.9f,5.5f},{-37.77f,5.98f},{-42.23f,5.98f},{-42.1f,5.5f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-36.65f,-1.35f},{-37.0f,-1.0f},{-37.9f,-1.5f},{-37.77f,-1.98f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-43.0f,5.0f},{-43.35f,5.35f},{-43.98f,4.23f},{-43.5f,4.1f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-36.02f,-0.23f},{-36.02f,4.23f},{-36.5f,4.1f},{-36.5f,-0.1f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-43.35f,-1.35f},{-43.0f,-1.0f},{-43.5f,-0.1f},{-43.98f,-0.23f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-36.02f,-0.23f},{-36.5f,-0.1f},{-37.0f,-1.0f},{-36.65f,-1.35f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.005
			.points = {{-36.5f,4.1f},{-36.02f,4.23f},{-36.65f,5.35f},{-37.0f,5.0f}},
			.z = 1.0f,
			.height = 0.1f,
			.texture = &TEX_NOISE_1,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Plane.006
			.points = {{-33.01f,-47.13f},{-33.41f,-46.65f},{-36.47f,-49.22f},{-36.07f,-49.7f}},
			.z = 0.05f,
			.height = 6.2f,
			.texture = &TEX_WOOD,
			.tint = {105,30,11,255},
			.surfaceMaterial = SURFACE_LADDER,
		},

		{ // Rockwall
			.points = {{80.99f,-5.59f},{81.0f,6.0f},{69.0f,6.0f},{69.01f,-6.41f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{82.61f,-18.52f},{80.99f,-5.59f},{69.01f,-6.41f},{70.66f,-17.41f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{79.12f,-28.76f},{82.61f,-18.52f},{70.66f,-17.41f},{67.13f,-28.22f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{82.05f,-40.87f},{79.12f,-28.76f},{67.13f,-28.22f},{70.05f,-40.89f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{78.75f,-54.31f},{82.05f,-40.87f},{70.05f,-40.89f},{66.81f,-55.49f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{82.03f,-61.12f},{78.75f,-54.31f},{66.81f,-55.49f},{70.27f,-63.49f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{81.74f,-74.33f},{82.03f,-61.12f},{70.27f,-63.49f},{69.88f,-72.5f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{79.96f,-80.14f},{81.74f,-74.33f},{69.88f,-72.5f},{68.04f,-79.81f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{82.27f,-89.63f},{79.96f,-80.14f},{68.04f,-79.81f},{70.3f,-91.23f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{82.61f,-98.89f},{82.27f,-89.63f},{70.3f,-91.23f},{70.7f,-97.44f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{80.46f,-106.21f},{82.61f,-98.89f},{70.7f,-97.44f},{68.47f,-105.61f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{81.93f,-114.74f},{80.46f,-106.21f},{68.47f,-105.61f},{70.03f,-113.24f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{75.72f,-128.11f},{81.93f,-114.74f},{70.03f,-113.24f},{66.82f,-120.07f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{75.72f,-128.11f},{66.82f,-120.07f},{64.04f,-122.3f},{64.36f,-134.3f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{64.36f,-134.3f},{64.04f,-122.3f},{54.95f,-117.12f},{53.58f,-129.04f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{53.58f,-129.04f},{54.95f,-117.12f},{40.9f,-120.83f},{39.34f,-132.73f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{39.34f,-132.73f},{40.9f,-120.83f},{31.62f,-115.9f},{31.45f,-127.9f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{31.45f,-127.9f},{31.62f,-115.9f},{20.08f,-121.66f},{21.45f,-133.59f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{21.45f,-133.59f},{20.08f,-121.66f},{10.94f,-118.84f},{9.04f,-130.69f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{9.04f,-130.69f},{10.94f,-118.84f},{-3.36f,-118.34f},{0.1f,-129.84f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{0.1f,-129.84f},{-3.36f,-118.34f},{-11.48f,-124.42f},{-7.94f,-135.88f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-7.94f,-135.88f},{-11.48f,-124.42f},{-26.14f,-123.82f},{-30.98f,-134.8f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-26.14f,-123.82f},{-29.44f,-120.24f},{-35.43f,-130.64f},{-30.98f,-134.8f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-29.44f,-120.24f},{-37.7f,-117.94f},{-38.62f,-129.9f},{-35.43f,-130.64f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-38.62f,-129.9f},{-37.7f,-117.94f},{-54.39f,-119.81f},{-50.21f,-131.06f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-50.21f,-131.06f},{-54.39f,-119.81f},{-57.3f,-122.81f},{-57.06f,-134.8f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-57.06f,-134.8f},{-57.3f,-122.81f},{-60.21f,-119.8f},{-66.95f,-129.73f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-60.21f,-119.8f},{-68.17f,-115.57f},{-67.74f,-127.56f},{-66.95f,-129.73f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-67.74f,-127.56f},{-68.17f,-115.57f},{-75.39f,-122.14f},{-76.01f,-134.12f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-76.01f,-134.12f},{-75.39f,-122.14f},{-81.9f,-114.13f},{-85.32f,-125.63f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-85.32f,-125.63f},{-81.9f,-114.13f},{-100.87f,-117.78f},{-99.69f,-129.72f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-99.69f,-129.72f},{-100.87f,-117.78f},{-102.83f,-118.39f},{-108.84f,-128.78f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-102.83f,-118.39f},{-104.55f,-114.27f},{-115.21f,-119.77f},{-108.84f,-128.78f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-104.55f,-114.27f},{-107.0f,-112.03f},{-118.48f,-108.54f},{-115.21f,-119.77f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-107.0f,-112.03f},{-98.26f,-106.36f},{-109.71f,-102.76f},{-118.48f,-108.54f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-98.26f,-106.36f},{-102.78f,-91.55f},{-113.61f,-96.7f},{-109.71f,-102.76f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-102.78f,-91.55f},{-105.74f,-88.1f},{-117.72f,-87.35f},{-113.61f,-96.7f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-105.74f,-88.1f},{-99.84f,-79.85f},{-111.83f,-79.44f},{-117.72f,-87.35f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-99.84f,-79.85f},{-105.56f,-70.52f},{-117.56f,-70.59f},{-111.83f,-79.44f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-105.56f,-70.52f},{-97.5f,-57.93f},{-109.46f,-56.92f},{-117.56f,-70.59f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-97.5f,-57.93f},{-101.05f,-47.42f},{-112.3f,-51.6f},{-109.46f,-56.92f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-101.05f,-47.42f},{-103.61f,-35.08f},{-115.47f,-33.3f},{-112.3f,-51.6f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-103.61f,-35.08f},{-100.34f,-31.57f},{-110.99f,-26.04f},{-115.47f,-33.3f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-100.34f,-31.57f},{-99.17f,-17.54f},{-111.16f,-17.84f},{-110.99f,-26.04f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-99.17f,-17.54f},{-105.16f,-1.95f},{-116.95f,-4.14f},{-111.16f,-17.84f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-105.16f,-1.95f},{-104.06f,3.97f},{-114.35f,10.14f},{-116.95f,-4.14f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-104.06f,3.97f},{-98.36f,9.69f},{-109.61f,13.84f},{-114.35f,10.14f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-98.36f,9.69f},{-101.81f,22.7f},{-113.23f,19.02f},{-109.61f,13.84f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-101.81f,22.7f},{-104.47f,33.17f},{-116.29f,31.11f},{-113.23f,19.02f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-104.47f,33.17f},{-103.65f,43.46f},{-115.43f,45.73f},{-116.29f,31.11f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-103.65f,43.46f},{-98.5f,54.53f},{-110.48f,55.2f},{-115.43f,45.73f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-98.5f,54.53f},{-103.08f,69.41f},{-114.99f,67.93f},{-110.48f,55.2f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-103.08f,69.41f},{-100.72f,81.15f},{-111.29f,86.83f},{-114.99f,67.93f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-100.72f,81.15f},{-97.86f,89.71f},{-109.78f,91.07f},{-111.29f,86.83f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-97.86f,89.71f},{-104.91f,101.73f},{-116.86f,100.59f},{-109.78f,91.07f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-104.91f,101.73f},{-102.73f,104.54f},{-111.3f,112.93f},{-116.86f,100.59f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-102.73f,104.54f},{-102.28f,105.11f},{-103.0f,117.08f},{-111.3f,112.93f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-89.28f,100.28f},{-91.08f,112.14f},{-103.0f,117.08f},{-102.28f,105.11f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-77.42f,109.72f},{-79.38f,121.56f},{-91.08f,112.14f},{-89.28f,100.28f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-69.89f,106.47f},{-62.66f,116.05f},{-79.38f,121.56f},{-77.42f,109.72f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-63.94f,99.56f},{-59.85f,110.84f},{-62.66f,116.05f},{-69.89f,106.47f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-33.75f,106.44f},{-33.48f,118.44f},{-59.85f,110.84f},{-63.94f,99.56f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-17.23f,101.4f},{-16.66f,113.38f},{-33.48f,118.44f},{-33.75f,106.44f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-1.28f,104.57f},{-6.02f,115.6f},{-16.66f,113.38f},{-17.23f,101.4f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{-1.28f,104.57f},{0.04f,107.35f},{1.76f,119.22f},{-6.02f,115.6f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{6.72f,97.84f},{10.57f,109.2f},{1.76f,119.22f},{0.04f,107.35f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{31.82f,103.46f},{25.53f,113.68f},{10.57f,109.2f},{6.72f,97.84f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{37.44f,111.44f},{35.06f,123.2f},{25.53f,113.68f},{31.82f,103.46f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{42.21f,107.95f},{50.16f,116.93f},{35.06f,123.2f},{37.44f,111.44f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{50.29f,98.33f},{52.85f,110.06f},{50.16f,116.93f},{42.21f,107.95f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{68.26f,108.33f},{66.86f,120.25f},{52.85f,110.06f},{50.29f,98.33f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{76.15f,106.04f},{85.58f,113.46f},{66.86f,120.25f},{68.26f,108.33f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{87.53f,102.01f},{85.58f,113.46f},{76.15f,106.04f},{75.55f,102.68f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{86.12f,94.84f},{87.53f,102.01f},{75.55f,102.68f},{74.26f,96.71f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{84.0f,79.0f},{86.12f,94.84f},{74.26f,96.71f},{72.34f,76.19f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{89.46f,70.95f},{84.0f,79.0f},{72.34f,76.19f},{77.99f,67.4f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{89.29f,57.13f},{89.46f,70.95f},{77.99f,67.4f},{78.5f,62.37f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{85.26f,54.33f},{89.29f,57.13f},{78.5f,62.37f},{74.11f,58.77f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{86.68f,49.74f},{85.26f,54.33f},{74.11f,58.77f},{75.72f,44.84f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{92.07f,40.8f},{86.68f,49.74f},{75.72f,44.84f},{80.1f,41.65f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{84.24f,32.39f},{92.07f,40.8f},{80.1f,41.65f},{72.77f,35.93f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{87.05f,23.53f},{84.24f,32.39f},{72.77f,35.93f},{75.35f,20.89f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{81.0f,6.0f},{87.05f,23.53f},{75.35f,20.89f},{69.0f,6.0f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{70.3f,-91.23f},{68.04f,-79.81f},{60.1f,-81.46f},{59.23f,-93.07f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{59.23f,-93.07f},{60.1f,-81.46f},{50.89f,-78.36f},{50.49f,-90.0f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{50.49f,-90.0f},{50.89f,-78.36f},{38.73f,-81.47f},{39.64f,-93.07f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{39.64f,-93.07f},{38.73f,-81.47f},{31.52f,-80.69f},{28.33f,-91.89f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{28.33f,-91.89f},{31.52f,-80.69f},{22.32f,-76.97f},{22.94f,-88.59f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall
			.points = {{22.94f,-88.59f},{22.32f,-76.97f},{7.36f,-85.41f},{13.49f,-95.3f}},
			.z = 0.0f,
			.height = 9.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-108.0f,-3.0f},{-108.1f,2.25f},{-113.9f,3.75f},{-114.0f,-3.0f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-108.1f,2.25f},{-106.76f,4.65f},{-111.13f,8.75f},{-113.9f,3.75f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-106.76f,4.65f},{-102.18f,9.14f},{-107.53f,11.86f},{-111.13f,8.75f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-102.18f,9.14f},{-103.61f,23.84f},{-109.41f,22.29f},{-107.53f,11.86f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-103.61f,23.84f},{-108.59f,33.47f},{-114.56f,32.93f},{-109.41f,22.29f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-108.59f,33.47f},{-105.95f,41.46f},{-111.54f,43.65f},{-114.56f,32.93f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-105.95f,41.46f},{-102.11f,52.08f},{-107.98f,53.29f},{-111.54f,43.65f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-102.11f,52.08f},{-103.78f,62.8f},{-109.63f,61.47f},{-107.98f,53.29f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-103.78f,62.8f},{-106.24f,72.25f},{-112.23f,72.09f},{-109.63f,61.47f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-106.24f,72.25f},{-102.74f,84.41f},{-108.52f,86.04f},{-112.23f,72.09f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-102.74f,84.41f},{-102.93f,94.53f},{-108.91f,94.04f},{-108.52f,86.04f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-102.93f,94.53f},{-105.07f,100.15f},{-110.28f,97.19f},{-108.91f,94.04f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-105.07f,100.15f},{-107.89f,102.76f},{-113.89f,102.95f},{-110.28f,97.19f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-107.89f,102.76f},{-104.49f,105.76f},{-107.94f,110.67f},{-113.89f,102.95f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-99.57f,107.56f},{-99.61f,113.56f},{-107.94f,110.67f},{-104.49f,105.76f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-91.72f,104.63f},{-91.87f,110.63f},{-99.61f,113.56f},{-99.57f,107.56f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-80.48f,109.57f},{-82.45f,115.24f},{-91.87f,110.63f},{-91.72f,104.63f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-73.2f,111.56f},{-72.79f,117.54f},{-82.45f,115.24f},{-80.48f,109.57f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-67.01f,108.88f},{-63.58f,113.79f},{-72.79f,117.54f},{-73.2f,111.56f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-61.7f,102.89f},{-60.12f,108.68f},{-63.58f,113.79f},{-67.01f,108.88f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-57.15f,103.78f},{-58.83f,109.54f},{-60.12f,108.68f},{-61.7f,102.89f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-47.76f,106.43f},{-48.74f,112.35f},{-58.83f,109.54f},{-57.15f,103.78f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-40.48f,106.9f},{-42.18f,112.65f},{-48.74f,112.35f},{-47.76f,106.43f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-36.26f,109.45f},{-37.24f,115.37f},{-42.18f,112.65f},{-40.48f,106.9f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-29.06f,107.88f},{-27.3f,113.62f},{-37.24f,115.37f},{-36.26f,109.45f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-16.58f,102.78f},{-16.59f,108.78f},{-27.3f,113.62f},{-29.06f,107.88f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-3.38f,108.22f},{-5.43f,113.86f},{-16.59f,108.78f},{-16.58f,102.78f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{0.84f,110.06f},{2.81f,115.73f},{-5.43f,113.86f},{-3.38f,108.22f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{7.52f,100.53f},{9.58f,106.16f},{2.81f,115.73f},{0.84f,110.06f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{24.38f,104.4f},{21.95f,109.89f},{9.58f,106.16f},{7.52f,100.53f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{38.44f,114.08f},{38.48f,120.08f},{21.95f,109.89f},{24.38f,104.4f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{44.31f,109.62f},{48.59f,113.83f},{38.48f,120.08f},{38.44f,114.08f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{51.52f,109.33f},{48.59f,113.83f},{44.31f,109.62f},{47.03f,105.35f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{52.51f,101.61f},{52.66f,107.61f},{51.52f,109.33f},{47.03f,105.35f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{66.96f,111.97f},{66.08f,117.91f},{52.66f,107.61f},{52.51f,101.61f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{72.21f,109.76f},{75.05f,115.05f},{66.08f,117.91f},{66.96f,111.97f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{77.63f,105.98f},{82.88f,108.89f},{75.05f,115.05f},{72.21f,109.76f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{84.01f,97.98f},{82.88f,108.89f},{77.63f,105.98f},{78.06f,98.77f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{81.61f,91.22f},{84.01f,97.98f},{78.06f,98.77f},{75.79f,92.68f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{80.43f,83.03f},{81.61f,91.22f},{75.79f,92.68f},{74.43f,83.33f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{80.42f,77.88f},{80.43f,83.03f},{74.43f,83.33f},{75.03f,75.23f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{83.03f,75.97f},{80.42f,77.88f},{75.03f,75.23f},{78.65f,71.87f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{87.08f,70.39f},{83.03f,75.97f},{78.65f,71.87f},{81.62f,67.91f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{87.77f,63.36f},{87.08f,70.39f},{81.62f,67.91f},{81.9f,64.62f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{84.05f,57.94f},{87.77f,63.36f},{81.9f,64.62f},{79.19f,61.46f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{81.29f,54.11f},{84.05f,57.94f},{79.19f,61.46f},{75.33f,54.77f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{84.52f,47.56f},{81.29f,54.11f},{75.33f,54.77f},{79.7f,43.98f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{89.06f,43.02f},{84.52f,47.56f},{79.7f,43.98f},{83.14f,42.08f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{89.06f,43.02f},{83.14f,42.08f},{77.41f,34.63f},{83.1f,32.75f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{82.57f,24.9f},{83.1f,32.75f},{77.41f,34.63f},{76.58f,24.55f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{83.72f,17.81f},{82.57f,24.9f},{76.58f,24.55f},{77.77f,18.58f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{80.18f,9.89f},{83.72f,17.81f},{77.77f,18.58f},{74.68f,12.28f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{77.48f,3.4f},{80.18f,9.89f},{74.68f,12.28f},{71.53f,4.16f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{79.62f,-13.1f},{77.48f,3.4f},{71.53f,4.16f},{73.65f,-13.7f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{79.6f,-25.68f},{79.62f,-13.1f},{73.65f,-13.7f},{74.23f,-23.01f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{74.18f,-28.84f},{79.6f,-25.68f},{74.23f,-23.01f},{68.43f,-27.14f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{79.35f,-39.18f},{74.18f,-28.84f},{68.43f,-27.14f},{73.36f,-39.52f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{75.0f,-52.87f},{79.35f,-39.18f},{73.36f,-39.52f},{69.01f,-53.33f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{80.32f,-63.7f},{75.0f,-52.87f},{69.01f,-53.33f},{74.36f,-64.39f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{77.24f,-77.57f},{80.32f,-63.7f},{74.36f,-64.39f},{71.0f,-81.25f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{78.07f,-85.82f},{77.24f,-77.57f},{71.0f,-81.25f},{72.38f,-87.18f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{79.77f,-97.64f},{78.07f,-85.82f},{72.38f,-87.18f},{73.78f,-98.07f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{78.37f,-105.73f},{79.77f,-97.64f},{73.78f,-98.07f},{72.38f,-105.41f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{77.95f,-110.67f},{78.37f,-105.73f},{72.38f,-105.41f},{71.96f,-110.29f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{77.62f,-117.78f},{77.95f,-110.67f},{71.96f,-110.29f},{71.72f,-116.65f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{73.66f,-125.67f},{77.62f,-117.78f},{71.72f,-116.65f},{68.95f,-121.95f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{73.66f,-125.67f},{68.95f,-121.95f},{64.95f,-124.74f},{65.31f,-130.73f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{65.31f,-130.73f},{64.95f,-124.74f},{53.99f,-119.27f},{53.54f,-125.26f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{53.54f,-125.26f},{53.99f,-119.27f},{39.17f,-123.92f},{38.35f,-129.87f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{38.35f,-129.87f},{39.17f,-123.92f},{31.69f,-119.27f},{31.52f,-125.26f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{31.52f,-125.26f},{31.69f,-119.27f},{18.84f,-126.31f},{19.67f,-132.25f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{19.67f,-132.25f},{18.84f,-126.31f},{2.04f,-122.08f},{1.68f,-128.07f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{1.68f,-128.07f},{2.04f,-122.08f},{-7.64f,-123.46f},{-4.63f,-128.65f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-4.63f,-128.65f},{-7.64f,-123.46f},{-11.81f,-129.41f},{-9.72f,-135.04f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-9.72f,-135.04f},{-11.81f,-129.41f},{-22.2f,-126.66f},{-23.75f,-132.46f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-23.75f,-132.46f},{-22.2f,-126.66f},{-31.23f,-123.79f},{-33.24f,-129.44f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-33.24f,-129.44f},{-31.23f,-123.79f},{-44.35f,-119.69f},{-44.24f,-125.69f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-44.24f,-125.69f},{-44.35f,-119.69f},{-55.79f,-124.61f},{-55.25f,-130.58f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-55.25f,-130.58f},{-55.79f,-124.61f},{-60.76f,-123.38f},{-63.47f,-128.73f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-63.47f,-128.73f},{-60.76f,-123.38f},{-65.7f,-119.71f},{-66.38f,-125.67f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-66.38f,-125.67f},{-65.7f,-119.71f},{-73.48f,-123.36f},{-72.63f,-129.3f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-72.63f,-129.3f},{-73.48f,-123.36f},{-79.62f,-122.08f},{-82.21f,-127.5f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-82.21f,-127.5f},{-79.62f,-122.08f},{-84.32f,-118.29f},{-86.2f,-123.99f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-86.2f,-123.99f},{-84.32f,-118.29f},{-92.88f,-118.58f},{-92.23f,-124.55f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-92.23f,-124.55f},{-92.88f,-118.58f},{-103.61f,-120.48f},{-105.07f,-126.3f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-105.07f,-126.3f},{-103.61f,-120.48f},{-107.95f,-117.03f},{-113.35f,-119.65f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-107.95f,-117.03f},{-107.73f,-112.3f},{-113.3f,-110.06f},{-113.35f,-119.65f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-107.73f,-112.3f},{-102.33f,-106.07f},{-108.04f,-104.22f},{-113.3f,-110.06f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-102.33f,-106.07f},{-104.42f,-93.88f},{-110.15f,-95.66f},{-108.04f,-104.22f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-104.42f,-93.88f},{-107.51f,-87.02f},{-113.51f,-87.08f},{-110.15f,-95.66f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-107.51f,-87.02f},{-103.88f,-79.99f},{-109.86f,-79.52f},{-113.51f,-87.08f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-103.88f,-79.99f},{-106.67f,-69.36f},{-112.67f,-69.11f},{-109.86f,-79.52f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-106.67f,-69.36f},{-101.77f,-58.49f},{-107.75f,-58.09f},{-112.67f,-69.11f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-101.77f,-58.49f},{-106.4f,-40.51f},{-112.38f,-41.0f},{-107.75f,-58.09f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-106.4f,-40.51f},{-105.91f,-31.92f},{-111.75f,-30.51f},{-112.38f,-41.0f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-105.91f,-31.92f},{-104.07f,-27.28f},{-109.38f,-24.48f},{-111.75f,-30.51f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-104.07f,-27.28f},{-100.52f,-21.47f},{-106.48f,-20.76f},{-109.38f,-24.48f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-100.52f,-21.47f},{-104.65f,-9.47f},{-110.21f,-11.72f},{-106.48f,-20.76f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-104.65f,-9.47f},{-106.64f,-4.9f},{-112.14f,-7.31f},{-110.21f,-11.72f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{-106.64f,-4.9f},{-108.0f,-3.0f},{-114.0f,-3.0f},{-112.14f,-7.31f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{72.38f,-87.18f},{71.0f,-81.25f},{63.48f,-83.7f},{64.66f,-89.68f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{64.66f,-89.68f},{63.48f,-83.7f},{58.17f,-84.16f},{57.31f,-90.19f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{51.59f,-88.13f},{52.84f,-82.17f},{45.32f,-81.83f},{46.45f,-87.82f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{57.31f,-90.19f},{58.17f,-84.16f},{52.84f,-82.17f},{51.59f,-88.13f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{46.45f,-87.82f},{45.32f,-81.83f},{38.74f,-84.88f},{39.39f,-90.94f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{39.39f,-90.94f},{38.74f,-84.88f},{30.58f,-82.98f},{28.71f,-88.78f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{28.71f,-88.78f},{30.58f,-82.98f},{22.39f,-79.75f},{22.78f,-85.83f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Rockwall top
			.points = {{22.78f,-85.83f},{22.39f,-79.75f},{10.96f,-86.19f},{14.08f,-91.42f}},
			.z = 9.0f,
			.height = 4.0f,
			.texture = &TEX_GRASS,
			.tint = {25,25,25,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // roof
			.points = {{68.19f,23.87f},{64.64f,34.8f},{53.7f,31.25f},{57.26f,20.31f}},
			.z = 7.8f,
			.height = 0.4f,
			.texture = &TEX_WOOD,
			.tint = {12,12,12,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // token
			.points = {{61.45f,27.06f},{61.45f,28.06f},{60.45f,28.06f},{60.45f,27.06f}},
			.z = 1.0f,
			.height = 1.0f,
			.texture = &TEX_TILE_6,
			.tint = {255,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.stretchTexture = true,
			.tickFunction = [](Wall* self) {
				self->rotate(GetFrameTime());
				if (self->touching) {
				    // "Collect" token
				    self->hide = true;
				    self->ignoreCollisions = true;
				
				    // add 1 to score
				    score++;
				
				    // Play collect sound
				    PlaySound(snd_collect);
				
				    // Turn off script
				    self->touching = false;
				}
			},
		},

		{ // token.001
			.points = {{58.63f,-105.88f},{58.63f,-104.88f},{57.63f,-104.88f},{57.63f,-105.88f}},
			.z = 2.301f,
			.height = 1.0f,
			.texture = &TEX_TILE_6,
			.tint = {255,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.stretchTexture = true,
			.tickFunction = [](Wall* self) {
				self->rotate(GetFrameTime());
				if (self->touching) {
				    // "Collect" token
				    self->hide = true;
				    self->ignoreCollisions = true;
				
				    // add 1 to score
				    score++;
				
				    // Play collect sound
				    PlaySound(snd_collect);
				
				    // Turn off script
				    self->touching = false;
				}
			},
		},

		{ // token.002
			.points = {{-29.53f,-54.29f},{-29.53f,-53.29f},{-30.53f,-53.29f},{-30.53f,-54.29f}},
			.z = 6.7f,
			.height = 1.0f,
			.texture = &TEX_TILE_6,
			.tint = {255,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.stretchTexture = true,
			.tickFunction = [](Wall* self) {
				self->rotate(GetFrameTime());
				if (self->touching) {
				    // "Collect" token
				    self->hide = true;
				    self->ignoreCollisions = true;
				
				    // add 1 to score
				    score++;
				
				    // Play collect sound
				    PlaySound(snd_collect);
				
				    // Turn off script
				    self->touching = false;
				}
			},
		},

		{ // token.003
			.points = {{-39.5f,-3.05f},{-39.5f,-2.05f},{-40.5f,-2.05f},{-40.5f,-3.05f}},
			.z = 20.45f,
			.height = 1.0f,
			.texture = &TEX_TILE_6,
			.tint = {255,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.stretchTexture = true,
			.tickFunction = [](Wall* self) {
				self->rotate(GetFrameTime());
				if (self->touching) {
				    // "Collect" token
				    self->hide = true;
				    self->ignoreCollisions = true;
				
				    // add 1 to score
				    score++;
				
				    // Play collect sound
				    PlaySound(snd_collect);
				
				    // Turn off script
				    self->touching = false;
				}
			},
		},

	},
	{ // Things
		{ // Empty.001
			.position = {-28.795f,0.0f,-27.087f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.003
			.position = {-42.526f,0.0f,22.411f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.004
			.position = {-51.739f,0.0f,-23.784f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.005
			.position = {-46.144f,0.0f,-42.218f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.006
			.position = {-77.225f,0.0f,-2.681f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.007
			.position = {-84.242f,0.0f,28.632f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.008
			.position = {-80.091f,0.0f,12.362f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.009
			.position = {-69.546f,0.0f,41.947f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.010
			.position = {-49.18f,0.0f,51.313f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.011
			.position = {-71.61f,0.0f,53.849f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.012
			.position = {-21.669f,0.0f,45.08f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.013
			.position = {-5.585f,0.0f,54.396f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.014
			.position = {12.159f,0.0f,26.625f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.015
			.position = {-5.626f,0.0f,24.647f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.016
			.position = {8.931f,0.0f,59.776f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.017
			.position = {23.032f,0.0f,52.487f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.018
			.position = {31.654f,0.0f,59.409f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.019
			.position = {50.302f,0.0f,46.009f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.021
			.position = {61.834f,0.0f,17.054f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.023
			.position = {61.161f,0.0f,2.443f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.024
			.position = {44.103f,0.0f,0.976f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.025
			.position = {38.677f,0.0f,19.415f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.027
			.position = {49.581f,0.0f,62.608f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.030
			.position = {39.306f,0.0f,80.849f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.031
			.position = {59.435f,0.0f,75.188f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.032
			.position = {18.549f,0.0f,71.833f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.033
			.position = {36.581f,0.0f,70.575f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.034
			.position = {-3.677f,0.0f,72.253f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.035
			.position = {-25.483f,0.0f,63.237f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.036
			.position = {-27.789f,0.0f,78.543f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.037
			.position = {6.178f,0.0f,81.478f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.038
			.position = {-41.628f,0.0f,60.721f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.039
			.position = {-35.967f,0.0f,50.446f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.040
			.position = {-45.402f,0.0f,73.72f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.041
			.position = {-16.467f,0.0f,69.107f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.042
			.position = {-59.45f,0.0f,65.962f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.043
			.position = {-57.563f,0.0f,57.575f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.044
			.position = {-61.337f,0.0f,78.207f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.045
			.position = {-71.15f,0.0f,68.898f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.046
			.position = {-83.228f,0.0f,61.098f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.047
			.position = {-61.337f,0.0f,47.511f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.048
			.position = {-84.989f,0.0f,41.472f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.049
			.position = {-88.008f,0.0f,52.04f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.050
			.position = {26.474f,0.0f,28.64f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.052
			.position = {51.384f,0.0f,-9.856f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.053
			.position = {25.216f,0.0f,-3.566f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.054
			.position = {23.455f,0.0f,13.795f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.055
			.position = {4.333f,0.0f,13.04f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.059
			.position = {-48.807f,0.0f,-60.329f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.060
			.position = {-9.254f,0.0f,-53.083f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.061
			.position = {-24.653f,0.0f,-39.194f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.064
			.position = {10.623f,0.0f,-14.888f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.065
			.position = {-4.977f,0.0f,-12.121f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.066
			.position = {47.861f,0.0f,-25.456f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.068
			.position = {57.422f,0.0f,-40.049f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.069
			.position = {31.758f,0.0f,-34.514f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.070
			.position = {14.9f,0.0f,-27.72f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.071
			.position = {0.055f,0.0f,-23.443f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.073
			.position = {53.648f,0.0f,-57.662f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.074
			.position = {42.074f,0.0f,-45.333f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.075
			.position = {31.003f,0.0f,-55.901f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.076
			.position = {18.171f,0.0f,-43.069f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.078
			.position = {47.358f,0.0f,-75.023f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.079
			.position = {27.481f,0.0f,-67.223f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.083
			.position = {19.147f,0.0f,-74.832f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.096
			.position = {-43.171f,0.0f,-111.788f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.097
			.position = {-42.809f,0.0f,-95.846f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.098
			.position = {-60.2f,0.0f,-107.803f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.101
			.position = {-64.91f,0.0f,-94.397f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.103
			.position = {-81.939f,0.0f,-103.817f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.107
			.position = {-82.664f,0.0f,-90.049f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.108
			.position = {-79.041f,0.0f,-74.107f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.112
			.position = {-78.316f,0.0f,-60.339f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.113
			.position = {-84.838f,0.0f,-37.875f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.115
			.position = {-72.881f,0.0f,-47.296f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.117
			.position = {-85.2f,0.0f,-24.107f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

		{ // Empty.127
			.position = {-88.099f,0.0f,76.255f},
			.size = 10.0f,
			.texture = &TEX_OBJ_TREE_1,
		},

	},
};