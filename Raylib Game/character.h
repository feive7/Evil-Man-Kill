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
	BoundingBox boundingBox() {
		return {
			position.x - hitbox.x / 2, position.y           , position.z - hitbox.z / 2,
			position.x + hitbox.x / 2, position.y + hitbox.y, position.z + hitbox.z / 2,
		};
	}
	void setSpeedCap(float speed) {
		this->friction = (speed - 1) / speed;
	}
	float velocityMagnitude() {
		return Vector3Distance({ 0 }, velocity);
	}
};