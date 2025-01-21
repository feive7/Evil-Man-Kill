#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include "smath.h"
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "rcamera.h"
#include "texture.h"
#include "weapon.h"
#include "character.h"
#include "humanoid.h"
#include "newplayer.h"
#include "NPC.h"
#include "gamemap.h"
#define NUM_OF_JOHNS 2
Player player;
NPC npcs[NUM_OF_JOHNS];
RenderTexture2D target;
Cube cube = { {0, 0, 0}, {20,2,2}, BLUE };
Shader shader;
Shader discardAlpha;
Shader viewer;
Shader shiny;
int fix = 10;

void Init() {
    InitAudioDevice();
    InitTextures();
    InitWeapons();
    InitModels();
    
    target = LoadRenderTexture(WINDOW_WIDTH, WINDOW_HEIGHT);
    shader = LoadShader(0, "shader.fs");
    discardAlpha = LoadShader(0, "discardAlpha.fs");
    viewer = LoadShader(0, "test.fs");
    shiny = LoadShader(0, "shiny.fs");

    player.name = "Roland Baker";
    player.character.position = { 0.0f,0.0f,8.0f };
    player.character.height = 6.0f;

    player.camera.position = { 0.0f, 0.0f, 4.0f };
    player.camera.target = { 0.0f, 0.0f, 0.0f };
    player.camera.up = { 0.0f, 4.0f, 0.0f };
    player.camera.fovy = 60.0f;
    player.camera.projection = CAMERA_PERSPECTIVE;
    player.character.friction = 3.0f / 4.0f;
    player.weapon = drumstick;

    for (int i = 0; i < NUM_OF_JOHNS; i++) {
        npcs[i].name = "John";
        npcs[i].character.height = 6.0f;
        npcs[i].character.model = ANIM_JOHN_FIGHT;
        npcs[i].character.hitbox = { 2,6,2 };
        npcs[i].character.friction = 3.0f / 4.0f;
        npcs[i].humanoid.maxhealth = 100;
        npcs[i].humanoid.health = 100;
        npcs[i].humanoid.state = IDLE;
    }
    npcs[0].character.position = { 0.0f,0.0f,0.0f };
    npcs[1].character.position = { 4.0f,0.0f,0.0f };
}
void GameLoop() {
    // Game Logic
    player.tick();
    for (int i = 0; i < NUM_OF_JOHNS; i++) {
        npcs[i].tick();
    }
    if (fix > 0) {
        fix--;
        player.camera.target = { 0,4,0 };
    }
    if (player.isAttacking()) {
        for (int i = 0; i < NUM_OF_JOHNS; i++) {
            RayCollision collision = GetRayCollisionBox(player.ray, npcs[i].character.boundingBox());
            if (collision.hit && collision.distance <= player.weapon.range) {
                npcs[i].hitBy(player);
            }
        }
    }

    // Game Render
    BeginTextureMode(target);
    ClearBackground(BLACK);
    BeginMode3D(player.camera);
    for (int i = 0; i < map.num_of_cubes; i++) {
        DrawCubeStruct(map.cubes[i]);
    }
    BeginShaderMode(discardAlpha);
    for (int i = 0; i < NUM_OF_JOHNS; i++) {
        npcs[i].draw3D(player.camera);
    }
    EndShaderMode();
    EndMode3D();
    player.draw2D();
    EndTextureMode();
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginShaderMode(shader);
    DrawTextureRec(target.texture, { 0,0,(float)target.texture.width,-(float)target.texture.height }, { 0,0 }, WHITE);
    EndShaderMode();
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
    UnloadShader(shader);

    return 0;
}