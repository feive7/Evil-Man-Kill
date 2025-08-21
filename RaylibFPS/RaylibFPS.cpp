#include <iostream>
#include <vector>
#include <raylib.h>
#include <raymath.h>
#include <player.h>

void AddDebugLine(const char* text, bool reset = false) {
	static int y = 5;
	if (reset) { 
		y = 5;
	}
	DrawText(text, 5, y, 20, BLACK);
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

int main() {
	// Init Window
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "FPS");

	InitAudioDevice();

	DisableCursor();

	// Cap the FPS to 60
	SetTargetFPS(60);

	// Init Player
	Player player = { 0 };
	player.body.lookRotation = { 0 };
	player.body.crouchingHeight = 1.0f;
	player.body.standingHeight = 2.0f;
	player.headTimer = 0.0f;
	player.walkLerp = 0.0f;
	player.lean = { 0 };
	player.alive = true;

	// Init player camera
	Camera camera = { 0 };
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.position = {
		player.body.position.x,
		player.body.position.y + player.body.getHeight(),
		player.body.position.z,
	};

	UpdateCameraAngle(&camera, player);

	// Init enemies
	for (int i = 0; i < 10; i++) {
		float x = GetRandomValue(-100, 100);
		float z = GetRandomValue(-100, 100);
		Enemy enemy;
		enemy.body.position.x = x;
		enemy.body.position.y = 0.0f;
		enemy.body.position.z = z;
		enemy.alive = true;
		enemy.target = &player;
		enemies.push_back(enemy);
	}
	
	// Textures
	tex_john = LoadTexture("npc_john.png");
	tex_john_victory = LoadTexture("npc_john_victory.png");

	// Shaders
	shader_discard = LoadShader(NULL, "discard.fs");

	// Sounds
	snd_gunshot = LoadSound("8bitgunshot.wav");
	snd_hit = LoadSound("hit01.wav");

	// Debug toggle
	bool debugEnabled = false;

	while (!WindowShouldClose()) {
		player.update();

		if (IsKeyPressed(KEY_F3)) debugEnabled = !debugEnabled;

		UpdateCameraAngle(&camera, player);

		UpdateLevel();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginShaderMode(shader_discard);
		BeginMode3D(camera);
		DrawLevel(camera);
		EndMode3D();

		DrawCircle(screenWidth / 2, screenHeight / 2, 3.0f, GRAY);

		if (debugEnabled) {
			AddDebugLine("Position: %.2f, %.2f, %.2f", player.body.position, true);
			AddDebugLine("Camera pos: %.2f, %.2f, %.2f", camera.position);
			AddDebugLine("Head Lerp: %.2f", player.body.heightLerp);
			AddDebugLine("Enemies Count: %i", enemies.size());
			AddDebugLine("Bullet Count: %i", projectiles.size());
			AddDebugLine(TextFormat("Player alive: %i", player.alive));
		}

		if (!player.alive) {
			DrawRectangle(0, 0, screenWidth, screenHeight, { 255,0,0,120 });
			const char* text = "You're Dead!!!!!!!!";
			int measure = MeasureText(text, 40);
			DrawText(text, screenWidth / 2 - measure / 2, screenHeight / 2 - 10, 40, WHITE);
		}

		EndDrawing();

		EndShaderMode();
	}

	CloseAudioDevice();

	CloseWindow();

	return 0;
}