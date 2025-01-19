#define SPRINT_SPEED 0.5
#define WALK_SPEED 0.2
class Player {
	public:
		std::string name;
		Character character;
		Camera camera;
		int health;
		Weapon weapon;
		void move(float f, float r) {
			Vector3 forward = GetCameraForward(&camera);
			forward.y = 0;
			forward = Vector3Scale(Vector3Normalize(forward),f);
			Vector3 right = GetCameraRight(&camera);
			right.y = 0;
			right = Vector3Scale(Vector3Normalize(right), r);
			character.move(Vector3Add(forward,right));
			if (f || r) {
				bob_tick++;
			}
			else {
				bob_tick = 0;
			}
		}
		void tick() {
			if (IsMouseButtonDown(0) && attack_tick > weapon.cooldown) {
				attack_tick = 0;
				SetSoundPitch(weapon.sound, GetRandomValue(10, 15) / 10.0f);
				PlaySound(weapon.sound);
			}
			CameraYaw(&camera, -GetMouseDelta().x / 300.0f, false);
			CameraPitch(&camera, -GetMouseDelta().y / 168.0f, true, false, false);
			float forward = (IsKeyDown(KEY_LEFT_SHIFT) ? SPRINT_SPEED : WALK_SPEED) * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
			float right = (IsKeyDown(KEY_LEFT_SHIFT) ? SPRINT_SPEED : WALK_SPEED) * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
			bob_height += .1 * (-abs(sin(bob_tick/5.0f)) - bob_height);
			move(forward, right);
			Vector3 offset = Vector3Add(Vector3Subtract(character.position, camera.position), { 0,character.height,0 });
			Vector3 rotation = { -GetMouseDelta().x,-GetMouseDelta().y,0 };
			camera.position = Vector3Add(camera.position, offset);
			camera.target = Vector3Add(camera.target, offset);
			attack_tick++;
		}
		void draw2D() {
			DrawTexture(weapon.animation.getFrame(attack_tick,2), 0, 0, WHITE);
		}
	private:
		float bob_height;
		int bob_tick;
		int attack_tick;
};