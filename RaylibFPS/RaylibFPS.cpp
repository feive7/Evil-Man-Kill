#include <iostream>
#include <vector>
#include <functional>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <glob.h>
#include <pathfinding.h>
#include <GameMap.h>

#include <maps/MAP_COSTCO.h>
#include <maps/MAP_ABSTRACTIONS.h>
#include <maps/MAP_EXAMPLE.h>
#include <maps/MAP_NOSTALGIA.h>

#include <projectile.h>
#include <body.h>
#include <player.h>
#include <NPC.h>
#include <customdebug.h>

//#define ENABLE_JOHNS
// Debug toggle
#ifdef _DEBUG
bool debugEnabled = false;
#else
bool debugEnabled = false;
#endif

bool startscreen = true;

// Update camera
static void UpdateCameraAngle(Camera* camera, Player player) {
    float delta = GetFrameTime();

    camera->position = player.body.getHeadPos();

    const Vector3 up = { 0.0f, 1.0f, 0.0f };
    const Vector3 targetOffset = { 0.0f, 0.0f, -1.0f };

    // Left and right
    Vector3 yaw = Vector3RotateByAxisAngle(targetOffset, up, player.body.lookRotation.x);

    // Up and down
    Vector3 right = Vector3Normalize(Vector3CrossProduct(yaw, up));

    // Rotate view vector around right axis
    float pitchAngle = -player.body.lookRotation.y - player.lean.y;
    pitchAngle = Clamp(pitchAngle, -PI / 2 + 0.0001f, PI / 2 - 0.0001f); // Clamp angle so it doesn't go past straight up or straight down
    Vector3 pitch = Vector3RotateByAxisAngle(yaw, right, pitchAngle);

    // Update camera based on body state
    if (player.body.crouching) {
        camera->fovy = Lerp(camera->fovy, 55.0f, 5.0f * delta);
    }
    else {
        camera->fovy = Lerp(camera->fovy, 60.0f, 5.0f * delta);
    }

    // Head animation
    // Rotate up direction around forward axis
    float headSin = sin(player.headTimer * PI);
    float headCos = cos(player.headTimer * PI);
    const float stepRotation = 0.01f;
    camera->up = Vector3RotateByAxisAngle(up, pitch, headSin * stepRotation + player.lean.x);

    // Camera BOB
    const float bobSide = 0.1f;
    const float bobUp = 0.15f;
    Vector3 bobbing = Vector3Scale(right, headSin * bobSide);
    bobbing.y = fabsf(headCos * bobUp);

    camera->position = Vector3Add(camera->position, Vector3Scale(bobbing, player.walkLerp));
    camera->target = Vector3Add(camera->position, pitch);
}

