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

	// Init Player
	Player player = { 0 };
	player.body.lookRotation = { 0 };
	player.body.height = 0.0f;
	player.headTimer = 0.0f;
	player.walkLerp = 0.0f;
	player.lean = { 0 };

	// Init player camera
	Camera camera = { 0 };
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.position = {
		player.body.position.x,
		player.body.position.y + (BOTTOM_HEIGHT + player.body.height),
		player.body.position.z,
	};

	for (int i = 0; i < 10; i++) {
		float x = GetRandomValue(-100, 100);
		float z = GetRandomValue(-100, 100);
		Enemy enemy;
		enemy.body.position.x = x;
		enemy.body.position.y = 0.0f;
		enemy.body.position.z = z;
		enemy.body.height = 3.0f;
		enemy.alive = true;
		enemy.target = &player.body;
		enemies.push_back(enemy);
	}

	UpdateCameraAngle(&camera, player);

	DisableCursor();

	// Cap the FPS to 60
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		player.update();

		camera.position = {
			player.body.position.x,
			player.body.position.y + (BOTTOM_HEIGHT + player.body.height),
			player.body.position.z,
		};

		UpdateCameraAngle(&camera, player);

		UpdateLevel();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
		DrawLevel();
		EndMode3D();

		DrawCircle(screenWidth / 2, screenHeight / 2, 3.0f, GRAY);

		AddDebugLine("Position: %.2f, %.2f, %.2f", player.body.position, true);
		AddDebugLine("Camera pos: %.2f, %.2f, %.2f", camera.position);
		AddDebugLine("Head Lerp: %.2f", player.body.height);
		AddDebugLine("Enemies Count: %i", enemies.size());
		AddDebugLine("Bullet Count: %i", projectiles.size());

		EndDrawing();
	}

	CloseWindow();

	return 0;
}