void AddDebugLine(const char* text, bool reset = false) {
	static int y = 5;
	if (reset) {
		y = 5;
	}
	DrawText(text, 5, y, 20, GREEN);
	y += 20;
}
void AddDebugLine(const char* text, Vector3 vec3, bool reset = false) {
	AddDebugLine(TextFormat(text, vec3.x, vec3.y, vec3.z), reset);
}
void AddDebugLine(const char* text, Vector2 vec2, bool reset = false) {
	AddDebugLine(TextFormat(text, vec2.x, vec2.y), reset);
}
void AddDebugLine(const char* text, float val, bool reset = false) {
	AddDebugLine(TextFormat(text, val), reset);
}
void AddDebugLine(const char* text, int val, bool reset = false) {
	AddDebugLine(TextFormat(text, val), reset);
}
void AddDebugLine(const char* text, size_t val, bool reset = false) {
	AddDebugLine(TextFormat(text, val), reset);
}
void AddDebugLine(const char* text, std::string string, bool reset = false) {
	AddDebugLine(TextFormat(text, string.c_str()), reset);
}

void printTime() {
	printf("%f\n", GetTime());
}