#define NPC_SPRINT_SPEED 0.5
#define NPC_WALK_SPEED 0.1
class NPC {
	public:
		std::string name;
		Character character;
		Humanoid humanoid;
		void draw3D(Camera camera) {
			DrawBillboard(camera, character.model.getFrame(animTick), Vector3Add(character.position, {0,character.height / 2,0}), character.height, WHITE);
			DrawBoundingBox(character.boundingBox(), RED);
		}
		void tick() {
			animTick++;
			hitTick++;
			character.move();
			updateState();
			if (humanoid.isDead()) {
				character.model = ANIM_JOHN_DEAD;
				deadTick++;
				if (deadTick > 30) {
					deadTick = 0;
					humanoid.health = humanoid.maxhealth;
					humanoid.state = IDLE;
					character.position = { (float)GetRandomValue(-10, 10), 0, (float)GetRandomValue(-10, 10) };
				}
			}
			else if (humanoid.isIdle()) {
				character.model = ANIM_JOHN_IDLE;
			}
			else if (humanoid.isMoving()) {
				character.model = ANIM_JOHN_FIGHT;
			}
			else if (humanoid.isBeingKnockedBack()) {
				character.model = ANIM_JOHN_HURT;
			}
		}
		void updateState() {
			if (!humanoid.isDead()) {
				if (humanoid.isBeingKnockedBack() && character.velocityMagnitude() < knockbackSuppression) humanoid.state = IDLE;
			}
		}
		void target(Player player) {
			if (humanoid.canMove()) {
				humanoid.state = MOVING;
				character.friction = 3.0f / 4.0f; // Regular Movement
				Vector3 moveDirection = Vector3Scale(Vector3Normalize(Vector3Subtract(player.character.position, character.position)), NPC_WALK_SPEED);
				character.move(moveDirection);
			}
		}
		void hitBy(Player player) {
			hitTick = 0; // Reset hit timer
			character.friction = .9; // Slidey
			humanoid.state = KNOCKBACK; // Knockback
			character.velocity = Vector3Scale(Vector3Negate(Vector3Normalize(Vector3Subtract(player.character.position, character.position))), tanh(player.damage() / 10.0f)); // Push NPC Back
			humanoid.hurt(player.damage()); // Hurt NPC
		}
	private:
		int hitTick = 20;
		int animTick = 0;
		float knockbackSuppression = 0.1;
		bool animDone = false;
		int deadTick = 0;
};