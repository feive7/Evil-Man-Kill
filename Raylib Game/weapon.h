struct Weapon {
	std::string name;
	int base_damage;
	float range;
	int cooldown;
	Animation animation;
	Sound sound;
};
Weapon drumstick;
Weapon evilmangun;
Weapon cowbell;
void initWeapons() {
	drumstick = {
		"Drumstick", 
		1,
		1.5f,
		15,
		QuickLoadAnimation("drumstick", WINDOW_WIDTH, WINDOW_HEIGHT, 10, 2),
		LoadSound("drumstick/swing.mp3")
	};
	evilmangun = {
		"Evil Man Gun",
		100,
		99999.9f,
		15,
		QuickLoadAnimation("admingun", WINDOW_WIDTH, WINDOW_HEIGHT, 15),
		LoadSound("admingun/shoot.mp3")
	};
	cowbell = {
		"Cowbell",
		10,
		15,
		15,
		QuickLoadAnimation("cowbell", WINDOW_WIDTH, WINDOW_HEIGHT, 15),
		LoadSound("cowbell/shoot.mp3")
	};
}