class Ball {
public:
	Vector3 position;
	Vector3 velocity;
	void update() {
		position += velocity;
	}
};