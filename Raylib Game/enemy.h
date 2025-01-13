struct Enemy {
	Vector3 pos;
	Vector3 hitbox; // {Width, Height, Depth}
	float size;
	int health;
	char hitframe;
	void draw() {
		DrawCube(pos, 1, 1, 1, RED);
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
	}
	BoundingBox boundingBox() {
		BoundingBox box = {
			pos.x - hitbox.x / 2, pos.y - hitbox.y / 2, pos.z - hitbox.z / 2,
			pos.x + hitbox.x / 2, pos.y + hitbox.y / 2, pos.z + hitbox.z / 2,
		};
		return box;
	}
};