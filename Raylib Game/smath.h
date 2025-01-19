float fract(float a) {
	return a - floor(a);
}

float pingpong(float a, float b) {
	if (b == 0.0) {
		return 0.0f;
	}
	else {
		return abs(fract((a - b) / (b * 2.0)) * b * 2.0 - b);
	}
}