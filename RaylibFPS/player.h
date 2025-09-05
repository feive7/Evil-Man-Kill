#pragma once

#define GRAVITY         32.0f
#define MAX_SPEED       20.0f
#define CROUCH_SPEED     5.0f
#define JUMP_FORCE      12.0f
#define MAX_ACCEL      150.0f
// Grounded drag
#define FRICTION         0.86f
// Increasing air drag, increases strafing speed
#define AIR_DRAG         0.98f
// Responsiveness for turning movement direction to looked direction
#define CONTROL         15.0f
#define CROUCH_HEIGHT    0.75f
#define STAND_HEIGHT     2.0f
#define BOTTOM_HEIGHT    0.5f
#define HEAD_OFFSET      0.5f // How far down the head is from height
#define STEP_HEIGHT      0.5f // How far the player can tp to the top of a wall

#define INTERACT_DISTANCE 3.0f

#define NORMALIZE_INPUT  0

static Vector2 sensitivity = { 0.005f, 0.005f };
static int score = 0;


static void SetSoundPosition(Camera listener, Sound sound, Vector3 position, float maxDist) {
    // Calculate direction vector and distance between listener and sound source
    Vector3 direction = Vector3Subtract(position, listener.position);
    float distance = Vector3Length(direction);

    // Apply logarithmic distance attenuation and clamp between 0-1
    float attenuation = 1.0f / (1.0f + (distance / maxDist));
    attenuation = Clamp(attenuation, 0.0f, 1.0f);

    // Calculate normalized vectors for spatial positioning
    Vector3 normalizedDirection = Vector3Normalize(direction);
    Vector3 forward = Vector3Normalize(Vector3Subtract(listener.target, listener.position));
    Vector3 right = Vector3Normalize(Vector3CrossProduct(listener.up, forward));

    // Reduce volume for sounds behind the listener
    float dotProduct = Vector3DotProduct(forward, normalizedDirection);
    if (dotProduct < 0.0f) attenuation *= (1.0f + dotProduct * 0.5f);

    // Set stereo panning based on sound position relative to listener
    float pan = 0.5f + 0.5f * Vector3DotProduct(normalizedDirection, right);

    // Apply final sound properties
    SetSoundVolume(sound, 1.0f / distance);
    SetSoundPan(sound, pan);
}
inline bool FuzzyLess(float a, float b, float thresh = 1.0f) {
    return a < b + thresh;
}
inline bool FuzzyGreater(float a, float b, float thresh = 1.0f) {
    return a > b - thresh;
}
inline bool FeatherEqual(float a, float b, float thresh = 1.0f) {
    return FuzzyLess(a, b, thresh) && FuzzyGreater(a, b, thresh);
}

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
class Body {
public:
    Vector3 position = { 0 };
    Vector3 velocity = { 0 };
    Vector3 dir = { 0 };
    float movementSpeed = 20.0f;
    float friction = FRICTION;
    bool isGrounded = true;
    bool isClimbing = false;
    bool isTouchingWall = false;
    bool isTouchingCeiling = false;

    Wall* groundWall; // Wall that the body last stood on
    Wall* wallTouching; // Wall the body last collided with horizontally

    float heightLerp = 1.0f;
    float standingHeight = 2.0f;
    float crouchingHeight = 1.0f;
    bool crouching = false;

    bool alive = true;

    float radius = 1.0f;

    Vector2 lookRotation = { PI, 0.0f };

