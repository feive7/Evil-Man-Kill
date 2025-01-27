struct Character {
	Animation model;
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration = { 0 };
	Vector3 hitbox;
	float height;
	float friction = 0.8;
	float speedcap = 4;
	float floor_y = 0;
	void move(Vector3 xyz = {}) {
		this->velocity = xyz;
		//if ((xyz.x || xyz.y || xyz.z)) {
		//	this->velocity = xyz;
		//}
		//this->velocity = Vector3Multiply(velocity, { friction,1,friction });
		this->position = Vector3Add(position, velocity);
		if (position.y > floor_y) {
			velocity.y -= .1;
		}
		else if (velocity.y < floor_y) {
			velocity.y = 0;
		}
		else {
			position.y = floor_y;
		}
	}
	BoundingBox boundingBox(Vector3 after = {0,0,0}) {
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