// Update game level
static void UpdateLevel(void) {
    BoundingBox p = player.body.getBoundingBox();
    for (auto itA = enemies.begin(); itA != enemies.end(); itA++) {
        Enemy& enemyA = *itA;
        BoundingBox a = enemyA.body.getBoundingBox();
        for (Projectile& projectile : projectiles) {
            BoundingBox b = projectile.getBoundingBox();
            if (CheckCollisionBoxes(a, b)) {
                enemyA.body.alive = false;
                projectile.alive = false;
                PlaySound(snd_hit);
                score++;
            }
        }
        if (CheckCollisionBoxes(a, p)) {
            //player.body.alive = false;
        }
    }
    for (Projectile& projectile : projectiles) {
        projectile.update();
    }


    // Remove dead projectiles in one pass
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [](const Projectile& p) { return !p.alive; }),
        projectiles.end());
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const Enemy& p) { return !p.body.alive; }),
        enemies.end());

    for (auto itA = enemies.begin(); itA != enemies.end(); itA++) {
        Enemy& enemyA = *itA;
        for (auto itB = enemies.begin(); itB != enemies.end(); itB++) {
            if (itA == itB) continue;
            Enemy& enemyB = *itB;
            float invdist = 1.0f / Vector3Distance(enemyA.body.position, enemyB.body.position);
            if (invdist > 1.0f) {
                enemyA.body.velocity -= Vector3Scale(Vector3Normalize(enemyB.body.position - enemyA.body.position), invdist);
            }
        }
        enemyA.update();
    }



    player.target = { 0 };
    Ray playerTargetRay = player.getForwardRay();
    bool wallHit = false;
    for (Wall& wall : loadedMap->walls) {
        for (Enemy& enemy : enemies) {
            Ray downRay = enemy.getDownRay();
            Ray targetRay = enemy.getTargetRay();

            Vector3 p1 = { wall.points[0].x,wall.z,wall.points[0].y };
            Vector3 p2 = { wall.points[1].x,wall.z,wall.points[1].y };
            Vector3 p3 = { wall.points[2].x,wall.z,wall.points[2].y };
            Vector3 p4 = { wall.points[3].x,wall.z,wall.points[3].y };
            ClosestRayCollision(enemy.downRayCollision, GetRayCollisionQuad(downRay, p1, p2, p3, p4));
            ClosestRayCollision(enemy.targetRayCollision, GetRayCollisionQuad(targetRay, p1, p2, p3, p4));

            p1 = { wall.points[0].x,wall.z + wall.height,wall.points[0].y };
            p2 = { wall.points[1].x,wall.z + wall.height,wall.points[1].y };
            p3 = { wall.points[2].x,wall.z + wall.height,wall.points[2].y };
            p4 = { wall.points[3].x,wall.z + wall.height,wall.points[3].y };
            ClosestRayCollision(enemy.downRayCollision, GetRayCollisionQuad(downRay, p1, p2, p3, p4));
            ClosestRayCollision(enemy.targetRayCollision, GetRayCollisionQuad(targetRay, p1, p2, p3, p4));

            for (int i = 0; i < 4; i++) {
                p1 = { wall.points[i].x,wall.z,wall.points[i].y };
                p2 = { wall.points[(i + 1) % 4].x,wall.z,wall.points[(i + 1) % 4].y };
                p3 = { wall.points[(i + 1) % 4].x,wall.z + wall.height,wall.points[(i + 1) % 4].y };
                p4 = { wall.points[i].x,wall.z + wall.height,wall.points[i].y };
                ClosestRayCollision(enemy.downRayCollision, GetRayCollisionQuad(downRay, p1, p2, p3, p4));
                ClosestRayCollision(enemy.targetRayCollision, GetRayCollisionQuad(targetRay, p1, p2, p3, p4));
            }
        }
        Vector3 p1 = { wall.points[0].x,wall.z,wall.points[0].y };
        Vector3 p2 = { wall.points[1].x,wall.z,wall.points[1].y };
        Vector3 p3 = { wall.points[2].x,wall.z,wall.points[2].y };
        Vector3 p4 = { wall.points[3].x,wall.z,wall.points[3].y };
        if (ClosestRayCollision(player.target, GetRayCollisionQuad(playerTargetRay, p1, p2, p3, p4))) {
            player.targetWall = &wall;
            wallHit = true;
        }

        p1 = { wall.points[0].x,wall.z + wall.height,wall.points[0].y };
        p2 = { wall.points[1].x,wall.z + wall.height,wall.points[1].y };
        p3 = { wall.points[2].x,wall.z + wall.height,wall.points[2].y };
        p4 = { wall.points[3].x,wall.z + wall.height,wall.points[3].y };
        if (ClosestRayCollision(player.target, GetRayCollisionQuad(playerTargetRay, p1, p2, p3, p4))) {
            player.targetWall = &wall;
            wallHit = true;
        }

        for (int i = 0; i < 4; i++) {
            p1 = { wall.points[i].x,wall.z,wall.points[i].y };
            p2 = { wall.points[(i + 1) % 4].x,wall.z,wall.points[(i + 1) % 4].y };
            p3 = { wall.points[(i + 1) % 4].x,wall.z + wall.height,wall.points[(i + 1) % 4].y };
            p4 = { wall.points[i].x,wall.z + wall.height,wall.points[i].y };
            if (ClosestRayCollision(player.target, GetRayCollisionQuad(playerTargetRay, p1, p2, p3, p4))) {
                player.targetWall = &wall;
                wallHit = true;
            }
        }
        wall.tickFunction(&wall);
    }
    if (!wallHit) {
        player.targetWall = nullptr;
    }
}

