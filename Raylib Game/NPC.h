class NPC {
	public:
		std::string name;
		Character character;
		Humanoid humanoid;
		void draw3D(Camera camera) {
			DrawBillboard(camera, character.model.frames[0], Vector3Add(character.position, {0,character.height / 2,0}), character.height, WHITE);
			//DrawBoundingBox(character.boundingBox(), RED);
		}
		void tick() {
			animTick++;
			hitTick++;
			character.move();
			float gameTime = GetTime();
			if (animTick > character.model.length) { // wait for animation to finish
				character.model = ANIM_JOHN_FIGHT; // reset character model
				animTick = 0; // reset animation timer
			}
		}
		void hit(Player player) {
			character.model = ANIM_JOHN_HURT; // Play the hurt animation
			hitTick = 0; // Reset hit timer
			character.velocity = Vector3Negate(Vector3Normalize(Vector3Subtract(player.character.position, character.position))); // Push NPC Back
			humanoid.hurt(player.weapon.base_damage); // Hurt NPC
		}
	private:
		int hitTick = 20;
		int animTick = 0;
		bool animDone = false;
};