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

static GameMap* loadedMap;

static Vector2 sensitivity = { 0.005f, 0.005f };
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
        return position + Vector3{ 0,getHeight() - HEAD_OFFSET,0 };
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

        for (Wall& wall : loadedMap->walls) {
            if (wall.ignoreCollisions) continue; // Skip wall if no collisions
            for (int i = 0; i < 4; i++) {
                Sector sect = { wall.points[i],wall.points[(i + 1) % 4] };
                float lineDist = sect.distanceToPoint({ newpos.x,newpos.z });
                if (lineDist < radius && position.y + height > wall.z && position.y < wall.z + wall.height) {
                    float cDist = (radius - lineDist) * lineSide({ newpos.x,newpos.z }, sect.p1, sect.p2); // Distance into the wall
                    Vector2 normal = sect.getNormal();
                    newpos.x += normal.x * cDist;
                    newpos.z += normal.y * cDist;
                    if (newpos.y >= wall.z + wall.height - STEP_HEIGHT && isGrounded) {
                        newpos.y = wall.z + wall.height;
                    }
                    else if (wall.surfaceMaterial == SURFACE_BOUNCY) {
                        newvel.x = -newvel.x;
                        newvel.z = -newvel.z;
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