// Draw game level
static void DrawEntities(Camera camera) {
    const int floorExtent = 25;
    const float tileSize = 5.0f;
    const Color tileColor1 = { 150, 200, 200, 255 };

    // Floor tiles
    /*for (int y = -floorExtent; y < floorExtent; y++) {
        for (int x = -floorExtent; x < floorExtent; x++) {
            if ((y & 1) && (x & 1)) {
                DrawPlane({ x* tileSize, 0.0f, y* tileSize },{ tileSize, tileSize }, tileColor1);
            }
            else if (!(y & 1) && !(x & 1)) {
                DrawPlane({ x* tileSize, 0.0f, y* tileSize }, { tileSize, tileSize }, LIGHTGRAY);
            }
        }
    }*/

    /*if (player.target.hit) {
        DrawSphere(player.target.point, .5f, RED);
    }*/

    for (Projectile& ball : projectiles) {
        ball.draw();
    }

    for (Enemy& enemy : enemies) {
        //float midHeight = (enemy.body.getBoundingBox().max.y + enemy.body.getBoundingBox().min.y) / 2.0f;
        //if (!IsSoundPlaying(snd_step)) {
        //    SetSoundPosition(camera, snd_step, enemy.body.position, 20.0f);
        //    PlaySound(snd_step);
        //}
        //DrawRay(enemy.getDownRay(), RED);
        //DrawSphere(enemy.downRayCollision.point, 0.5f, RED);
        //enemy.drawBoundingBox();
        //DrawSphere(enemy.currentNode->point, 0.5f, GREEN);
        //DrawSphere(enemy.targetNode->point, 0.5f, RED);
        if (enemy.reachedTarget) {
            DrawBillboard(camera, TEX_JOHN_VICTORY, enemy.body.position + Vector3{ 0.0f,enemy.body.standingHeight / 2.0f,0.0f }, enemy.body.standingHeight, WHITE);
        }
        else if (enemy.body.getCrouchState()) {
            DrawBillboard(camera, TEX_NPC_JOHN_CROUCH, enemy.body.position + Vector3{ 0.0f,enemy.body.standingHeight / 2.0f,0.0f }, enemy.body.standingHeight, WHITE);
        }
        else {
            DrawBillboard(camera, TEX_NPC_JOHN, enemy.body.position + Vector3{ 0.0f,enemy.body.standingHeight / 2.0f,0.0f }, enemy.body.standingHeight, WHITE);
        }
    }

    /*const Vector3 towerSize = { 16.0f, 32.0f, 16.0f };
    const Color towerColor = { 150, 200, 200, 255 };

    Vector3 towerPos ={ 16.0f, 16.0f, 16.0f };
    DrawCubeV(towerPos, towerSize, towerColor);
    DrawCubeWiresV(towerPos, towerSize, DARKBLUE);

    towerPos.x *= -1;
    DrawCubeV(towerPos, towerSize, towerColor);
    DrawCubeWiresV(towerPos, towerSize, DARKBLUE);

    towerPos.z *= -1;
    DrawCubeV(towerPos, towerSize, towerColor);
    DrawCubeWiresV(towerPos, towerSize, DARKBLUE);

    towerPos.x *= -1;
    DrawCubeV(towerPos, towerSize, towerColor);
    DrawCubeWiresV(towerPos, towerSize, DARKBLUE);*/
}

