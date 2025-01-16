struct Player {
	Character character;
	Humanoid humanoid;
	Camera* camera;
	int selected;
	Weapon inventory[10];

	int weapon_frame = 0;

	int attack_tick;
	float attack_time;

	Ray ray;

	char camera_mode = 0;

	Weapon equipped() {
		return inventory[selected];
	}
	void attachCamera(Camera* cam) {
		Vector3 offset = Vector3Subtract(character.position, camera->position);
		camera->position = Vector3Add(camera->position, offset);
		camera->target = Vector3Add(camera->target, offset);
		camera->up = Vector3Add(camera->up, offset);
	}
	void tick() {
		float gameTime = GetTime();

		// Handle rotation
		CameraYaw(camera, -GetMouseDelta().x / 400.0f, false);
		CameraPitch(camera, -GetMouseDelta().y / 225.0f, true, false, false);

		// Handle movement
		float moveForward = 0.05f * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
		float moveRight = 0.05f * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
		//PlayerMove(moveForward, moveRight);
		//this->position = Vector3Add(this->position, this->velocity);
		//this->target = Vector3Add(this->target, this->velocity);

		// Handle mouse down
		this->attack_tick++;
		this->weapon_frame = FrameIndex(gameTime - attack_time, equipped().animation.length);
		if (IsMouseButtonDown(0)) {
			if (gameTime - attack_time > equipped().cooldown) {
				this->attack_time = gameTime;
				this->attack_tick = 0;
				this->weapon_frame = 0;
				ray = GetMouseRay(WINDOW_CENTER, *camera);
				PlaySound(equipped().sound);
			}
		}
		attachCamera(camera);
	}
	void draw() {
		DrawTexture(equipped().animation.frames[weapon_frame], 0, 0, WHITE);
		DrawTextEx(goof, equipped().name.c_str(), { 10, WINDOW_HEIGHT - 100 }, 40, 1, BLACK);
	}
};