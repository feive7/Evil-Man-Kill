#pragma once
class Enemy {
public:
    Body body = { 0 };
    Vector3* target = { 0 };
    bool reachedTarget = false;

    RayCollision downRayCollision = { 0 };
    RayCollision targetRayCollision = { 0 };

    float walkTimer = 0.0f;
    float standHeight = STAND_HEIGHT;

    Node* currentNode = nullptr;
    Node* targetNode = nullptr;
    std::vector<Node*> path;
    int currentPath = 0;

    // Get ray from head down
    Ray getDownRay() {
        return { body.getHeadPos(), {0.0f,-1.0f,0.0f} };
    }
    // Get ray from head up
    Ray getTargetRay() {
        return { body.getHeadPos(), *target - body.getHeadPos() };
    }
    // Update reachedTarget state
    void checkForTarget() {
        if (Vector3Distance(body.position, *target) < 1) {
            reachedTarget = true;
        }
    }
    // Old AI mover
    void stupidPathFind() {
        bool overGround = downRayCollision.hit && downRayCollision.distance < 10; // Is above a ground
        bool inAir = !body.isGrounded; // Is in air
        if (overGround && inAir) { // above ground
            // stop moving to land on ground
            stopMove();
        }
        if (overGround && !inAir) { // on ground
            moveToTarget();
        }
        if (!overGround && !inAir && body.position.y <= target->y) {
            body.jump();
        }
        if (body.isTouchingWall && body.wallTouching != nullptr) {
            if (body.position.y < body.wallTouching->z) {
                body.crouching = true;
            }
            else if (body.wallTouching->z < body.position.y - 1.0f) {
                body.jump();
            }
        }
        else {
            body.crouching = false;
        }
    }
    // New AI pathfinding using map nodes
    void smartPathFind() {
        currentNode = FindClosestNode(body.position);
        targetNode = FindClosestNode(*target);
        path = bfs(currentNode, targetNode);
    }
    // Enemy tick function
    void update() {
        if (currentNode == nullptr) {
            currentNode = FindClosestNode(body.position);
            targetNode = FindClosestNode(*target);
            smartPathFind(); // fills path
        }

        if (!reachedTarget) {
            if (path.size() > 1 && Vector3Distance(targetRayCollision.point, *target) > 2.0f) {
                Vector3 targetPos = path[1]->point;
                body.move(targetPos - body.position);
                if (Vector3Distance(targetPos, body.position) < 2.0f) {
                    smartPathFind();
                }
            }
            else {
                stupidPathFind();
            }
        }
        else {
            body.velocity.x = 0.0f;
            body.velocity.z = 0.0f;
        }

        body.update();
        downRayCollision = { 0 };
        targetRayCollision = { 0 };
    }

    // Draw bounding box wires
    void drawBoundingBox() {
        DrawBoundingBox(body.getBoundingBox(), BLACK);
    }
private:
    // Move towards target
    void moveToTarget() {
        body.move(*target - body.position);
    }
    // Move opposite to velocity
    void stopMove() {
        body.move(Vector3Negate(body.velocity));
    }
};

static std::vector<Enemy> enemies;