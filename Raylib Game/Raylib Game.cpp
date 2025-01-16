#include <iostream>
#include <cmath>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "draw.h"
#include "textureloader.h"
#include "ball.h"
#include "weapon.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

#define MAX_COLUMNS 20
char inputs = 0;


Player player;
Camera camera;
Enemy enemy;
Ball projectiles[1];


void Init() {
    InitAudioDevice();
    initWeapons();
    LoadTextures();

    player.position = { 0,0,0 };
    player.target = { 1,0,0 };
    player.up = { 0,1,0 };
    player.height = 2;
    player.selected = 0;
    player.inventory[0] = drumstick;
    player.inventory[1] = cowbell;
    player.inventory[2] = evilmangun;
    player.attachCamera(&camera);

    enemy.pos = { 0,1,6 };
    enemy.hitbox = { .5,2,.5 };
    enemy.size = 2;
    enemy.health = 100;
}

void GameLoop() {
    float gameTime = GetTime();
    if (IsKeyPressed(KEY_LEFT)) {
        player.selected--;
        if (player.selected < 0) {
            player.selected = 0;
        }
    }
    else if (IsKeyPressed(KEY_RIGHT)) {
        player.selected++;
        if (player.selected > 10) {
            player.selected = 10;
        }
    }
    if (player.attack_tick == 0) {
        RayCollision collision = GetRayCollisionBox(player.ray, enemy.boundingBox());
        if (collision.hit && collision.distance <= player.equipped().range) {
            enemy.hurt(player.equipped().damage);
        }
        projectiles[0].timestamp = gameTime;
        projectiles[0].life = 1;
        projectiles[0].position = camera.target;
        projectiles[0].velocity = Vector3Subtract(camera.target,camera.position);
    }
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
    for (int i = 0; i < 1; i++) {
        projectiles[i].tick();
        projectiles[i].draw(camera);
    }
    enemy.draw(camera);
    EndMode3D();
    player.tick();
    player.draw();
    DrawTexture(TXT_CROSSHAIR, WINDOW_WIDTH / 2 - 25, WINDOW_HEIGHT / 2 - 25, PURPLE);

    std::string fps = std::to_string(GetFPS());
    std::string debugline1 = std::to_string(enemy.health);
    std::string debugline2 = std::to_string(enemy.hitframe);
    std::string debugline3 = "Shoot Time: " + std::to_string(player.attack_time) + " Shoot Tick: " + std::to_string(player.attack_tick);
    std::string debugline4 = "Time: " + std::to_string(GetTime());
    DrawText(fps.c_str(), 10, 0, 10, BLACK);
    DrawText(debugline1.c_str(), 10, 20, 10, BLACK);
    DrawText(debugline2.c_str(), 10, 40, 10, BLACK);
    DrawText(debugline3.c_str(), 10, 60, 10, BLACK);
    DrawText(debugline4.c_str(), 10, 80, 10, BLACK);

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