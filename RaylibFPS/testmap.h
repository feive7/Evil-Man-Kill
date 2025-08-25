#define TURN_AMOUNT 10
#define DOOR_SPEED 0.1f
#define DOOR_WAIT_TIME 2.0f
#define FLASH_TIME 0.25f
static GameMap testmap = {
	{ // Walls
		{ // Button 1
			.points = {{1.0f,-2.0f},{-1.0f,-2.0f},{-1.0f,-4.0f},{1.0f,-4.0f}},
			.z = 0.0f,
			.height = 2.0f,
			.tint = {0,0,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.interactFunction = [](Wall* self) {
				static int angle = 0.0f;
				self->rotate(TURN_AMOUNT * DEG2RAD);
				angle += TURN_AMOUNT;
				if (angle >= 360) {
					angle = 0;
					self->interact = false;
				}
			}
		},

		{ // Button 2
			.points = {{11.0f,-2.0f},{9.0f,-2.0f},{9.0f,-4.0f},{11.0f,-4.0f}},
			.z = 0.0f,
			.height = 2.0f,
			.tint = {0,255,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.interactFunction = [](Wall* self) {
				static const float zInit = self->z;
				static const float heightInit = self->height;
				static float time = 0.0f;
				static char direction = 1;
				static char sequence = 0;

				if (sequence == 0) { // Opening
					self->z += DOOR_SPEED;
					if (self->z > zInit + heightInit) sequence = 1;
				}
				else if (sequence == 1) { // Waiting
					time += GetFrameTime();
					if (time > DOOR_WAIT_TIME) sequence = 2;
				}
				else if (sequence == 2) { // Closing
					self->z -= DOOR_SPEED;
					if (self->z < zInit) {
						self->z = zInit;
						sequence = 0;
						time = 0.0f;
						self->interact = false;
					}
				}
			}
		},

		{ // Button 3
			.points = {{21.0f,-2.0f},{19.0f,-2.0f},{19.0f,-4.0f},{21.0f,-4.0f}},
			.z = 0.0f,
			.height = 2.0f,
			.tint = {255,0,0,255},
			.surfaceMaterial = SURFACE_REGULAR,
			.interactFunction = [](Wall* self) {
				static const Color colorInit = self->tint;
				static float time = 0.0f;
				static char direction = 1;
				self->tint = ColorLerp(colorInit, BLUE, time);
				time += direction * GetFrameTime() / FLASH_TIME;
				if (time > 1.0f) {
					time = 1.0f;
					direction = -1;
				}
				else if (time < 0.0f) {
					time = 0.0f;
					direction = 1;
					self->interact = false;
				}
			}
		},

		{ // Floor
			.points = {{25.0f,-5.0f},{25.0f,5.0f},{-5.0f,5.0f},{-5.0f,-5.0f}},
			.z = -2.0f,
			.height = 2.0f,
			.tint = {255,255,255,255},
			.surfaceMaterial = SURFACE_REGULAR,
		},

	},
};