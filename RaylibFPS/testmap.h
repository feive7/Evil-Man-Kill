static GameMap testmap = {
	{ // Walls
		{ // Cube.053
			.points = {{6.0f,6.0f},{-6.0f,6.0f},{-6.0f,-6.0f},{6.0f,-6.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {0,102,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.054
			.points = {{16.0f,5.0f},{6.0f,5.0f},{6.0f,-5.0f},{16.0f,-5.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {0,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.tickFunction = [](Wall* self) {
				static const Vector3 keyPoints[] = {
					{11,-2,11},
					{-11,-2,11},
					{-11,-2,-11},
					{11,-2,-11},
				};
				self->keyFrameMove(keyPoints, 4);
			}
		},

	},
};