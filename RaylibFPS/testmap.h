static GameMap testmap = {
	{ // Walls
		{ // Ceiling
			.points = {{12.0f,12.0f},{-12.0f,12.0f},{-12.0f,-12.0f},{12.0f,-12.0f}},
			.z = 6.0f,
			.height = 1.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Core
			.points = {{3.0f,3.0f},{-3.0f,3.0f},{-3.0f,-3.0f},{3.0f,-3.0f}},
			.z = -8.0f,
			.height = 7.0f,
			.tint = {255,68,62,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.rotation = 1.0f,
			.rotating = true,
		},

		{ // Cube.032
			.points = {{-10.0f,6.0f},{-12.0f,6.0f},{-12.0f,-6.0f},{-10.0f,-6.0f}},
			.z = 4.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.033
			.points = {{6.0f,6.0f},{-6.0f,6.0f},{-6.0f,-6.0f},{6.0f,-6.0f}},
			.z = -1.0f,
			.height = 1.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.034
			.points = {{12.0f,12.0f},{-12.0f,12.0f},{-12.0f,-12.0f},{12.0f,-12.0f}},
			.z = -9.0f,
			.height = 1.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.035
			.points = {{-2.65f,4.07f},{-3.01f,4.42f},{-4.42f,3.01f},{-4.07f,2.65f}},
			.z = -8.0f,
			.height = 7.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.036
			.points = {{4.07f,2.65f},{4.42f,3.01f},{3.01f,4.42f},{2.65f,4.07f}},
			.z = -8.0f,
			.height = 7.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.037
			.points = {{2.65f,-4.07f},{3.01f,-4.42f},{4.42f,-3.01f},{4.07f,-2.65f}},
			.z = -8.0f,
			.height = 7.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.038
			.points = {{-4.07f,-2.65f},{-4.42f,-3.01f},{-3.01f,-4.42f},{-2.65f,-4.07f}},
			.z = -8.0f,
			.height = 7.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.039
			.points = {{-10.0f,-6.0f},{-12.0f,-6.0f},{-12.0f,-12.0f},{-10.0f,-12.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.040
			.points = {{-10.0f,12.0f},{-12.0f,12.0f},{-12.0f,6.0f},{-10.0f,6.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.041
			.points = {{10.0f,10.0f},{10.0f,12.0f},{-10.0f,12.0f},{-10.0f,10.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.042
			.points = {{12.0f,12.0f},{10.0f,12.0f},{10.0f,6.0f},{12.0f,6.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.050
			.points = {{10.0f,-12.0f},{10.0f,-10.0f},{-10.0f,-10.0f},{-10.0f,-12.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.051
			.points = {{12.0f,-6.0f},{10.0f,-6.0f},{10.0f,-12.0f},{12.0f,-12.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.052
			.points = {{-12.0f,6.0f},{-24.0f,6.0f},{-24.0f,-6.0f},{-12.0f,-6.0f}},
			.z = -10.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.057
			.points = {{12.0f,6.0f},{10.0f,6.0f},{10.0f,-6.0f},{12.0f,-6.0f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.058
			.points = {{7.9f,11.95f},{6.78f,10.29f},{10.1f,8.05f},{11.22f,9.71f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.059
			.points = {{11.22f,-9.71f},{10.1f,-8.05f},{6.78f,-10.29f},{7.9f,-11.95f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.060
			.points = {{-11.22f,9.71f},{-10.1f,8.05f},{-6.78f,10.29f},{-7.9f,11.95f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.061
			.points = {{-7.9f,-11.95f},{-6.78f,-10.29f},{-10.1f,-8.05f},{-11.22f,-9.71f}},
			.z = -8.0f,
			.height = 14.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Door
			.points = {{-10.0f,6.0f},{-12.0f,6.0f},{-12.0f,-6.0f},{-10.0f,-6.0f}},
			.z = -8.0f,
			.height = 12.0f,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.interactFunction = [](Wall* self) {
				static int tick = 0;
				static int sequence = 0;

				// Sequence action
				if (sequence == 0) { // opening sequence
					self->z += 0.1f; // Move up
				}
				else if (sequence == 1) {
					// Wait
				}
				else if (sequence == 2) {
					self->z -= 0.1f; // Move down
				}

				// Update sequence
				if (tick > 80) {
					sequence++;
					tick = 0;
				}
				if (sequence > 2) {
					sequence = 0;
					self->interact = false;
					self->z -= 0.1f;
				}
				tick++;
			}
		},

	},
};