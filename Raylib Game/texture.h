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
	Texture2D frames[4];
	void setLength(int newLength) {
		this->length = newLength;
	}
	Texture2D getFrame(int tick, int flags = 0) {
		int frameNumber = (8 * tick / length);
		
		if ((flags >> 0) & 1) { // Loop
			frameNumber %= 4;
		}
		if ((flags >> 1) & 1) { // Mirror
			frameNumber = 4 - abs(frameNumber-4);
		}
		frameNumber = (frameNumber > 3 ? 3 : frameNumber);
		frameNumber = (frameNumber < 0 ? 0 : frameNumber);
		return frames[frameNumber];
	}
};
Animation QuickLoadAnimation(std::string directory, int width, int height) {
	Animation anim = {};
	anim.frames[0] = QuickLoadTexture(directory + "/frame1.png", width, height);
	anim.frames[1] = QuickLoadTexture(directory + "/frame2.png", width, height);
	anim.frames[2] = QuickLoadTexture(directory + "/frame3.png", width, height);
	anim.frames[3] = QuickLoadTexture(directory + "/frame4.png", width, height);
	return anim;
}