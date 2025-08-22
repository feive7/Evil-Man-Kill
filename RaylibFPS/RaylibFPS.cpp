#include <iostream>
#include <vector>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <collisions.h>
#include <testmap.h>
#include <player.h>
#include <customdebug.h>

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
	player.body.radius = 1.0f;
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
		enemy.body.crouching = false;
		enemy.body.radius = 0.25f;
		enemy.speed = 1.0f;
		enemy.reachedTarget = true;
		enemy.body.lookRotation = { 0 };
		enemy.body.crouchingHeight = 1.0f;
		enemy.body.standingHeight = 2.0f;
		enemy.body.dir = { 0 };
		enemies.push_back(enemy);
	}
	
	// Textures
	tex_john = LoadTexture("npc_john.png");
	tex_john_victory = LoadTexture("npc_john_victory.png");
	tile_1 = LoadTexture("tile_2.png");

	// Shaders
	shader_discard = LoadShader(NULL, "discard.fs");

	// Sounds
	snd_gunshot = LoadSound("8bitgunshot.wav");
	snd_hit = LoadSound("hit01.wav");
	snd_step = LoadSound("step.wav");

	// Music
	music_main = LoadMusicStream("fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("lost_town.mp3");
	music_lose.looping = true;

	// Debug toggle
	bool debugEnabled = false;

	// Music toggle
	bool musicToggle = true;

	//PlayMusicStream(music_main);

	while (!WindowShouldClose()) {
		if (!player.alive && musicToggle) {
			StopMusicStream(music_main);
			PlayMusicStream(music_lose);
			musicToggle = false;
		}
		if (player.alive) {
			//UpdateMusicStream(music_main);
		}
		else {
			UpdateMusicStream(music_lose);
		}

		player.update();

		if (IsKeyPressed(KEY_F3)) debugEnabled = !debugEnabled;

		UpdateCameraAngle(&camera, player);

		UpdateLevel();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginShaderMode(shader_discard);
		BeginMode3D(camera);
		DrawEntities(camera);
		rlSetTexture(tile_1.id);
		rlColor4ub(255, 255, 255, 255);
		rlBegin(RL_QUADS);
		testmap.draw();
		rlEnd();
		DrawCircle3D(player.body.position, player.body.radius, { 1.0f, 0.0f, 0.0f }, 90.0f, GRAY); // Draw player as a circle on the ground
		EndMode3D();

		DrawCircle(screenWidth / 2, screenHeight / 2, 3.0f, GRAY);

		if (debugEnabled) {
			AddDebugLine("Player Position: %.2f, %.2f, %.2f", player.body.position, true);
			AddDebugLine("Player Velocity: %.2f, %.2f, %.2f", player.body.velocity);
			AddDebugLine("Player Speed: %.2f", Vector3Length(player.body.velocity));

			AddDebugLine("Enemy Position: % .2f, % .2f, % .2f", enemies[0].body.position);
			AddDebugLine("Enemy Velocity: %.2f, %.2f, %.2f", enemies[0].body.velocity);
			AddDebugLine("Enemy Dir: %.2f, %.2f, %.2f", enemies[0].body.dir);
			AddDebugLine(TextFormat("Enemy Grounded: %i", enemies[0].body.isGrounded));
		}

		if (!player.alive) {
			DrawRectangle(0, 0, screenWidth, screenHeight, { 255,0,0,120 });
			const char* text = "You're Dead!!!!!!!!";
			int textWidth = MeasureText(text, 40);
			DrawText(text, screenWidth / 2 - textWidth / 2, screenHeight / 2 - 30, 40, WHITE);

			const char* scoreText = TextFormat("Score: %i", score);
			int scoreWidth = MeasureText(scoreText, 20);
			DrawText(scoreText, screenWidth / 2 - scoreWidth / 2, screenHeight / 2 + 20, 20, WHITE);
		}
		else {
			if (!debugEnabled) {
				DrawText(TextFormat("Score: %i", score), 5, 5, 20, BLACK);
			}
		}

		EndDrawing();

		EndShaderMode();
	}

	CloseAudioDevice();

	CloseWindow();

	return 0;
}