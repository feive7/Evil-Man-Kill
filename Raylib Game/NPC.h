class NPC {
	public:
		std::string name;
		Character character;
		Humanoid humanoid;
		float hit_timestamp;
		void draw3D(Camera camera) {
			DrawBillboard(camera, character.model.frames[int(pingpong(10*GetTime(), 4))], Vector3Add(character.position, {0,humanoid.height / 2,0}), humanoid.height, WHITE);
			//DrawBoundingBox(character.boundingBox(), RED);
		}
		void tick(Player plr) {
			float gameTime = GetTime();
			if (gameTime - hit_timestamp > 1.0f) {
				character.model = ANIM_JOHN_FIGHT;
			}
			else {
				character.model = ANIM_JOHN_HURT;
			}
		}
		void hit(float amount) {
			humanoid.hurt(amount);
			hit_timestamp = GetTime();
		}
	private:
		bool animDone = false;
};