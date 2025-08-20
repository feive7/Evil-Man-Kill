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
#define CROUCH_HEIGHT    0.0f
#define STAND_HEIGHT     1.0f
#define BOTTOM_HEIGHT    0.5f

#define NORMALIZE_INPUT  0

static Vector2 sensitivity = { 0.005f, 0.005f };
static std::vector<Ball> projectiles;

class Body {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 dir;
    bool isGrounded;

    bool crouching;

    Vector2 lookRotation;
    float headTimer;
    float walkLerp;
    float headLerp;
    Vector2 lean;

    Vector3 getForward() {
        float yaw = lookRotation.x;
        float pitch = lookRotation.y;

        Vector3 forward;
        forward.x = -sinf(yaw) * cosf(pitch);
        forward.y = -sinf(pitch);
        forward.z = -cosf(yaw) * cosf(pitch);

        return Vector3Normalize(forward);
    }

    Vector3 getHeadPos() {
        return position + Vector3{ 0,BOTTOM_HEIGHT + headLerp };
    }

    void update() {
        updateLookRotation();
        move();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            projectiles.push_back({ getHeadPos(),getForward() });
        }
        //warp({ 10,10,10 });
    }
    
    
private:
    void updateLookRotation() {
        // Get mouse inputs
        Vector2 mouse_delta = GetMouseDelta();
        lookRotation.x -= mouse_delta.x * sensitivity.x;
        lookRotation.y += mouse_delta.y * sensitivity.y;
        const Vector3 targetOffset = { 0.0f, 0.0f, -1.0f };

        const Vector3 up = { 0.0f, 1.0f, 0.0f };
        Vector3 yaw = Vector3RotateByAxisAngle(targetOffset, up, lookRotation.x);

        // Clamp view up
        float maxAngleUp = Vector3Angle(up, yaw);
        maxAngleUp -= 0.001f; // Avoid numerical errors
        if (-(lookRotation.y) > maxAngleUp) { lookRotation.y = -maxAngleUp; }

        // Clamp view down
        float maxAngleDown = Vector3Angle(Vector3Negate(up), yaw);
        maxAngleDown *= -1.0f; // Downwards angle is negative
        maxAngleDown += 0.001f; // Avoid numerical errors
        if (-(lookRotation.y) < maxAngleDown) { lookRotation.y = -maxAngleDown; }
    }
    void move() {
        // Get keyboard inputs
        bool jumpPressed = IsKeyPressed(KEY_SPACE);
        char sideway = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
        char forward = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
        crouching = IsKeyDown(KEY_LEFT_CONTROL);

        Vector2 input = { (float)sideway, (float)-forward };

        #if defined(NORMALIZE_INPUT)
        // Slow down diagonal movement
        if ((sideway != 0) && (forward != 0)) input = Vector2Normalize(input);
        #endif

        float delta = GetFrameTime();

        if (!isGrounded) velocity.y -= GRAVITY * delta;

        if (isGrounded && jumpPressed) {
            velocity.y = JUMP_FORCE;
            isGrounded = false;

            // Sound can be played at this moment
            //SetSoundPitch(fxJump, 1.0f + (GetRandomValue(-100, 100)*0.001));
            //PlaySound(fxJump);
        }

        Vector3 front = { sin(lookRotation.x), 0.f, cos(lookRotation.x) };
        Vector3 right = { cos(-lookRotation.x), 0.f, sin(-lookRotation.x) };

        Vector3 desiredDir = { input.x * right.x + input.y * front.x, 0.0f, input.x * right.z + input.y * front.z, };
        dir = Vector3Lerp(dir, desiredDir, CONTROL * delta);

        float decel = (isGrounded ? FRICTION : AIR_DRAG);
        Vector3 hvel = { velocity.x * decel, 0.0f, velocity.z * decel };

        float hvelLength = Vector3Length(hvel); // Magnitude
        if (hvelLength < (MAX_SPEED * 0.01f)) hvel = { 0 };

        // This is what creates strafing
        float speed = Vector3DotProduct(hvel, dir);

        // Whenever the amount of acceleration to add is clamped by the maximum acceleration constant,
        // a Player can make the speed faster by bringing the direction closer to horizontal velocity angle
        // More info here: https://youtu.be/v3zT3Z5apaM?t=165
        float maxSpeed = (crouching ? CROUCH_SPEED : MAX_SPEED);
        float accel = Clamp(maxSpeed - speed, 0.f, MAX_ACCEL * delta);
        hvel.x += dir.x * accel;
        hvel.z += dir.z * accel;

        velocity.x = hvel.x;
        velocity.z = hvel.z;

        position.x += velocity.x * delta;
        position.y += velocity.y * delta;
        position.z += velocity.z * delta;

        // Fancy collision system against the floor
        if (position.y <= 0.0f) {
            position.y = 0.0f;
            velocity.y = 0.0f;
            isGrounded = true; // Enable jumping
        }

        headLerp = Lerp(headLerp, (crouching ? CROUCH_HEIGHT : STAND_HEIGHT), 20.0f * delta);

        if (isGrounded && ((forward != 0) || (sideway != 0))) {
            headTimer += delta * 3.0f;
            walkLerp = Lerp(walkLerp, 1.0f, 10.0f * delta);
        }
        else {
            walkLerp = Lerp(walkLerp, 0.0f, 10.0f * delta);
        }

        lean.x = Lerp(lean.x, sideway * 0.02f, 10.0f * delta);
        lean.y = Lerp(lean.y, forward * 0.015f, 10.0f * delta);
    }
    void warp(Vector3 bounds) {
        position.x = fmod(position.x, bounds.x);
        position.y = fmod(position.y, bounds.y);
        position.z = fmod(position.z, bounds.z);
    }
};

