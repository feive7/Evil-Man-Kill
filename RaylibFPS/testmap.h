static GameMap testmap = {
	{ // Walls
		{ // Cube.053
			.points = {{1.0f,1.0f},{-1.0f,1.0f},{-1.0f,-1.0f},{1.0f,-1.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.tickFunction = [](Wall* self) {
				static const Vector2 points[] = {
					{10,10},
					{-10,10},
					{-10,-10},
					{10,-10},
				};
				self->keyFrameMove(points, 4);
			}
		},

		{ // Platform
			.points = {{50.0f,50.0f},{-50.0f,50.0f},{-50.0f,-50.0f},{50.0f,-50.0f}},
			.z = -4.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
};