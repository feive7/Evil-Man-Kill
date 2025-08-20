class Ball {
public:
	Vector3 position;
	Vector3 velocity;
	void update() {
		position += velocity;
	}
	void draw() {
		DrawSphere(position, 0.5f, BLACK);
	}
};