static GameMap testmap = {
	{ // Walls
		{ // Cube
			.points = {{10.0f,10.0f},{-10.0f,10.0f},{-10.0f,-10.0f},{10.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &GRASS,
			.tint = {0,60,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.001
			.points = {{10.0f,9.0f},{8.0f,9.0f},{8.0f,7.0f},{10.0f,7.0f}},
			.z = 0.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.tickFunction = [](Wall* self) {
				#define DOOR_SPEED 0.1f
				#define DOOR_WAIT_TIME 1
				static int tick = 0;
				static int sequence = 0;
				static const float zInit = self->z;
				static const float heightInit = self->height;
				static float time = 0.0f;
				static char direction = 1;
				
				// Sequence action
				if (self->touching) {
				    if (sequence == 0) { // Opening
				        self->move({ 0,DOOR_SPEED,0 }); // Move up
				        if (self->z > zInit + heightInit) sequence = 1;
				    }
				    else if (sequence == 1) { // Waiting
				        time += GetFrameTime();
				        self->move({ 0,0,0 });
				        if (time > DOOR_WAIT_TIME) sequence = 2;
				    }
				    else if (sequence == 2) { // Closing
				        self->move({ 0,-DOOR_SPEED,0 }); // Move down
				        if (self->z < zInit) {
				            self->z = zInit;
				            sequence = 0;
				            time = 0.0f;
				            self->move({ 0,0,0 });
				            self->touching = false;
				        }
				    }
				}
			},
		},

		{ // Cube.002
			.points = {{3.0f,16.0f},{-3.0f,16.0f},{-3.0f,10.0f},{3.0f,10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.tickFunction = [](Wall* self) {
				const Vector3 keyPoints[] = {
				    {0,-2,13},
				    {0,-2,33},
				};
				if (self->touching) {
				    self->keyFrameMove(keyPoints, 2);
				    self->touching = false;
				}
			},
		},

		{ // Cube.003
			.points = {{10.0f,56.0f},{-10.0f,56.0f},{-10.0f,36.0f},{10.0f,36.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &GRASS,
			.tint = {0,60,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

		{ // Cube.004
			.points = {{-10.0f,10.0f},{-30.0f,10.0f},{-30.0f,-10.0f},{-10.0f,-10.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.texture = &GRASS,
			.tint = {0,255,255,255},
			.surfaceMaterial = SURFACE_ICE,
		},

	},
};