    // Get forward direction as Vector3
    Vector3 getForward() {
        float yaw = lookRotation.x;
        float pitch = lookRotation.y;

        Vector3 forward;
        forward.x = -sinf(yaw) * cosf(pitch);
        forward.y = -sinf(pitch);
        forward.z = -cosf(yaw) * cosf(pitch);

        return Vector3Normalize(forward);
    }
    // Get current total height
    float getHeight() {
        return Lerp(crouchingHeight, standingHeight, heightLerp);
    }
    // Get real crouch state (for speed purposes)
    bool getCrouchState() {
        return getHeight() < standingHeight;
    }
    // Get Head position (factors in head offset)
    Vector3 getHeadPos() {
        return position + Vector3{ 0,getHeight() - HEAD_OFFSET,0};
    }
    // Request jump
    void jump() {
        if (isGrounded && !isTouchingCeiling) {
            velocity.y = JUMP_FORCE;
            isGrounded = false;
            //SetSoundPosition(camera, snd_step, position, 20.0f);
            //PlaySound(snd_step);
        }
    }
    // Set movement intention (Only enemies use this as player has their own movement function)
    void move(Vector3 direction) {
        float delta = GetFrameTime();

        Vector3 desiredDir = Vector3ClampValue(direction, 0, 1);
        dir = Vector3Lerp(dir, desiredDir, CONTROL * delta);

        float decel = (isGrounded ? friction : AIR_DRAG);
        Vector3 hvel = { velocity.x, 0.0f, velocity.z };

        float hvelLength = Vector3Length(hvel); // Magnitude
        if (hvelLength < (movementSpeed * 0.01f)) hvel = { 0 };

        // This is what creates strafing
        float speed = Vector3DotProduct(hvel, dir);

        float maxSpeed = (getCrouchState() ? CROUCH_SPEED : movementSpeed);
        float accel = Clamp(maxSpeed - speed, 0.f, MAX_ACCEL * delta);
        hvel.x += dir.x * accel;
        hvel.z += dir.z * accel;

        velocity.x = hvel.x * decel;
        velocity.z = hvel.z * decel;
    }
    // Apply movement intention with collisions
    void tryMove() {
        float delta = GetFrameTime();
        Vector3 newpos = position + Vector3Scale(velocity, delta);
        Vector3 newvel = velocity;
        float newHeightLerp = Lerp(heightLerp, (crouching ? CROUCH_HEIGHT : standingHeight), 20.0f * delta);
        float newHeight = Lerp(crouchingHeight, standingHeight, newHeightLerp);
        float height = getHeight();

        bool grounded = false;
        float bouncePower = 0.0f;
        isClimbing = false;
        isTouchingWall = false;
        isTouchingCeiling = false;

        for (Wall& wall : testmap.walls) {
            for (int i = 0; i < 4; i++) {
                Sector sect = { wall.points[i],wall.points[(i + 1) % 4] };
                float lineDist = sect.distanceToPoint({ newpos.x,newpos.z });
                if (lineDist < radius && position.y + height > wall.z && position.y < wall.z + wall.height ) {
                    float cDist = (radius - lineDist) * lineSide({ newpos.x,newpos.z }, sect.p1, sect.p2); // Distance into the wall
                    Vector2 normal = sect.getNormal();
                    newpos.x += normal.x * cDist;
                    newpos.z += normal.y * cDist;
                    if (newpos.y >= wall.z + wall.height - STEP_HEIGHT && isGrounded) {
                        newpos.y = wall.z + wall.height;
                    }
                    else if (wall.surfaceMaterial == SURFACE_BOUNCY) {
                        newvel.x = -newvel.x;
                        newvel.z = -newvel.y;
                    }
                    else if (wall.surfaceMaterial == SURFACE_LADDER) {
                        Vector2 velocityClip = ClipVelocityAgainstNormal({ newvel.x,newvel.z }, normal, true);
                        newvel.x = 0;
                        newvel.z = 0;
                        newvel.y = 4.0f;
                    }
                    else {
                        Vector2 velocityClip = ClipVelocityAgainstNormal({ newvel.x,newvel.z }, normal, true);
                        newvel.x = velocityClip.x;
                        newvel.z = velocityClip.y;
                    }
                    touchWall(wall);
                    wallTouching = &wall;
                    isTouchingWall = true;
                    wall.touching = true;
                }
            }
            if (CheckCollisionCircleQuad({ newpos.x,newpos.z }, radius, wall.points[0], wall.points[1], wall.points[2], wall.points[3])) { // Checking vertical collisions
                if (newpos.y <= wall.z + wall.height && newpos.y > wall.z + wall.height - 1.0f && velocity.y <= 0) { // Hit top of wall
                    newpos.y = wall.z + wall.height;
                    newpos += wall.deltaMovement;
                    grounded = true;
                    groundWall = &wall;
                    
                    if (wall.surfaceMaterial == SURFACE_BOUNCY) {
                        newvel.y = -newvel.y;
                    }
                    else if (wall.surfaceMaterial == SURFACE_ICE) {
                        friction = 1.0f;
                    }
                    else {
                        friction = FRICTION;
                        newvel.y = 0.0f;
                    }
                    touchWall(wall);
                    wall.touching = true;
                }
                else if (newpos.y + newHeight > wall.z && newpos.y + newHeight < wall.z + 1.0f) { // Hit bottom of wall
                    newvel.y = 0.0f;
                    if (!grounded) {
                        newpos.y = wall.z - height;
                    }
                    isTouchingCeiling = true;
                    touchWall(wall);
                    wall.touching = true;
                }
            }
        }
        if (!isTouchingCeiling) {
            heightLerp = newHeightLerp;
        }
        if (grounded && !isGrounded) { // Body just landed so we play a sound
            //SetSoundPosition(camera, snd_step, position, 20.0f);
            //PlaySound(snd_land);
        }
        
        isGrounded = grounded;
        velocity = newvel;
        position = newpos;
    }
    // Apply all passive movements (gravity, climbing, etc)
    void update() {
        float delta = GetFrameTime();
        if (!isGrounded && !isClimbing) velocity.y -= GRAVITY * delta;
        if (isClimbing) velocity.y = 0.0f;
        tryMove();
    }
    // Returns body bounding box
    BoundingBox getBoundingBox() {
        return {
            Vector3Subtract(position,{0.5f,0.0f,0.5f}),
            Vector3Add(getHeadPos(),{0.5f,0.0f,0.5f}),
        };
    }
private:
    // Trigger wall effect
    void touchWall(Wall& wall) {
        switch (wall.surfaceMaterial) {
        case SURFACE_REGULAR: break;
        case SURFACE_LAVA: alive = false; break;
        }
    }
};
class Player {
public:
    Body body;
    Item equipped = item_drumstick;
    float headTimer = 0.0f;
    float walkLerp = 0.0f;
    bool noclipping = false;
    Vector2 lean = { 0 };
    RayCollision target = { 0 };
    Wall* targetWall = nullptr;
    Vector2 screenLean = { 0.0f,0.0f };

