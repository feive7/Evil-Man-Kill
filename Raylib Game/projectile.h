struct Projectile {
	Vector3 origin;
	Vector3 target;
	void setAtPlayer(Player player) {
		origin = player.camera.position;
		target = player.camera.target;
		Ray ray = { origin, target };
	}
	Vector3 forward() {
		return Vector3Normalize(Vector3Subtract(target, origin));
	}
	void tick() {
		Vector3 f = forward();
		this->origin = Vector3Add(origin, f);
		this->target = Vector3Add(target, f);
	}
	void draw(Camera camera) {
		DrawBillboard(camera, TXT_BALL, origin, .1, WHITE);
	}
};