// Update camera
static void UpdateCameraAngle(Camera* camera, Body cameraBody) {
    float delta = GetFrameTime();
    
    const Vector3 up = { 0.0f, 1.0f, 0.0f };
    const Vector3 targetOffset = { 0.0f, 0.0f, -1.0f };

    // Left and right
    Vector3 yaw = Vector3RotateByAxisAngle(targetOffset, up, cameraBody.lookRotation.x);

    

    // Up and down
    Vector3 right = Vector3Normalize(Vector3CrossProduct(yaw, up));

    // Rotate view vector around right axis
    Vector3 pitch = Vector3RotateByAxisAngle(yaw, right, -cameraBody.lookRotation.y - cameraBody.lean.y);

    // Update camera based on body state
    if (cameraBody.crouching) {
        camera->fovy = Lerp(camera->fovy, 55.0f, 5.0f * delta);

    }
    else {
        camera->fovy = Lerp(camera->fovy, 60.0f, 5.0f * delta);
    }


    // Head animation
    // Rotate up direction around forward axis
    float headSin = sin(cameraBody.headTimer * PI);
    float headCos = cos(cameraBody.headTimer * PI);
    const float stepRotation = 0.01f;
    camera->up = Vector3RotateByAxisAngle(up, pitch, headSin * stepRotation + cameraBody.lean.x);

    // Camera BOB
    const float bobSide = 0.1f;
    const float bobUp = 0.15f;
    Vector3 bobbing = Vector3Scale(right, headSin * bobSide);
    bobbing.y = fabsf(headCos * bobUp);

    camera->position = Vector3Add(camera->position, Vector3Scale(bobbing, cameraBody.walkLerp));
    camera->target = Vector3Add(camera->position, pitch);
}

// Update game level
static void UpdateLevel(void) {
    for (Ball& ball : projectiles) {
        ball.update();
    }
}

// Draw game level
static void DrawLevel(void) {
    const int floorExtent = 25;
    const float tileSize = 5.0f;
    const Color tileColor1 = { 150, 200, 200, 255 };

    // Floor tiles
    for (int y = -floorExtent; y < floorExtent; y++) {
        for (int x = -floorExtent; x < floorExtent; x++) {
            if ((y & 1) && (x & 1)) {
                DrawPlane({ x* tileSize, 0.0f, y* tileSize },{ tileSize, tileSize }, tileColor1);
            }
            else if (!(y & 1) && !(x & 1)) {
                DrawPlane({ x* tileSize, 0.0f, y* tileSize }, { tileSize, tileSize }, LIGHTGRAY);
            }
        }
    }

    for (Ball& ball : projectiles) {
        ball.draw();
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