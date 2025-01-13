struct Player {
	Vector3 position;
	Vector3 target;
	Vector3 up;
	float height;
	Camera* camera;
	Gun gun;
	float last_shot;
	Ray ray;
	char camera_mode = 0;

	void attachCamera(Camera* cam) {
		cam->position = position;
		cam->target = target;
		cam->up = Vector3Add(position, { 0.0f, 1.0f, 0.0f });
		cam->fovy = 60.0f;
		cam->projection = CAMERA_PERSPECTIVE;
		camera = cam;
	}
	Camera getCamera() {
		Camera cam = *camera;
		cam.position = position;
		cam.target = target;
		cam.up = up;
		return cam;
	}
	Vector3 getUp() {
		return Vector3Normalize(this->up);
	}
	Vector3 getForward() {
		return Vector3Normalize(Vector3Subtract(this->target, this->position));
	}
	Vector3 getRight() {
		Vector3 forward = getForward();
		Vector3 up = getUp();
		return Vector3Normalize(Vector3CrossProduct(forward, up));
	}
	void PlayerMove(float forward, float right) {
		Vector3 f = getForward();
		Vector3 r = getRight();
		f.y = 0;
		r.y = 0;
		f = Vector3Normalize(f);
		r = Vector3Normalize(r);
		this->position.x += forward * f.x + right * r.x;
		this->position.z += forward * f.z + right * r.z;
		this->target.x += forward * f.x + right * r.x;
		this->target.z += forward * f.z + right * r.z;
		this->position.y += forward * f.y + right * r.y;
		this->target.y += forward * f.y + right * r.y;
	}

	void PlayerYaw(float angle, bool rotateAroundTarget) {
		Vector3 up = getUp();

		// View vector
		Vector3 targetPosition = Vector3Subtract(this->target, this->position);

		// Rotate view vector around up axis
		targetPosition = Vector3RotateByAxisAngle(targetPosition, up, angle);

		if (rotateAroundTarget)
		{
			// Move position relative to target
			this->position = Vector3Subtract(this->target, targetPosition);
		}
		else // rotate around camera.position
		{
			// Move target relative to position
			this->target = Vector3Add(this->position, targetPosition);
		}
	}
	void PlayerPitch(float angle, bool lockView, bool rotateAroundTarget, bool rotateUp) {
		Vector3 up = getUp();

		// View vector
		Vector3 targetPosition = Vector3Subtract(this->target, this->position);

		if (lockView)
		{
			// In these camera modes we clamp the Pitch angle
			// to allow only viewing straight up or down.

			// Clamp view up
			float maxAngleUp = Vector3Angle(up, targetPosition);
			maxAngleUp -= 0.001f; // avoid numerical errors
			if (angle > maxAngleUp) angle = maxAngleUp;

			// Clamp view down
			float maxAngleDown = Vector3Angle(Vector3Negate(up), targetPosition);
			maxAngleDown *= -1.0f; // downwards angle is negative
			maxAngleDown += 0.001f; // avoid numerical errors
			if (angle < maxAngleDown) angle = maxAngleDown;
		}

		// Rotation axis
		Vector3 right = getRight();

		// Rotate view vector around right axis
		targetPosition = Vector3RotateByAxisAngle(targetPosition, right, angle);

		if (rotateAroundTarget)
		{
			// Move position relative to target
			this->position = Vector3Subtract(this->target, targetPosition);
		}
		else // rotate around camera.position
		{
			// Move target relative to position
			this->target = Vector3Add(this->position, targetPosition);
		}

		if (rotateUp)
		{
			// Rotate up direction around right axis
			this->up = Vector3RotateByAxisAngle(this->up, right, angle);
		}
	}
	void tick() {
		// Handle rotation
		PlayerYaw(-GetMouseDelta().x / 400.0f, false);
		PlayerPitch(-GetMouseDelta().y / 225.0f, true, false, false);

		// Handle movement
		float moveForward = 0.2f * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
		float moveRight = 0.2f * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
		PlayerMove(moveForward, moveRight);

		// Update the camera's position and target
		this->camera->position = position;
		this->camera->position.y += 2;
		this->camera->target = target;
		this->camera->target.y += 2;
		this->camera->up = up;
		this->camera->up.y += 2;
	}

};