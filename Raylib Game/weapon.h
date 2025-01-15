struct Weapon {
	std::string name;
	int damage;
	int range;
	float cooldown;
	float animation_length;
	Texture2D texture_idle;
	Texture2D texture_use;
	bool shake;
};