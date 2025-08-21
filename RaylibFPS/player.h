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
static int score = 0;

static Texture tex_john;
static Texture tex_john_victory;
static Texture tile_1;

static Shader shader_discard;

static Sound snd_gunshot;
static Sound snd_hit;
static Sound snd_step;

static Music music_main;
static Music music_lose;

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
    void draw() {
        DrawSphere(position, radius, BLACK);
    }
};
static std::vector<Projectile> projectiles;
class Body {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 dir;
    bool isGrounded;

    float heightLerp = 1.0f;
    float standingHeight = 2.0f;
    float crouchingHeight = 1.0f;
    bool crouching;

    float radius;

    Vector2 lookRotation;

    Vector3 getForward() {
        float yaw = lookRotation.x;
        float pitch = lookRotation.y;

        Vector3 forward;
        forward.x = -sinf(yaw) * cosf(pitch);
        forward.y = -sinf(pitch);
        forward.z = -cosf(yaw) * cosf(pitch);

        return Vector3Normalize(forward);
    }

    float getHeight() {
        return Lerp(crouchingHeight, standingHeight, heightLerp);
    }

    Vector3 getHeadPos() {
        return position + Vector3{ 0,getHeight(),0};
    }

    void tryMove() {
        float delta = GetFrameTime();
        Vector3 newpos = position + Vector3Scale(velocity, delta);
        Vector3 newvel = velocity;
        float height = getHeight();

        bool grounded = false;

        for (Wall& wall : testmap.walls) {
            for (int i = 0; i < 4; i++) {
                Sector sect = { wall.points[i],wall.points[(i + 1) % 4] };
                float lineDist = sect.distanceToPoint({ newpos.x,newpos.z });
                if (lineDist < radius && position.y + height > wall.z && position.y < wall.z + wall.height ) {
                    float cDist = (radius - lineDist) * lineSide({ newpos.x,newpos.z }, sect.p1, sect.p2); // Distance into the wall
                    Vector2 normal = sect.getNormal();
                    newpos.x += normal.x * cDist;
                    newpos.z += normal.y * cDist;
                    Vector2 velocityClip = ClipVelocityAgainstNormal({ newvel.x,newvel.z }, normal, true);
                    newvel.x = velocityClip.x;
                    newvel.z = velocityClip.y;
                }
            }
            if (CheckCollisionCircleQuad({ newpos.x,newpos.z }, radius, wall.points[0], wall.points[1], wall.points[2], wall.points[3])) { // Checking vertical collisions
                if (newpos.y <= wall.z + wall.height && newpos.y > wall.z + wall.height - 1.0f) { // Hit top of wall
                    newpos.y = wall.z + wall.height;
                    grounded = true;
                    newvel.y = 0.0f;
                }
                else if (newpos.y + height > wall.z && newpos.y + height < wall.z + 1.0f) { // Hit bottom of wall
                    newvel.y = 0.0f;
                    newpos.y = wall.z - height;
                }
            }
        }

        isGrounded = grounded;
        velocity = newvel;
        position = newpos;
    }
    
    BoundingBox getBoundingBox() {
        return {
            Vector3Subtract(position,{0.5f,0.0f,0.5f}),
            Vector3Add(getHeadPos(),{0.5f,0.0f,0.5f}),
        };
    }
    

};
class Player {
public:
    Body body;
    float headTimer;
    float walkLerp;
    bool alive = true;
    bool noclipping = false;
    Vector2 lean;

    int deathTick;

