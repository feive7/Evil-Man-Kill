struct bullet {
	Vector3 origin;
	Vector3 target;
	Ray ray;
	void setAtPlayer(Player player) {
		origin = player.position;
		target = player.target;
		Ray ray = { origin, target };
	}
};