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
	float length;
	Texture2D frames[4];
	void setLength(float newLength) {
		this->length = newLength;
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