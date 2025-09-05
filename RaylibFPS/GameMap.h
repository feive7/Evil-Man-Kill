#pragma once
#include <thing.h>
#include <collisions.h>
struct GameMap {
    Color skyColor;
    std::vector<Wall> walls;
    std::vector<Thing> things;
    void draw() {
        rlBegin(RL_QUADS);
        for (Wall wall : walls) {
            rlSetTexture(wall.texture->id);
            wall.draw();
        }
        rlEnd();
        for (const Thing thing : things) {
            DrawBillboard(camera, *thing.texture, thing.position + Vector3{0.0f,thing.size/2.0f,0.0f}, thing.size, WHITE);
        }

        rlSetTexture(0);
    }
    RayCollision castRay(Ray ray) {
        RayCollision result = { 0 };
        for (Wall& wall : walls) {
            Vector3 p1 = { wall.points[0].x,wall.z,wall.points[0].y };
            Vector3 p2 = { wall.points[1].x,wall.z,wall.points[1].y };
            Vector3 p3 = { wall.points[2].x,wall.z,wall.points[2].y };
            Vector3 p4 = { wall.points[3].x,wall.z,wall.points[3].y };
            RayCollision col = GetRayCollisionQuad(ray, p1, p2, p3, p4);
            if (col.hit && (!result.hit || col.distance < result.distance)) {
                result = col;
            }

            p1 = { wall.points[0].x,wall.z + wall.height,wall.points[0].y };
            p2 = { wall.points[1].x,wall.z + wall.height,wall.points[1].y };
            p3 = { wall.points[2].x,wall.z + wall.height,wall.points[2].y };
            p4 = { wall.points[3].x,wall.z + wall.height,wall.points[3].y };
            col = GetRayCollisionQuad(ray, p1, p2, p3, p4);
            if (col.hit && (!result.hit || col.distance < result.distance)) {
                result = col;
            }

            for (int i = 0; i < 4; i++) {
                p1 = { wall.points[i].x,wall.z,wall.points[i].y };
                p2 = { wall.points[(i + 1) % 4].x,wall.z,wall.points[(i + 1) % 4].y };
                p3 = { wall.points[(i + 1) % 4].x,wall.z + wall.height,wall.points[(i + 1) % 4].y };
                p4 = { wall.points[i].x,wall.z + wall.height,wall.points[i].y };
                col = GetRayCollisionQuad(ray, p1, p2, p3, p4);
                if (col.hit && (!result.hit || col.distance < result.distance)) {
                    result = col;
                }
            }
        }
        return result;
    }
    void update() {
        float delta = GetFrameTime();
        for (auto wallIt = walls.begin(); wallIt != walls.end(); wallIt++) {
            Wall& wall = *wallIt;
            wall.tickFunction(&wall);
            //wall.move(wall.deltaMovement);
        }
    }
    Vector3 getRandomSpawnPoint() {
        std::vector<Vector3> options;
        for (Wall& wall : walls) {
            if (wall.canSpawn) {
                Vector2 point = wall.center();
                options.push_back({ point.x,wall.z + wall.height,point.y });
            }
        }
        if (options.size() == 0) options.push_back({ 0,0,0 });
        int idx = GetRandomValue(0, options.size() - 1);
        return options[idx] + Vector3{ GetRandomValue(-100,100) / 100.0f,0.0f,GetRandomValue(-100,100) / 100.0f };
    }
};