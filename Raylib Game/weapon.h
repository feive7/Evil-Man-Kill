const Vector2 WINDOW_CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
struct Weapon {
	std::string name;
	int damage;
	float range;
	float cooldown;
	Animation animation;
	Sound sound;
	bool shake;
};
Weapon drumstick;
Weapon evilmangun;
Weapon cowbell;
void initWeapons() {
	drumstick = {
		"Drumstick",
		1,
		1.5f,
		0.2f,
		0.3f,
		QuickLoadTexture("drumstick/frame1.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("drumstick/frame2.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("drumstick/frame3.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("drumstick/frame4.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		LoadSound("drumstick/swing.mp3")
	};
	evilmangun = {
		"Evil Man Gun",
		100,
		99999.9f,
		0.5f,
		QuickLoadAnimation("admingun", WINDOW_WIDTH, WINDOW_HEIGHT, 0.15f),
		LoadSound("admingun/shoot.mp3")
	};
	cowbell = {
		"Cowbell",
		10,
		15,
		1.0f,
		QuickLoadAnimation("cowbell", WINDOW_WIDTH, WINDOW_HEIGHT, 0.15f),
		LoadSound("cowbell/shoot.mp3")
	};
}