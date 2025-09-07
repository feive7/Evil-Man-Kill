#pragma once
class Projectile {
public:
    Vector3 position;
    Vector3 velocity;
    float radius = 0.1f;
    bool alive = true;
    void update() {
        position += velocity;
        velocity.y -= 0.01f;
        if (position.y < 0 || Vector3Length(position) > 1000) {
            alive = false;
        }
    }
    BoundingBox getBoundingBox() {
        return {
            Vector3Subtract(position,{radius,radius,radius}),
            Vector3Add(position,{radius,radius,radius}),
        };
    }
    void draw() {
        DrawSphere(position, radius, BLACK);
    }
};
static std::vector<Projectile> projectiles;