class Player {
	public:
		std::string name;
		Character character;
		Camera camera;
		int health;
		void move(float f, float r) {
			Vector3 forward = Vector3Scale(GetCameraForward(&camera), f);
			Vector3 right = Vector3Scale(GetCameraRight(&camera), r);
			printf("%f %f %f\n", forward.x, forward.y, forward.y);
			character.position = Vector3Add(character.position, Vector3Add(forward,right));
		}
		void tick() {
			CameraYaw(&camera, -GetMouseDelta().x / 150.0f, false);
			CameraPitch(&camera, -GetMouseDelta().y / 84.0f, true, false, false);
			float forward = .1 * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
			float right = .1 * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
			move(forward, right);
			Vector3 offset = Vector3Subtract(character.position,camera.position);
			Vector3 rotation = { -GetMouseDelta().x,-GetMouseDelta().y,0 };
			camera.position = Vector3Add(camera.position, offset);
			camera.target = Vector3Add(camera.target, offset);
		}
};