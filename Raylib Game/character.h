struct Character {
	Vector3 position;
	Vector3 velocity;
	float height;
	Vector3 head() {
		return Vector3Add(position, { 0,height,0 });
	}
};