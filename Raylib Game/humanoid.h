struct Humanoid {
	int maxhealth;
	int health;
	bool isAlive;
	void hurt(int amount) {
		this->health -= amount;
		if (health <= 0) {
			this->isAlive = false;
		}
	}
};