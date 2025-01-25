Shader discardAlpha;
Shader defaultShader;
Shader overlayShader;
Shader testShader;
Shader rayMarchShader;
int viewEyeLoc;
int viewCenterLoc;
int runTimeLoc;
int resolutionLoc;
void InitRayMarchShader() {
	
	
}
void InitShaders() {
	discardAlpha = LoadShader(NULL, "shaders/discardAlpha.fs");
	defaultShader = LoadShader(NULL, "shaders/defaultShader.fs");
	overlayShader = LoadShader(NULL, "shaders/overlayShader.fs");
	testShader = LoadShader(NULL, "shaders/shader.fs");
	rayMarchShader = LoadShader(NULL, "shaders/raymarch.fs");
	InitRayMarchShader();
}

void UnloadShaders() {
	UnloadShader(discardAlpha);
	UnloadShader(defaultShader);
	UnloadShader(overlayShader);
}