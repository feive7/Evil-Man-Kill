#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <player.h>

int main() {
	// Init Window
	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "FPS");

	// Init Player
	Body player = { 0 };
	player.lookRotation = { 0 };
	player.headTimer = 0.0f;
	player.walkLerp = 0.0f;
	player.headLerp = 0.0f;
	player.lean = { 0 };

	// Init player camera
	Camera camera = { 0 };
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.position = {
		player.position.x,
		player.position.y + (BOTTOM_HEIGHT + player.headLerp),
		player.position.z,
	};

	UpdateCameraAngle(&camera, player);

	DisableCursor();

	// Cap the FPS to 60
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		player.update();

		camera.position = {
			player.position.x,
			player.position.y + (BOTTOM_HEIGHT + player.headLerp),
			player.position.z,
		};

		UpdateCameraAngle(&camera, player);
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
		DrawLevel();
		EndMode3D();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}