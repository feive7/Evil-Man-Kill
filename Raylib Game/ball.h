struct Ball {
	Vector3 position;
	Vector3 velocity;
	void tick(Vector3 target) {
		this->position = Vector3Add(position, velocity);
	}
	void draw(Camera camera) {
		DrawBillboard(camera, TXT_BALL, position, .1, WHITE);
	}
};