int main() {
	// Init Window
	const int screenWidth = 1600;
	const int screenHeight = 900;
	
	SetConfigFlags(FLAG_MSAA_4X_HINT);

	InitWindow(screenWidth, screenHeight, "Evil Man Kill - Engine Demo");

	InitAudioDevice();

	DisableCursor();

	// Cap the FPS to 60
	SetTargetFPS(60);

	// Init Player
	player = { 0 };

	// Init player camera
	camera.fovy = 60.0f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.position = player.body.getHeadPos();

	UpdateCameraAngle(&camera, player);

	// Init enemies
#ifdef ENABLE_JOHNS
	for (int i = 0; i < 10; i++) {
		Enemy enemy;
		enemy.body.position = loadedMap->getRandomSpawnPoint();
		enemy.body.radius = 0.25f;
		enemy.body.dir = { 0 };
		enemy.body.movementSpeed = 15.0f;
		enemy.target = &player.body.position;
		enemies.push_back(enemy);
	}
#endif
	
	// Load assets
	LoadGlob();

    // Load Map
    loadedMap = &MAP_NOSTALGIA;

    // Init Map Nodes
    InitNodes();

	// Music toggle
	bool musicToggle = true;

	//PlayMusicStream(music_main);

	while (!WindowShouldClose()) {
		if (!player.body.alive && musicToggle) {
			StopMusicStream(music_main);
			PlayMusicStream(music_lose);
			musicToggle = false;
		}
		if (player.body.alive) {
			//UpdateMusicStream(music_main);
		}
		else {
			UpdateMusicStream(music_lose);
		}

		player.update();

		if (IsKeyPressed(KEY_F3)) debugEnabled = !debugEnabled;
		if (IsKeyPressed(KEY_R)) player = { 0 };
        if (IsKeyPressed(KEY_ONE)) {
            loadedMap = &MAP_NOSTALGIA;
            player = { 0 };
            UpdateCameraAngle(&camera, player);
        }
        if (IsKeyPressed(KEY_TWO)) {
            loadedMap = &MAP_EXAMPLE;
            player = { 0 };
            UpdateCameraAngle(&camera, player);
        }
        if (IsKeyPressed(KEY_THREE)) {
            loadedMap = &MAP_ABSTRACTIONS;
            player = { 0 };
            UpdateCameraAngle(&camera, player);
        }

		UpdateCameraAngle(&camera, player);

		UpdateLevel();

		BeginDrawing();

		ClearBackground(loadedMap->skyColor);

		BeginMode3D(camera);

		SetShaderValue(shader_main, shader_main_viewpos_loc, &camera.position, RL_SHADER_UNIFORM_VEC3);
		SetShaderValue(shader_main, shader_main_viewtarget_loc, &camera.target, RL_SHADER_UNIFORM_VEC3);
		BeginShaderMode(shader_main);

        loadedMap->draw();
		DrawEntities(camera);

		EndShaderMode();
		DrawCircle3D(player.body.position, player.body.radius, { 1.0f, 0.0f, 0.0f }, 90.0f, GRAY); // Draw player as a circle on the ground
		EndMode3D();

		DrawCircle(screenWidth / 2, screenHeight / 2, 3.0f, GRAY);
		player.drawScreen();

        if (startscreen) {
            DrawRectangle(0, 0, screenWidth, screenHeight, { 255,255,255,255 });
            const char* text1 = "Token Collector Demo";
            int text1Width = MeasureText(text1, 40);
            DrawText(text1, screenWidth / 2 - text1Width / 2, screenHeight / 2 - 30, 40, BLACK);

            const char* text2 = "Find 8 tokens through out the 3 maps currently in the game.\n";
            int text2Width = MeasureText(text2, 20);
            DrawText(text2, screenWidth / 2 - text2Width / 2, screenHeight / 2 + 20, 20, BLACK);

            const char* text3 = "Press 1,2,3 to change maps\n";
            int text3Width = MeasureText(text3, 20);
            DrawText(text3, screenWidth / 2 - text3Width / 2, screenHeight / 2 + 40, 20, BLACK);

            const char* text4 = "There is a token hidden behind a door in one of the maps, press 'e' to open the door\n";
            int text4Width = MeasureText(text4, 20);
            DrawText(text4, screenWidth / 2 - text4Width / 2, screenHeight / 2 + 60, 20, BLACK);

            const char* text5 = "Press 'enter' to continue\n";
            int text5Width = MeasureText(text5, 20);
            DrawText(text5, screenWidth / 2 - text5Width / 2, screenHeight / 2 + 100, 20, BLACK);

            if (IsKeyPressed(KEY_ENTER)) {
                startscreen = false;
            }
        }
        else if (score < 8) {
            if (debugEnabled) {
                AddDebugLine("FPS: %i", GetFPS(), true);
                AddDebugLine("Player Position: %f, %f, %f", player.body.position);
                AddDebugLine("Player Velocity: %f, %f, %f", player.body.velocity);
                AddDebugLine("Player Speed: %.2f", Vector3Length(player.body.velocity));
                AddDebugLine("Player Look Rotation: %.2f, %.2f", player.body.lookRotation);
                AddDebugLine(TextFormat("Player Touching Ceiling: %i", player.body.isTouchingCeiling));
                AddDebugLine(TextFormat("Player OnGround: %i", player.body.isGrounded));
                AddDebugLine("Player Height: %.2f", player.body.getHeight());
                AddDebugLine("Player Equipped: %s", player.equipped.name);
            }

            if (!player.body.alive) {
                DrawRectangle(0, 0, screenWidth, screenHeight, { 255,0,0,120 });
                const char* text = "You're Dead!!!!!!!!";
                int textWidth = MeasureText(text, 40);
                DrawText(text, screenWidth / 2 - textWidth / 2, screenHeight / 2 - 30, 40, WHITE);

                const char* scoreText = TextFormat("Score: %i", score);
                int scoreWidth = MeasureText(scoreText, 20);
                DrawText(scoreText, screenWidth / 2 - scoreWidth / 2, screenHeight / 2 + 20, 20, WHITE);

                const char* respawn = TextFormat("Press 'r' to respawn", score);
                int respawnWidth = MeasureText(respawn, 20);
                DrawText(respawn, screenWidth / 2 - respawnWidth / 2, screenHeight / 2 + 60, 20, WHITE);
            }
            else {
                if (!debugEnabled) {
                    DrawText(TextFormat("Tokens collected: %i / 8", score), 5, 5, 20, (loadedMap == &MAP_ABSTRACTIONS ? BLACK : WHITE));
                    int numOfTokens;
                    if (loadedMap == &MAP_ABSTRACTIONS) numOfTokens = 1;
                    if (loadedMap == &MAP_EXAMPLE) numOfTokens = 4;
                    if (loadedMap == &MAP_NOSTALGIA) numOfTokens = 3;
                    DrawText(TextFormat("Tokens on this map: %i", numOfTokens), 5, 25, 20, (loadedMap == &MAP_ABSTRACTIONS ? BLACK : WHITE));
                }
            }
        }
        else {
            DrawRectangle(0, 0, screenWidth, screenHeight, { 0,255,0,120 });
            const char* text = "You have collected all tokens!";
            int textWidth = MeasureText(text, 40);
            DrawText(text, screenWidth / 2 - textWidth / 2, screenHeight / 2 - 30, 40, GREEN);

            const char* subtext = "That's all there is to this demo";
            int subtextWidth = MeasureText(subtext, 20);
            DrawText(subtext, screenWidth / 2 - subtextWidth / 2, screenHeight / 2 + 20, 20, GREEN);
        }

		EndDrawing();
	}

	UnloadGlob();

	CloseAudioDevice();

	CloseWindow();

	return 0;
}