    int deathTick = 0;
    // Get ray from player head through player direction vector
    Ray getForwardRay() {
        return { body.getHeadPos(), body.getForward() };
    }
    // Handle player inputs and other states
    void update() {
        if (body.alive) {
            if (IsKeyPressed(KEY_V)) noclipping = !noclipping;
            if (IsKeyPressed(KEY_K)) body.alive = false;
            if (IsKeyPressed(KEY_E)) {
                if (target.hit && targetWall != nullptr && target.distance <= INTERACT_DISTANCE) {
                    targetWall->interact = true;
                }
            }
            updateLookRotation();
            updateScreenLean();
            if (noclipping) {
                body.velocity = { 0.0f,0.0f,0.0f };
                noclip();
            }
            else {
                if (IsKeyPressed(KEY_SPACE)) body.jump();
                body.crouching = IsKeyDown(KEY_LEFT_CONTROL);
                move();
                body.update();
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                projectiles.push_back({ body.getHeadPos(),body.getForward() });
                PlaySound(snd_gunshot);
            }
        }
        else {
            deathTick++;
        }
    }
    // Draw 2D stuff on the screen like items
    void drawScreen() {
        float SW = (float)GetScreenWidth();
        float SH = (float)GetScreenHeight();
        float scale = (float)GetScreenHeight() / equipped.texture->height;
        DrawTextureEx(*equipped.texture, { SW - equipped.texture->width * scale + screenLean.x, 0.0f + screenLean.y }, 0.0f, scale, WHITE);
    }
private:
    // Update lean for drawing items
    void updateScreenLean() {
        Vector2 newLean = { 0 };
        
        Vector2 vel2D = { body.velocity.x, body.velocity.z };
        vel2D = Vector2Rotate(vel2D, body.lookRotation.x);

        newLean.x = -vel2D.x;
        newLean.y = body.velocity.y;
        newLean.y = Clamp(newLean.y, -50.0f, 50.0f);
        newLean.y += 50.0f;

        screenLean = Vector2Lerp(newLean, screenLean, 0.5f);
    }
    // Update look rotation based on mouse inputs
    void updateLookRotation() {
        // Get mouse inputs
        Vector2 mouse_delta = GetMouseDelta();
        body.lookRotation.x -= mouse_delta.x * sensitivity.x;
        body.lookRotation.y += mouse_delta.y * sensitivity.y;
        const Vector3 targetOffset = { 0.0f, 0.0f, -1.0f };

        const Vector3 up = { 0.0f, 1.0f, 0.0f };
        Vector3 yaw = Vector3RotateByAxisAngle(targetOffset, up, body.lookRotation.x);

        // Clamp view up
        float maxAngleUp = Vector3Angle(up, yaw);
        maxAngleUp -= 0.001f; // Avoid numerical errors

        // Clamp view down
        float maxAngleDown = Vector3Angle(Vector3Negate(up), yaw);
        maxAngleDown *= -1.0f; // Downwards angle is negative
        maxAngleDown += 0.001f; // Avoid numerical errors

        body.lookRotation.y = Clamp(body.lookRotation.y, maxAngleDown, maxAngleUp);
    }
    // Fly with disregard for collisions
    void noclip() {
        char sideway = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
        char forward = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
        char vertical = (IsKeyDown(KEY_SPACE) - IsKeyDown(KEY_LEFT_CONTROL));

        float speed = 0.2f;

        Quaternion qLook = QuaternionFromEuler(-body.lookRotation.y, body.lookRotation.x, 0.0f);
        Vector3 movement = Vector3RotateByQuaternion({ (float) sideway,(float)vertical,(float)-forward}, qLook);

        body.position += Vector3Scale(movement,speed);
    }
    // Player custom movement
    void move() {
        // Get keyboard inputs
        bool jumpPressed = IsKeyPressed(KEY_SPACE);
        char sideway = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
        char forward = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));

        Vector2 input = { (float)sideway, (float)-forward };

