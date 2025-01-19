#include <iostream>
#include <regex>
#include <cmath>
#include <string>
#include <istream>
#include "smath.h"
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "texture.h"
#include "weapon.h"
#include "character.h"
#include "humanoid.h"
#include "newplayer.h"
#include "NPC.h"

Player player;
NPC npc;
int fix = 10;

void Init() {
    InitAudioDevice();
    initTextures();
    initWeapons();
    player.name = "Roland Baker";
    player.character.position = { 0.0f,0.0f,8.0f };
    player.character.height = 6.0f;

    player.camera.position = { 0.0f, 0.0f, 4.0f };
    player.camera.target = { 0.0f, 0.0f, 0.0f };
    player.camera.up = { 0.0f, 4.0f, 0.0f };
    player.camera.fovy = 60.0f;
    player.camera.projection = CAMERA_PERSPECTIVE;
    player.weapon = drumstick;

    npc.name = "John";
    npc.character.position = { 0.0f,0.0f,0.0f };
    npc.character.height = 6.0f;
    npc.character.model = ANIM_JOHN_FIGHT;
}
void GameLoop() {
    // Game Logic
    player.tick();
    npc.tick();
    if (fix > 0) {
        fix--;
        player.camera.target = { 0,4,0 };
    }
    if (IsMouseButtonPressed(0)) {
        npc.hit(player);
    }

    // Game Render
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(player.camera);
    DrawCube({ 0,0,0 }, 1, 1, 1, RED);
    for (int x = -10; x <= 10; x++) {
        for (int y = -10; y <= 10; y++) {
            if ((x + y) % 2 == 0) {
                DrawPlane({ x * 6.0f,0,y * 6.0f }, { 6.0f,6.0f }, LIGHTGRAY);
            }
            else {
                DrawPlane({ x * 6.0f,0,y * 6.0f }, { 6.0f,6.0f }, DARKGRAY);
            }
        }
    }
    npc.draw3D(player.camera);
    EndMode3D();
    player.draw2D();
    DrawText(TextFormat("- Character Position: (%06.3f, %06.3f, %06.3f)", player.character.position.x, player.character.position.y, player.character.position.z), 610, 45, 10, BLACK);
    DrawText(TextFormat("- Camera Position: (%06.3f, %06.3f, %06.3f)", player.camera.position.x, player.camera.position.y, player.camera.position.z), 610, 60, 10, BLACK);
    DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)", player.camera.target.x, player.camera.target.y, player.camera.target.z), 610, 75, 10, BLACK);
    DrawText(TextFormat("- Forward: (%06.3f, %06.3f, %06.3f)", GetCameraForward(&player.camera).x, GetCameraForward(&player.camera).y, GetCameraForward(&player.camera).z), 610, 90, 10, BLACK);
    DrawText(TextFormat("- Right: (%06.3f, %06.3f, %06.3f)", GetCameraRight(&player.camera).x, GetCameraRight(&player.camera).y, GetCameraRight(&player.camera).z), 610, 105, 10, BLACK);
    DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)", player.camera.up.x, player.camera.up.y, player.camera.up.z), 610, 120, 10, BLACK);

    EndDrawing();
}
int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Evil Man Kill");
    Init();
    DisableCursor();
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        GameLoop();
    }
    CloseAudioDevice();
    CloseWindow();

    return 0;
}