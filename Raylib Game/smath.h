float fract(float a) {
	return a - floor(a);
}
int reflect(int a, int b) {
	return b - abs(a - b);
}
int pingpong(int a, int b) {
	return reflect(a % (2 * b), b);
}