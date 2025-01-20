#define PLAYER_SPRINT_SPEED 0.5
#define PLAYER_WALK_SPEED 0.2
class Player {
	public:
		std::string name;
		Character character;
		Camera camera;
		int health;
		Weapon weapon;
		Ray ray;
		int consecutiveHits = 0;
		bool willCrit;
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
		int crit_window() {
			return weapon.cooldown + 10;
		}
		void tick() {
			if (IsMouseButtonDown(0) && attack_tick >= weapon.cooldown) {
				attack_tick = 0;
				SetSoundPitch(weapon.sound, GetRandomValue(10, 15) / 10.0f);
				PlaySound(weapon.sound);
				consecutiveHits++;
			}
			else {
				attack_tick++;
				if (attack_tick >= crit_window()) {
					consecutiveHits = 0;
				}
			}
			castRay();
			CameraYaw(&camera, -GetMouseDelta().x / 300.0f, false);
			CameraPitch(&camera, -GetMouseDelta().y / 168.0f, true, false, false);
			float forward = (IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPRINT_SPEED : PLAYER_WALK_SPEED) * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
			float right = (IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPRINT_SPEED : PLAYER_WALK_SPEED) * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
			bob_height += .1 * (-abs(sin(bob_tick/5.0f)) - bob_height);
			move(forward, right);
			Vector3 offset = Vector3Add(Vector3Subtract(character.position, camera.position), { 0,character.height,0 });
			Vector3 rotation = { -GetMouseDelta().x,-GetMouseDelta().y,0 };
			camera.position = Vector3Add(camera.position, offset);
			camera.target = Vector3Add(camera.target, offset);
		}
		void draw2D() {
			DrawTexture(TXT_CROSSHAIR, WINDOW_WIDTH / 2 - 25, WINDOW_HEIGHT / 2 - 25, WHITE);
			DrawTexture(weapon.animation.getFrame(attack_tick), 0, 0, WHITE);
			DrawRing({ WINDOW_WIDTH / 2,WINDOW_HEIGHT / 2 }, 25, 30, 0, 360 * critProgress(), 20, (critProgress() == 1 ? BLUE : RED));
		}
		void castRay() {
			ray.position = camera.position;
			ray.direction = GetCameraForward(&camera);
		}
		bool isAttacking() {
			return attack_tick == 0;
		}
		int attackTick() {
			return attack_tick;
		}
		int damage() {
			int d = (10 - consecutiveHits);
			if (d < 0) d = 0;
			return d;
		}
		int critTick() {
			int tick = crit_window() - attackTick();
			return tick;
		}
		float critProgress() {
			float prog = (float)critTick() / crit_window();
			if (prog < 0) {
				prog = 0;
			}
			prog = abs(1-prog);
			return prog;
		}
	private:
		float bob_height;
		int bob_tick;
		int attack_tick;
};