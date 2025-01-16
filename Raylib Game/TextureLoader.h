#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 844
int FrameIndex(float time, float length) {
	int frame = 8 * (time / length);
	int i = 3 - abs(3 - frame);
	if (i > 3) {
		i = 3;
	}
	if (i < 0) {
		i = 0;
	}
	return i;
}
struct Animation {
	float length;
	Texture2D frames[4];
	Texture2D getFrame(float time) {
		int i = FrameIndex(time, length);
		return frames[i];
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
	Animation output = {
		length,
		QuickLoadTexture((directory + "/frame1.png").c_str(), WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture((directory + "/frame2.png").c_str(), WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture((directory + "/frame3.png").c_str(), WINDOW_WIDTH, WINDOW_HEIGHT),
		QuickLoadTexture((directory + "/frame4.png").c_str(), WINDOW_WIDTH, WINDOW_HEIGHT),
	};
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

Texture2D TXT_EVILMAN;
Texture2D TXT_EVILMANHURT;
Texture2D TXT_CROSSHAIR;
Texture2D TXT_DEAD;
Texture2D TXT_BALL;
Font goof;
void LoadTextures() {
	TXT_EVILMAN = QuickLoadTexture("john.png", 600, 900);
	TXT_EVILMANHURT = QuickLoadTexture("john_hurt.png", 600, 900);
	TXT_DEAD = QuickLoadTexture("death.png", 600, 900);
	TXT_CROSSHAIR = QuickLoadTexture("crosshair.png", 50, 50);
	TXT_BALL = QuickLoadTexture("ball.png", 100, 100);

	goof = LoadFont("DURA.ttf");
}