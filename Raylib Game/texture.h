#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 847
Texture2D QuickLoadTexture(std::string filename, int width, int height) {
	Image img = LoadImage(filename.c_str());
	ImageResize(&img, width, height);
	Texture2D txt = LoadTextureFromImage(img);
	UnloadImage(img);
	return txt;
}
struct Animation {
	int length;
	bool loop;
	bool mirror;
	Texture2D frames[4];
	Texture2D getFrame(int tick) {
		if (length > 0) {
			int frame = 4 * (tick / (float)length);
			if (loop) {
				frame %= 6;
			}
			if (mirror) {
				frame = reflect(frame, 3);
			}
			if (frame < 0) frame = 0;
			if (frame > 3) frame = 3;
			return frames[frame]; 
		}
		return frames[0];
	}
};
Animation QuickLoadAnimation(std::string directory, int width, int height, int length, int flags = 0) {
	Animation anim = {};
	if ((flags >> 0) & 1) {
		anim.loop = true;
	}
	if ((flags >> 1) & 1) {
		anim.mirror = true;
	}
	anim.length = length;
	anim.frames[0] = QuickLoadTexture(directory + "/frame1.png", width, height);
	anim.frames[1] = QuickLoadTexture(directory + "/frame2.png", width, height);
	anim.frames[2] = QuickLoadTexture(directory + "/frame3.png", width, height);
	anim.frames[3] = QuickLoadTexture(directory + "/frame4.png", width, height);
	return anim;
}
Animation ANIM_JOHN_IDLE;
Animation ANIM_JOHN_FIGHT;
Animation ANIM_JOHN_HURT;
void initTextures() {
	ANIM_JOHN_IDLE = QuickLoadAnimation("john/idle", 150, 450, 15, 3);
	ANIM_JOHN_FIGHT = QuickLoadAnimation("john/fight", 150, 450, 4, 3);
	ANIM_JOHN_HURT = QuickLoadAnimation("john/hurt", 150, 450, 15, 0);
}