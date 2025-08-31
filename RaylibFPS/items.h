#pragma once
class Item {
public:
	std::string name = "Error_item";
	Texture* texture = nullptr;
	void drawOnScreen() {
		if (texture) {
			float scale = (float)GetScreenHeight() / texture->height;
			DrawTextureEx(*texture, { (float)GetScreenWidth() - texture->width * scale, 0.0f }, 0.0f, scale, WHITE);
		}
	}
};