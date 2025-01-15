#include <iostream>
#include <cmath>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include "textureloader.h"
#include "weapon.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

#define MAX_COLUMNS 20
const int WINDOW_WIDTH = 1500;
const int WINDOW_HEIGHT = 800;
const Vector2 WINDOW_CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
char inputs = 0;


Player player;
Camera camera;
Enemy enemy;
Weapon cowbell;
Weapon drumstick;
Weapon spinner;



void Init() {
    HANDFRNT = QuickLoadTexture("hand_front.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    HANDBACK = QuickLoadTexture("hand_back.png", WINDOW_WIDTH, WINDOW_HEIGHT);

    TXT_COWBELL = QuickLoadTexture("cowbell.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    TXT_COWBELLSHOOT = QuickLoadTexture("cowbell_shoot.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    TXT_DRUMSTICK = QuickLoadTexture("drumstick.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    TXT_DRUMSTICKSWING = QuickLoadTexture("drumstick_swing.png", WINDOW_WIDTH, WINDOW_HEIGHT);

    TXT_SPINNER = QuickLoadTexture("spinner.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    TXT_SPINNERUSE = QuickLoadTexture("spinner_use.png", WINDOW_WIDTH, WINDOW_HEIGHT);

    TXT_ENEMY = QuickLoadTexture("enemy.png", 400, 600);
    TXT_ENEMYHURT = QuickLoadTexture("enemy_hurt.png", 400, 600);
    TXT_DEAD = QuickLoadTexture("death.png", 200, 800);

    TXT_CROSSHAIR = QuickLoadTexture("crosshair.png", 50, 50);

    cowbell.name = "Cowbell";
    cowbell.cooldown = .5;
    cowbell.damage = 10;
    //cowbell.texture_idle = TXT_COWBELL;
    //cowbell.texture_use = TXT_COWBELLSHOOT;

    

    spinner.name = "Spinner";
    spinner.range = .01;
    spinner.cooldown = .25;
    spinner.damage = 1;
    //spinner.texture_idle = TXT_SPINNER;
    //spinner.texture_use = TXT_SPINNERUSE;

    player.position = { 0,0,0 };
    player.target = { 0,0,1 };
    player.up = { 0,1,0 };
    player.height = 2;
    player.selected = 0;
    player.inventory[0] = drumstick;
    player.inventory[1] = cowbell;
    player.attachCamera(&camera);

    enemy.pos = { 0,1,6 };
    enemy.hitbox = { .5,2,.5 };
    enemy.size = 2;
    enemy.health = 100;
}

void GameLoop() {
    float time = GetTime();
    player.tick();
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
    if (IsMouseButtonDown(0) && time > player.last_shot + player.equipped().cooldown) {
        player.last_shot = time;
        player.ray = GetMouseRay(WINDOW_CENTER, camera);
        RayCollision collision = GetRayCollisionBox(player.ray, enemy.boundingBox());
        if (collision.hit) {
            if (collision.distance <= player.equipped().range) {
                enemy.hurt(player.equipped().damage);
            }
            printf("Hit Distance: %f\n", collision.distance);
        }
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

    if (time > player.last_shot + player.equipped().animation_length) {
        DrawTexture(player.equipped().texture_idle, 0, 0, WHITE);
    }
    else {
        DrawTexture(player.equipped().texture_use, 0, 0, WHITE);
    }


    std::string fps = std::to_string(GetFPS());
    std::string debugline1 = std::to_string(enemy.health);
    std::string debugline2 = std::to_string(enemy.hitframe);
    std::string debugline3 = std::to_string(player.last_shot);
    std::string debugline4 = "Time: " + std::to_string(GetTime());
    DrawText(fps.c_str(), 10, 0, 10, BLACK);
    DrawText(debugline1.c_str(), 10, 20, 10, BLACK);
    DrawText(debugline2.c_str(), 10, 40, 10, BLACK);
    DrawText(debugline3.c_str(), 10, 60, 10, BLACK);
    DrawText(debugline4.c_str(), 10, 80, 10, BLACK);
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