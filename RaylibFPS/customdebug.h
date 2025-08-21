void WatchFloat(float* value) {
	static bool running = false;
	static float lastValue = 0.0f;
	if (!running) {
		printf("New float watcher created\n");
		running = true;
		lastValue = *value;
	}
	if (*value != lastValue) {
		printf("Value changed from %f to %f\n", lastValue, *value);
		lastValue = *value;
	}
}
inline bool isNeg(float value) {
	if (value < 0.0f) {
		return true;
	}
	false;
}
void WatchSignFlip(float* value) {
	static bool running = false;
	static bool wasNeg = false;
	if (!running) {
		printf("New float watcher created\n");
		running = true;
		wasNeg = isNeg(*value);
	}
	if (isNeg(*value) != wasNeg) {
		printf(isNeg(*value) ? "Value flipped from positive to negative" : "Value flipped from negative to positive");
		wasNeg = isNeg(*value);
	}
}
void Test() {
	printf("Test\n");
}