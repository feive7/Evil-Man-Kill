struct Ball {
	Vector3 position;
	Vector3 velocity;
	float timestamp;
	float life;
	void tick() {
		this->position = Vector3Add(position, velocity);
	}
	void draw(Camera camera) {
		DrawBillboard(camera, TXT_BALL, position, .1, WHITE);
	}
};