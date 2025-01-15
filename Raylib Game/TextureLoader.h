struct Animation {
	float length;
	Texture2D frames[4];
	Texture2D getFrame(float time) {
		int frame = 4 * (time / length);
		if (frame > 4) {
			frame = 4;
		}
		return frames[frame];
	}
};
Texture2D QuickLoadTexture(const char* filename, int width, int height) {
    Image img = LoadImage(filename);
    ImageResize(&img, width, height);
    Texture2D txt = LoadTextureFromImage(img);
    UnloadImage(img);
    return txt;
}
Animation QuickLoadAnimation(std::string directory, int width, int height, float length) {
	Animation output;
	output.length = length;
	for (int i = 0; i < 4; i++) {
		const char* C = (directory + "/frame" + std::to_string(i)).c_str();
		Texture2D txt = QuickLoadTexture(C, width, height);
		output.frames[i] = txt;
	}
	return output;
}
Texture2D HANDFRNT;
Texture2D HANDBACK;

Texture2D TXT_COWBELL;
Texture2D TXT_COWBELLSHOOT;

Texture2D TXT_DRUMSTICK;
Texture2D TXT_DRUMSTICKSWING;

Texture2D TXT_SPINNER;
Texture2D TXT_SPINNERUSE;

Texture2D TXT_ENEMY;
Texture2D TXT_ENEMYHURT;
Texture2D TXT_CROSSHAIR;
Texture2D TXT_DEAD;