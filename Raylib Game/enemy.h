struct Enemy {
	std::string name;
	Vector3 pos;
	Vector3 hitbox; // {Width, Height, Depth}
	float size;
	int health;
	char hitframe;
	Vector3 top() {
		return Vector3Add(pos, { 0,size / 2 + .2f,0 });
	}
	void draw(Camera camera) {
		if (health > 0) {
			if (hitframe > 0) {
				DrawBillboard(camera, TXT_EVILMANHURT, pos, size, WHITE);
			}
			else {
				DrawBillboard(camera, TXT_EVILMAN, pos, size, WHITE);
			}
		}
		else {
			DrawBillboard(camera, TXT_DEAD, pos, size, WHITE);
		}
	}
	void hurt(int amount) {
		this->health -= amount;
		if (health < 0) {
			this->health = 0;
		}
		else {
			this->hitframe = 50;
		}
	}
	void tick() {
		if (hitframe > 0) {
			this->hitframe--;
		}
		else if (health == 0) {
			health = 100;
		}
	}
	BoundingBox boundingBox() {
		BoundingBox box = {
			pos.x - hitbox.x / 2, pos.y - hitbox.y / 2, pos.z - hitbox.z / 2,
			pos.x + hitbox.x / 2, pos.y + hitbox.y / 2, pos.z + hitbox.z / 2,
		};
		return box;
	}
};