#if defined(NORMALIZE_INPUT)
        // Slow down diagonal movement
        if ((sideway != 0) && (forward != 0)) input = Vector2Normalize(input);
#endif

        float delta = GetFrameTime();

        // Basis vectors from look rotation
        Vector3 front = { sinf(body.lookRotation.x), 0.f, cosf(body.lookRotation.x) };
        Vector3 right = { cosf(-body.lookRotation.x), 0.f, sinf(-body.lookRotation.x) };

        // Desired movement direction
        Vector3 desiredDir = {
            input.x * right.x + input.y * front.x,
            0.0f,
            input.x * right.z + input.y * front.z
        };

        // Smooth direction using time-independent exponential smoothing
        float dirLerp = 1.0f - expf(-CONTROL * delta);
        if (dirLerp < 0.0001f) dirLerp = 0.0001f;
        body.dir = Vector3Lerp(body.dir, desiredDir, dirLerp);

        // Friction / drag as exponential decay
        float factor = (body.isGrounded ? body.friction : AIR_DRAG);
        float decel = powf(factor, fmaxf(delta * 60.0f, 0.001f));
        Vector3 hvel = { body.velocity.x * decel, 0.0f, body.velocity.z * decel };

        // Kill tiny velocities
        float hvelLength = Vector3Length(hvel);
        if (hvelLength < (body.movementSpeed * 0.00001f)) hvel = { 0 };

        // Strafing math
        float speed = Vector3DotProduct(hvel, body.dir);

        // Accelerate toward max speed
        float maxSpeed = (body.getCrouchState() ? CROUCH_SPEED : body.movementSpeed);
        float accelRate = MAX_ACCEL;
        float accel = Clamp(maxSpeed - speed, 0.f, accelRate * delta);
        hvel.x += body.dir.x * accel;
        hvel.z += body.dir.z * accel;

        // Apply to velocity
        body.velocity.x = hvel.x;
        body.velocity.z = hvel.z;

        // Head bobbing
        if (body.isGrounded && ((forward != 0) || (sideway != 0))) {
            headTimer += delta * 3.0f;
            walkLerp = Lerp(walkLerp, 1.0f, 10.0f * delta);
        }
        else {
            walkLerp = Lerp(walkLerp, 0.0f, 10.0f * delta);
        }

        // Leaning
        lean.x = Lerp(lean.x, sideway * 0.02f, 10.0f * delta);
        lean.y = Lerp(lean.y, forward * 0.015f, 10.0f * delta);
    }

    // Wrap player position
    void warp(Vector3 bounds) {
        body.position.x = fmod(body.position.x, bounds.x);
        body.position.y = fmod(body.position.y, bounds.y);
        body.position.z = fmod(body.position.z, bounds.z);
    }
};

static Player player;

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
            if (path.size() > 1 && Vector3Distance(targetRayCollision.point,*target) > 2.0f) {
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
    for (Wall& wall : testmap.walls) {
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
        if(ClosestRayCollision(player.target, GetRayCollisionQuad(playerTargetRay, p1, p2, p3, p4))) {
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