#pragma once

class Player {
public:
    Body body;
    Item equipped = item_drumstick;
    float headTimer = 0.0f;
    float walkLerp = 0.0f;
    bool noclipping = false;
    Vector2 lean = { 0 };
    RayCollision mapTarget = { 0 };
    RayCollision entityTarget = { 0 };
    Wall* targetWall = nullptr;
    Body* targetBody = nullptr;
    Vector2 screenLean = { 0.0f,0.0f };
    bool attacking = false;

    int deathTick = 0;
    // Get ray from player head through player direction vector
    Ray getForwardRay() {
        return { body.getHeadPos(), body.getForward() };
    }
    // Get if the player is targeting a body and it's within sufficient distance
    bool isTargeting() {
        return targetBody != nullptr && entityTarget.distance < 4.0f;
    }
    // Handle player inputs and other states
    void update() {
        if (body.alive) {
            if (IsKeyPressed(KEY_V)) noclipping = !noclipping;
            if (IsKeyPressed(KEY_K)) body.alive = false;
            if (IsKeyPressed(KEY_E)) {
                if (mapTarget.hit && targetWall != nullptr && mapTarget.distance <= INTERACT_DISTANCE) {
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
                attacking = true;
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