    void update() {
        if (alive) {
            if (IsKeyPressed(KEY_V)) {
                noclipping = !noclipping;
            }
            updateLookRotation();
            if (noclipping) {
                body.velocity = { 0.0f,0.0f,0.0f };
                noclip();
            }
            else {
                move();
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
private:
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
        if (-(body.lookRotation.y) > maxAngleUp) { body.lookRotation.y = -maxAngleUp; }

        // Clamp view down
        float maxAngleDown = Vector3Angle(Vector3Negate(up), yaw);
        maxAngleDown *= -1.0f; // Downwards angle is negative
        maxAngleDown += 0.001f; // Avoid numerical errors
        if (-(body.lookRotation.y) < maxAngleDown) { body.lookRotation.y = -maxAngleDown; }
    }
    void noclip() {
        char sideway = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
        char forward = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
        char vertical = (IsKeyDown(KEY_SPACE) - IsKeyDown(KEY_LEFT_CONTROL));

        float speed = 0.2f;

        Quaternion qLook = QuaternionFromEuler(-body.lookRotation.y, body.lookRotation.x, 0.0f);
        Vector3 movement = Vector3RotateByQuaternion({ (float) sideway,(float)vertical,(float)-forward}, qLook);

        body.position += Vector3Scale(movement,speed);
    }
    void move() {
        // Get keyboard inputs
        bool jumpPressed = IsKeyPressed(KEY_SPACE);
        char sideway = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A));
        char forward = (IsKeyDown(KEY_W) - IsKeyDown(KEY_S));
        body.crouching = IsKeyDown(KEY_LEFT_CONTROL);

        Vector2 input = { (float)sideway, (float)-forward };

#if defined(NORMALIZE_INPUT)
        // Slow down diagonal movement
        if ((sideway != 0) && (forward != 0)) input = Vector2Normalize(input);
#endif

        float delta = GetFrameTime();

        if (!body.isGrounded) body.velocity.y -= GRAVITY * delta;

        if (body.isGrounded && jumpPressed) {
            body.velocity.y = JUMP_FORCE;
            body.isGrounded = false;

            // Sound can be played at this moment
            //SetSoundPitch(fxJump, 1.0f + (GetRandomValue(-100, 100)*0.001));
            //PlaySound(fxJump);
        }

        Vector3 front = { sin(body.lookRotation.x), 0.f, cos(body.lookRotation.x) };
        Vector3 right = { cos(-body.lookRotation.x), 0.f, sin(-body.lookRotation.x) };

        Vector3 desiredDir = { input.x * right.x + input.y * front.x, 0.0f, input.x * right.z + input.y * front.z, };
        body.dir = Vector3Lerp(body.dir, desiredDir, CONTROL * delta);

        float decel = (body.isGrounded ? FRICTION : AIR_DRAG);
        Vector3 hvel = { body.velocity.x * decel, 0.0f, body.velocity.z * decel };

        float hvelLength = Vector3Length(hvel); // Magnitude
        if (hvelLength < (MAX_SPEED * 0.01f)) hvel = { 0 };

        // This is what creates strafing
        float speed = Vector3DotProduct(hvel, body.dir);

        // Whenever the amount of acceleration to add is clamped by the maximum acceleration constant,
        // a Player can make the speed faster by bringing the direction closer to horizontal velocity angle
        // More info here: https://youtu.be/v3zT3Z5apaM?t=165
        float maxSpeed = (body.crouching ? CROUCH_SPEED : MAX_SPEED);
        float accel = Clamp(maxSpeed - speed, 0.f, MAX_ACCEL * delta);
        hvel.x += body.dir.x * accel;
        hvel.z += body.dir.z * accel;

        body.velocity.x = hvel.x;
        body.velocity.z = hvel.z;

        body.tryMove();

        // Fancy collision system against the floor
        //if (body.position.y <= 0.0f) {
        //    body.position.y = 0.0f;
        //    body.velocity.y = 0.0f;
        //    body.isGrounded = true; // Enable jumping
        //}

        body.heightLerp = Lerp(body.heightLerp, (body.crouching ? CROUCH_HEIGHT : STAND_HEIGHT), 20.0f * delta);

        if (body.isGrounded && ((forward != 0) || (sideway != 0))) {
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
        body.position.x = fmod(body.position.x, bounds.x);
        body.position.y = fmod(body.position.y, bounds.y);
        body.position.z = fmod(body.position.z, bounds.z);
    }
};
class Enemy {
public:
    Body body;
    Player* target;
    bool alive = true;
    bool victoryDance;
    float speed;

    float walkTimer;

    void update() {
        if (target == nullptr) {
            printf("Error: No target\n");
            return;
        }
        if (target->alive) {
            Vector3 direction = Vector3Normalize(target->body.position - body.position); direction.y = 0.0f; direction = Vector3Normalize(direction);
            body.position += Vector3Scale(direction, speed);
            walkTimer += GetFrameTime();
            if (CheckCollisionBoxes(body.getBoundingBox(), target->body.getBoundingBox())) {
                target->alive = false;
                victoryDance = true;
            }
        }
    }
    void drawBoundingBox() {
        DrawBoundingBox(body.getBoundingBox(), BLACK);
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
    Vector3 pitch = Vector3RotateByAxisAngle(yaw, right, -player.body.lookRotation.y - player.lean.y);

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
    for (Projectile& projectile : projectiles) {
        projectile.update();

        for (Enemy& enemy : enemies) {
            if (CheckCollisionBoxSphere(enemy.body.getBoundingBox(), projectile.position, projectile.radius)) {
                projectile.alive = false;
                //enemy.alive = false;
                enemy.body.position.x = GetRandomValue(-100, 100);
                enemy.body.position.z = GetRandomValue(-100, 100);

                float x = GetRandomValue(-100, 100);
                float z = GetRandomValue(-100, 100);
                Enemy newEnemy;
                newEnemy.body.position.x = x;
                newEnemy.body.position.y = 0.0f;
                newEnemy.body.position.z = z;
                newEnemy.alive = true;
                newEnemy.target = enemy.target;
                newEnemy.speed = enemy.speed + 0.01f;
                enemies.push_back(newEnemy);

                score++;
                PlaySound(snd_hit);
                break;
            }
            if (projectile.position.y < 0.0f) {
                projectile.alive = false;
            }
        }
    }

    // Remove dead projectiles in one pass
    projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
        [](const Projectile& p) { return !p.alive; }),
        projectiles.end());
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](const Enemy& p) { return !p.alive; }),
        enemies.end());

    for (Enemy& enemy : enemies) {
        enemy.update();
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

    for (Projectile& ball : projectiles) {
        ball.draw();
    }

    for (Enemy& enemy : enemies) {
        //enemy.drawBoundingBox();
        //float midHeight = (enemy.body.getBoundingBox().max.y + enemy.body.getBoundingBox().min.y) / 2.0f;
        if (!IsSoundPlaying(snd_step)) {
            SetSoundPosition(camera, snd_step, enemy.body.position, 20.0f);
            PlaySound(snd_step);
        }
        DrawBillboard(camera, (enemy.victoryDance ? tex_john_victory : tex_john), enemy.body.position + Vector3{0.0f,enemy.body.getHeight() / 2.0f,0.0f}, enemy.body.getHeight(), WHITE);
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