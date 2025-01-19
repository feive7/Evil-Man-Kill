struct Character {
	Animation model;
	Vector3 position;
	Vector3 velocity;
	float height;
	void move(Vector3 xyz = {}) {
		if (xyz.x || xyz.y || xyz.z) {
			this->velocity = Vector3Add(velocity, xyz);
		}
		this->velocity = Vector3Scale(velocity, 0.8);
		this->position = Vector3Add(position, velocity);
	}
};