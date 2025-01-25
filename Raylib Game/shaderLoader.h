Shader discardAlpha;
Shader defaultShader;
Shader overlayShader;
Shader testShader;

void InitShaders() {
	discardAlpha = LoadShader(NULL, "shaders/discardAlpha.fs");
	defaultShader = LoadShader(NULL, "shaders/defaultShader.fs");
	overlayShader = LoadShader(NULL, "shaders/overlayShader.fs");
	testShader = LoadShader(NULL, "shaders/shader.fs");
}

void UnloadShaders() {
	UnloadShader(discardAlpha);
	UnloadShader(defaultShader);
	UnloadShader(overlayShader);
}