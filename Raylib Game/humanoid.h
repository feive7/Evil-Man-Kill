enum STATE {
	DEAD = 0,
	IDLE = 1,
	MOVING = 2,
	KNOCKBACK = 3,
};
struct Humanoid {
	int maxhealth;
	int health;
	int state;
	void hurt(int amount) {
		this->health -= amount;
		if (health <= 0) {
			this->state = DEAD;
		}
	}
	bool isDead() {
		return state == DEAD;
	}
	bool isIdle() {
		return state == IDLE;
	}
	bool isMoving() {
		return state == MOVING;
	}
	bool isBeingKnockedBack() {
		return state == KNOCKBACK;
	}
	bool canMove() {
		return !isDead() && !isBeingKnockedBack();
	}
};
