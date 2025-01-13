#include <iostream>
#include <cmath>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "gun.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

#define MAX_COLUMNS 20
const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 800;
const Vector2 WINDOW_CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
char inputs = 0;

Texture2D QuickLoadTexture(const char* filename, int width, int height) {
    Image img = LoadImage(filename);
    ImageResize(&img, width, height);
    Texture2D txt = LoadTextureFromImage(img);
    UnloadImage(img);
    return txt;
}
Player player;
Camera camera;
Enemy enemy;
Gun pipe;
Texture2D TXT_GUN;
Texture2D TXT_GUNSHOOT;
Texture2D TXT_ENEMY;
Texture2D TXT_ENEMYHURT;
Texture2D TXT_CROSSHAIR;
Texture2D TXT_DEAD;

void Init() {
    TXT_GUN = QuickLoadTexture("gun.png", WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2);
    TXT_GUNSHOOT = QuickLoadTexture("gun_shoot.png", WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2);
    TXT_ENEMY = QuickLoadTexture("enemy.png", 400, 600);
    TXT_ENEMYHURT = QuickLoadTexture("enemy_hurt.png", 400, 600);
    TXT_CROSSHAIR = QuickLoadTexture("crosshair.png", 50, 50);
    TXT_DEAD = QuickLoadTexture("death.png", 200, 800);
    player.position = { 0,0,0 };
    player.target = { 0,0,1 };
    player.up = { 0,1,0 };
    player.height = 2;
    player.attachCamera(&camera);
    enemy.pos = { 0,1,6 };
    enemy.hitbox = { .5,2,.5 };
    enemy.size = 2;
    enemy.health = 10;
}

void GameLoop() {
    float time = GetTime();
    player.tick();
    enemy.tick();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(*player.camera);
    for (int x = -10; x <= 10; x++) {
        for (int y = -10; y <= 10; y++) {
            Color color;
            if ((x + y) % 2 == 0) {
                color = LIGHTGRAY;
            }
            else {
                color = DARKGRAY;
            }
            DrawPlane({ (float)x, 0.0f, (float)y }, { 1.0f, 1.0f }, color);
        }
    }
    if (enemy.health > 0) {
        if (enemy.hitframe > 0) {
            DrawBillboard(*player.camera, TXT_ENEMYHURT, enemy.pos, enemy.size, WHITE);
        }
        else {
            DrawBillboard(*player.camera, TXT_ENEMY, enemy.pos, enemy.size, WHITE);
        }
    }
    else {
        DrawBillboard(*player.camera, TXT_DEAD, enemy.pos, enemy.size, WHITE);
    }
    EndMode3D();
    DrawTexture(TXT_CROSSHAIR, WINDOW_WIDTH / 2 - 25, WINDOW_HEIGHT / 2 - 25, PURPLE);
    if (IsMouseButtonDown(0) && player.last_shot + player.gun.cooldown > time) {
        player.last_shot = time;
        player.ray = GetMouseRay(WINDOW_CENTER, camera);
        RayCollision collision = GetRayCollisionBox(player.ray, enemy.boundingBox());
        if (collision.hit) {
            enemy.hurt(1);
        }
    }

    if (player.last_shot > player.gun.cooldown / 2.0f) {
        DrawTexture(TXT_GUNSHOOT, WINDOW_WIDTH - WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, WHITE);
    }
    else {
        DrawTexture(TXT_GUN, WINDOW_WIDTH - WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, WHITE);
    }

    std::string fps = std::to_string(GetFPS());
    std::string debugline1 = std::to_string(enemy.health);
    std::string debugline2 = std::to_string(enemy.hitframe);
    std::string debugline3 = std::to_string(player.last_shot);
    std::string debugline4 = "Time: " + std::to_string(GetTime());
    std::string debugline5 = std::to_string(player.position.x) + " " + std::to_string(player.position.y) + " " + std::to_string(player.position.z);
    std::string debugline6 = std::to_string(player.target.x) + " " + std::to_string(player.target.y) + " " + std::to_string(player.target.z);
    std::string debugline7 = std::to_string(player.up.x) + " " + std::to_string(player.up.y) + " " + std::to_string(player.up.z);
    DrawText(fps.c_str(), 10, 0, 10, BLACK);
    DrawText(debugline1.c_str(), 10, 20, 10, BLACK);
    DrawText(debugline2.c_str(), 10, 40, 10, BLACK);
    DrawText(debugline3.c_str(), 10, 60, 10, BLACK);
    DrawText(debugline4.c_str(), 10, 80, 10, BLACK);
    DrawText(debugline5.c_str(), 10, 100, 10, BLACK);
    DrawText(debugline6.c_str(), 10, 120, 10, BLACK);
    DrawText(debugline7.c_str(), 10, 140, 10, BLACK);
    EndDrawing();
}
int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "John's assassination");
    Init();
    DisableCursor();
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        GameLoop();
    }
    CloseWindow();

    return 0;
}