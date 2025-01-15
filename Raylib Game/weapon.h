#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 800
struct Weapon {
	std::string name;
	int damage;
	int range;
	float cooldown;
	Animation animation;
	bool shake;
};
Weapon drumstick = {
	"Drumstick",
	1,
	.5,
	1,
	QuickLoadAnimation("drumstick", WINDOW_WIDTH, WINDOW_HEIGHT, 1.0f)
};