#include <iostream>
#include <cmath>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "character.h"
#include "newplayer.h"
#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 847
Player player;
void Init() {
    player.name = "Roland Baker";
    player.character.position = { 0.0f,0.0f,4.0f };

    player.camera.position = { 0.0f, 0.0f, 4.0f };
    player.camera.target = { 4.0f, 0.0f, 4.0f };
    player.camera.up = { 0.0f, 4.0f, 0.0f };
    player.camera.fovy = 60.0f;
    player.camera.projection = CAMERA_PERSPECTIVE;

}

void GameLoop() {
    //UpdateCamera(&player.camera, CAMERA_FIRST_PERSON);
    player.tick();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    //BeginMode3D(player.camera);
    BeginMode3D(player.camera);

    DrawCube({ 0,0,0 }, 1, 1, 1, RED);
    EndMode3D();
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