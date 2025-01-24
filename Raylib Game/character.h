struct Character {
	Animation model;
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration = { 0 };
	Vector3 hitbox;
	float height;
	float friction = 0.8;
	float speedcap = 4;
	void move(Vector3 xyz = {}) {
		if ((xyz.x || xyz.y || xyz.z)) {
			this->velocity = Vector3Add(velocity, xyz);
		}
		this->velocity = Vector3Scale(velocity, friction);
		this->position = Vector3Add(position, velocity);
	}
	BoundingBox boundingBox(Vector3 after) {
		BoundingBox b;
		b = {
			position.x - hitbox.x / 2 + after.x, position.y + after.y, position.z - hitbox.z / 2 + after.z,
			position.x + hitbox.x / 2 + after.x, position.y + hitbox.y + after.y, position.z + hitbox.z / 2 + after.z,
		};
		return b;
	}
	void setSpeedCap(float speed) {
		this->friction = (speed - 1) / speed;
	}
	float velocityMagnitude() {
		return Vector3Distance({ 0 }, velocity);
	}
};