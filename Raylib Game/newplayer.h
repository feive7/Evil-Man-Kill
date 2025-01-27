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
		void move(float f, float r, float u, Map map) {
			Vector3 forward = GetCameraForward(&camera);
			forward.y = 0;
			forward = Vector3Scale(Vector3Normalize(forward), f);
			Vector3 right = GetCameraRight(&camera);
			right.y = 0;
			right = Vector3Scale(Vector3Normalize(right), r);
			Vector3 full = Vector3Add(forward, right);
			full.y = u;
			Vector3 thingP = character.position;
			Vector3 thingV = character.velocity;
			for (int i = 0; i < map.num_of_cubes; i++) {
				Cube cube = map.cubes[i];
				if ((cube.flags >> 0) & 1) {
					if (CheckCollisionBoxes(character.boundingBox(), cube.boundingBox())) {
						if (abs(character.position.x - cube.center.x) - character.position.z + cube.center.z < 0) {
							character.position.z = cube.boundingBox().max.z + 1;
							character.velocity.z = 0;
						}
						if (abs(character.position.x - cube.center.x) + character.position.z - cube.center.z < 0) {
							character.position.z = cube.boundingBox().min.z - 1;
							character.velocity.z = 0;
						}
						if (abs(character.position.z - cube.center.z) - character.position.x + cube.center.x < 0) {
							character.position.x = cube.boundingBox().max.x + 1;
							character.velocity.x = 0;
						}
						if (abs(character.position.z - cube.center.z) + character.position.x - cube.center.x < 0) {
							character.position.x = cube.boundingBox().min.x - 1;
							character.velocity.x = 0;
						}
					}
				}
			}
			//character.position = Vector3Add(origin, full);
			character.position = Vector3Add(character.position, full);
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
			// Attack Logic
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

			// Movement Logic
			float forward = (IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPRINT_SPEED : PLAYER_WALK_SPEED) * (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
			float right = (IsKeyDown(KEY_LEFT_SHIFT) ? PLAYER_SPRINT_SPEED : PLAYER_WALK_SPEED) * (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
			float jump = (IsKeyDown(KEY_SPACE) && character.position.y <= character.floor_y);
			move(forward, right, jump, collision_map);
			
			// Camera Logic
			bob_height += .1 * (-abs(sin(bob_tick / 5.0f)) - bob_height);
			CameraYaw(&camera, -GetMouseDelta().x / 300.0f, false);
			CameraPitch(&camera, -GetMouseDelta().y / 168.0f, true, false, false);
			Vector3 offset = Vector3Add(Vector3Subtract(character.position, camera.position), { 0,character.height + bob_height,0 });
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
		void stop() {
			this->character.acceleration = { 0,0,0 };
			this->character.velocity = { 0,0,0 };
		}
		void load_map(Map map) {
			this->collision_map = map;
		}
	private:
		float bob_height;
		int bob_tick;
		int attack_tick;
		Map collision_map;
};