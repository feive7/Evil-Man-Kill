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
Weapon loadWeaponAssetsFromDirectory(std::string directory) {
	Weapon loaded = {};
	loaded.name = directory;
	loaded.animation = QuickLoadAnimation(directory.c_str(), WINDOW_WIDTH, WINDOW_HEIGHT, 10, 2);
	loaded.sound = LoadSound((directory + "/attack.mp3").c_str());
	return loaded;
}
void initWeapons() {
	drumstick = loadWeaponAssetsFromDirectory("drumstick");
	drumstick.base_damage = 10;
	drumstick.range = 10;
	drumstick.cooldown = 15;

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