#pragma once
class Screen {
public:
	Color bgcolor;
	std::string title;
	std::string subtitle;
	Color fontcolor;
	bool enabled = true;
	void draw() {
		if (enabled) {
			const int screenWidth = GetScreenWidth();
			const int screenHeight = GetScreenHeight();
			
			DrawRectangle(0, 0, screenWidth, screenHeight, bgcolor);

			const char* titleText = title.c_str();
			int titleWidth = MeasureText(titleText, 40);
			DrawText(titleText, screenWidth / 2 - titleWidth / 2, screenHeight / 2 - 20, 40, fontcolor);

			const char* subtitleText = subtitle.c_str();
			int subtitleWidth = MeasureText(subtitleText, 20);
			DrawText(subtitleText, screenWidth / 2 - subtitleWidth / 2, screenHeight / 2 + 20, 20, fontcolor);
		}
		else {
			printf("Attempted to draw disabled screen\n");
		}
	}
};