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
		10,
		10,
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
		500,
		15,
		QuickLoadTexture("admingun/frame1.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("admingun/frame2.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("admingun/frame3.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("admingun/frame4.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		LoadSound("admingun/shoot.mp3")
	};
	cowbell = {
		"Cowbell",
		10,
		15,
		500,
		15,
		QuickLoadTexture("cowbell/frame1.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("cowbell/frame2.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("cowbell/frame3.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture("cowbell/frame4.png", WINDOW_WIDTH, WINDOW_HEIGHT),
		LoadSound("cowbell/shoot.mp3")
	};
}