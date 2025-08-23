#define TILEABLE_TEXTURE
float DistancePointToLine(Vector2 p, Vector2 a, Vector2 b) {
    // Vector from A to P
    Vector2 ap = { p.x - a.x, p.y - a.y };
    // Vector from A to B
    Vector2 ab = { b.x - a.x, b.y - a.y };

    float abLenSq = ab.x * ab.x + ab.y * ab.y;
    if (abLenSq == 0) return sqrtf(ap.x * ap.x + ap.y * ap.y); // A and B are the same point

    // Project point onto the line, clamping t to [0, 1] for a segment
    float t = (ap.x * ab.x + ap.y * ab.y) / abLenSq;
    if (t < 0) t = 0;
    else if (t > 1) t = 1;

    // Closest point on segment to P
    Vector2 closest = { a.x + ab.x * t, a.y + ab.y * t };

    // Distance from P to closest point
    float dx = p.x - closest.x;
    float dy = p.y - closest.y;
    return Vector2Length({ dx,dy });
}
float lineSide(Vector2 p, Vector2 a, Vector2 b) {
    float d = (p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x);
    if (d == 0)
        return 0.0f;
    if (d < 0)
        return -1.0f;
    if (d > 0)
        return 1.0f;
}
static inline Vector2 ClipVelocityAgainstNormal(Vector2 v, Vector2 n, bool nIsNormalized) {
    float ndot = v.x * n.x + v.y * n.y;
    if (ndot < 0.0f) { // only if moving into the wall
        if (nIsNormalized) {
            v.x -= ndot * n.x;
            v.y -= ndot * n.y;
        }
        else {
            float nn = n.x * n.x + n.y * n.y;
            if (nn > 0.0f) {
                float k = ndot / nn;
                v.x -= k * n.x;
                v.y -= k * n.y;
            }
        }
    }
    return v;
}

bool CheckCollisionPointQuad(Vector2 p, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
    return CheckCollisionPointTriangle(p, a, b, c) || CheckCollisionPointTriangle(p, a, c, d) || CheckCollisionPointLine(p, a, c, 1.0f);
}
bool CheckCollisionCircleQuad(Vector2 circleCenter, float radius, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
    // Check if circle center is inside the quad
    if (CheckCollisionPointQuad(circleCenter, a, b, c, d)) {
        return true; // Circle center is inside the quad
    }
    // Check distance from circle center to each edge of the quad
    float dist1 = DistancePointToLine(circleCenter, a, b);
    float dist2 = DistancePointToLine(circleCenter, b, c);
    float dist3 = DistancePointToLine(circleCenter, c, d);
    float dist4 = DistancePointToLine(circleCenter, d, a);
    if (dist1 < radius || dist2 < radius || dist3 < radius || dist4 < radius) {
        return true; // Circle collides with at least one edge of the quad
    }
    return false; // No collision detected
}
class Sector {
public:
    Vector2 p1;
    Vector2 p2;
    float distanceToPoint(Vector2 p) {
        return DistancePointToLine(p, p1, p2);
    }
    Vector2 getDirection() {
        Vector2 dir = p2 - p1;
        return Vector2Normalize(dir);
    }
    Vector2 getNormal() {
        Vector2 dir = getDirection();
        return {dir.y,-dir.x};
    }
};
struct Wall {
    Vector2 points[4];
    float z;
    float height;

    Color tint = BLUE;
    
    float rotation;
    bool rotating;

    bool canSpawn;

    float area() const { // unused
        Vector2 a = points[0];
        Vector2 b = points[1];
        Vector2 c = points[2];
        Vector2 d = points[3];
        return fabsf((a.x * (b.y - d.y) + b.x * (c.y - a.y) + c.x * (d.y - b.y) + d.x * (a.y - c.y)) / 2.0f);

    }
    Vector2 center() const {
        Vector2 sum = points[0] + points[1] + points[2] + points[3];
        return Vector2Scale(sum, 0.25f);
    }
    void draw(bool tintOverride = false, Color newTint = WHITE) {
        if (tintOverride) {
            rlColor4ub(newTint.r, newTint.g, newTint.b, newTint.a);
        }
        else {
            rlColor4ub(tint.r, tint.g, tint.b, tint.a);
        }
        for (int i = 0; i < 4; i++) {
            Sector sect = { points[i],points[(i + 1) % 4] };
            Vector2 hDir = sect.getDirection();
            #ifdef MULTI_TILEABLE_TEXTURE
            // Bottom Left Corner
            rlTexCoord2f(1, 1); rlVertex3f(sect.p1.x, z, sect.p1.y);
            rlTexCoord2f(1, 0.75); rlVertex3f(sect.p1.x, z + 1, sect.p1.y);
            rlTexCoord2f(0.75, 0.75); rlVertex3f(sect.p1.x + hDir.x, z + 1, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 1); rlVertex3f(sect.p1.x + hDir.x, z, sect.p1.y + hDir.y);

            // Bottom Right Corner
            rlTexCoord2f(0, 1); rlVertex3f(sect.p2.x, z, sect.p2.y);
            rlTexCoord2f(0.25, 1); rlVertex3f(sect.p2.x - hDir.x, z, sect.p2.y - hDir.y);
            rlTexCoord2f(0.25, 0.75); rlVertex3f(sect.p2.x - hDir.x, z + 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0, 0.75); rlVertex3f(sect.p2.x, z + 1, sect.p2.y);

            // Top Left Corner
            rlTexCoord2f(1, 0.25); rlVertex3f(sect.p1.x, z + height - 1, sect.p1.y);
            rlTexCoord2f(1, 0); rlVertex3f(sect.p1.x, z + height, sect.p1.y);
            rlTexCoord2f(0.75, 0); rlVertex3f(sect.p1.x + hDir.x, z + height, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 0.25); rlVertex3f(sect.p1.x + hDir.x, z + height - 1, sect.p1.y + hDir.y);

            // Top Right Corner
            rlTexCoord2f(0, 0.25); rlVertex3f(sect.p2.x, z + height - 1, sect.p2.y);
            rlTexCoord2f(0.25, 0.25); rlVertex3f(sect.p2.x - hDir.x, z + height - 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0.25, 0); rlVertex3f(sect.p2.x - hDir.x, z + height, sect.p2.y - hDir.y);
            rlTexCoord2f(0, 0); rlVertex3f(sect.p2.x, z + height, sect.p2.y);

            // Bottom Side
            rlTexCoord2f(0.75, 1); rlVertex3f(sect.p1.x + hDir.x, z, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 0.75); rlVertex3f(sect.p1.x + hDir.x, z + 1, sect.p1.y + hDir.y);
            rlTexCoord2f(0.25, 0.75); rlVertex3f(sect.p2.x - hDir.x, z + 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0.25, 1); rlVertex3f(sect.p2.x - hDir.x, z, sect.p2.y - hDir.y);

            // Top Side
            rlTexCoord2f(0.75, 0.25); rlVertex3f(sect.p1.x + hDir.x, z + height - 1, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 0); rlVertex3f(sect.p1.x + hDir.x, z + height, sect.p1.y + hDir.y);
            rlTexCoord2f(0.25, 0); rlVertex3f(sect.p2.x - hDir.x, z + height, sect.p2.y - hDir.y);
            rlTexCoord2f(0.25, 0.25); rlVertex3f(sect.p2.x - hDir.x, z + height - 1, sect.p2.y - hDir.y);

            // Right Side
            rlTexCoord2f(1, 0.75); rlVertex3f(sect.p1.x, z + 1, sect.p1.y);
            rlTexCoord2f(1, 0.25); rlVertex3f(sect.p1.x, z + height - 1, sect.p1.y);
            rlTexCoord2f(0.75, 0.25); rlVertex3f(sect.p1.x + hDir.x, z + height - 1, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 0.75); rlVertex3f(sect.p1.x + hDir.x, z + 1, sect.p1.y + hDir.y);

            // Left Side
            rlTexCoord2f(0.25, 0.25); rlVertex3f(sect.p2.x - hDir.x, z + height - 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0, 0.25); rlVertex3f(sect.p2.x, z + height - 1, sect.p2.y);
            rlTexCoord2f(0, 0.75); rlVertex3f(sect.p2.x, z + 1, sect.p2.y);
            rlTexCoord2f(0.25, 0.75); rlVertex3f(sect.p2.x - hDir.x, z + 1, sect.p2.y - hDir.y);

            // Center
            rlTexCoord2f(0.25, 0.25); rlVertex3f(sect.p2.x - hDir.x, z + height - 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0.25, 0.75); rlVertex3f(sect.p2.x - hDir.x, z + 1, sect.p2.y - hDir.y);
            rlTexCoord2f(0.75, 0.75); rlVertex3f(sect.p1.x + hDir.x, z + 1, sect.p1.y + hDir.y);
            rlTexCoord2f(0.75, 0.25); rlVertex3f(sect.p1.x + hDir.x, z + height - 1, sect.p1.y + hDir.y);
            #elifdef REGULAR_TEXTURE
            rlTexCoord2f(0, 1); rlVertex3f(sect.p1.x, z, sect.p1.y);
            rlTexCoord2f(0, 0); rlVertex3f(sect.p1.x, z + height, sect.p1.y);
            rlTexCoord2f(1, 0); rlVertex3f(sect.p2.x, z + height, sect.p2.y);
            rlTexCoord2f(1, 1); rlVertex3f(sect.p2.x, z, sect.p2.y);
            #else
            const float SIZE = 2.0f;
            for (int i = 0; i < 4; i++) {
                int j = (i + 1) % 4;

                // Bottom and top vertices
                Vector3 v1 = { points[i].x,     z,         points[i].y };
                Vector3 v2 = { points[j].x,     z,         points[j].y };
                Vector3 v3 = { points[j].x,     z + height, points[j].y };
                Vector3 v4 = { points[i].x,     z + height, points[i].y };
                
                Sector sector = { points[i],points[j] };
                Vector2 normal = sector.getNormal();

                // Wall dimensions for texture tiling
                float wallWidth = Vector2Distance(points[i], points[j]);
                float wallHeight = height;

                float tileW = wallWidth / SIZE;
                float tileH = wallHeight / SIZE;

                // Draw one face (i -> j)
                rlNormal3f(normal.x, 0.0f, normal.y);
                rlTexCoord2f(0, tileH);   rlVertex3f(v4.x, v4.y, v4.z);
                rlTexCoord2f(tileW, tileH); rlVertex3f(v3.x, v3.y, v3.z);
                rlTexCoord2f(tileW, 0);   rlVertex3f(v2.x, v2.y, v2.z);
                rlTexCoord2f(0, 0);       rlVertex3f(v1.x, v1.y, v1.z);
            }
            // --- Ceiling (bottom face) ---
            {
                Vector3 v1 = { points[0].x, z, points[0].y };
                Vector3 v2 = { points[1].x, z, points[1].y };
                Vector3 v3 = { points[2].x, z, points[2].y };
                Vector3 v4 = { points[3].x, z, points[3].y };

                float w = Vector2Distance(points[0], points[1]);
                float h = Vector2Distance(points[1], points[2]);

                float tileW = w / SIZE;
                float tileH = h / SIZE;

                rlNormal3f(0.0f, -1.0f, 0.0f);
                rlTexCoord2f(0, 0);       rlVertex3f(v1.x, v1.y, v1.z);
                rlTexCoord2f(tileW, 0);   rlVertex3f(v2.x, v2.y, v2.z);
                rlTexCoord2f(tileW, tileH); rlVertex3f(v3.x, v3.y, v3.z);
                rlTexCoord2f(0, tileH);   rlVertex3f(v4.x, v4.y, v4.z);
            }

            // --- Floor (top face) ---
            {
                Vector3 v1 = { points[0].x, z + height, points[0].y };
                Vector3 v2 = { points[1].x, z + height, points[1].y };
                Vector3 v3 = { points[2].x, z + height, points[2].y };
                Vector3 v4 = { points[3].x, z + height, points[3].y };

                float w = Vector2Distance(points[0], points[1]);
                float h = Vector2Distance(points[1], points[2]);

                float tileW = w / SIZE;
                float tileH = h / SIZE;

                rlNormal3f(0.0f, 1.0f, 0.0f);
                rlTexCoord2f(0, tileH);   rlVertex3f(v4.x, v4.y, v4.z);
                rlTexCoord2f(tileW, tileH); rlVertex3f(v3.x, v3.y, v3.z);
                rlTexCoord2f(tileW, 0);   rlVertex3f(v2.x, v2.y, v2.z);
                rlTexCoord2f(0, 0);       rlVertex3f(v1.x, v1.y, v1.z);
            }
            #endif
        }

        /*rlTexCoord2f(0, 0); rlVertex3f(points[0].x, z, points[0].y);
        rlTexCoord2f(0, 1); rlVertex3f(points[1].x, z, points[1].y);
        rlTexCoord2f(1, 1); rlVertex3f(points[2].x, z, points[2].y);
        rlTexCoord2f(1, 0); rlVertex3f(points[3].x, z, points[3].y);

        rlTexCoord2f(1, 0); rlVertex3f(points[3].x, z + height, points[3].y);
        rlTexCoord2f(1, 1); rlVertex3f(points[2].x, z + height, points[2].y);
        rlTexCoord2f(0, 1); rlVertex3f(points[1].x, z + height, points[1].y);
        rlTexCoord2f(0, 0); rlVertex3f(points[0].x, z + height, points[0].y);*/
    }
    void rotate(float angle) {
        Vector2 mid = center();
        for (int i = 0; i < 4; i++) {
            points[i] = Vector2Rotate(points[i] - mid, angle) + mid;
        }
    }
    BoundingBox getBoundingBox() {
        BoundingBox bbox = {
            {INFINITY,z,INFINITY},
            {-INFINITY,z + height,-INFINITY},
};
        for (int i = 0; i < 4; i++) {
            Vector2 p = points[i];
            bbox.min.x = fmin(bbox.min.x, p.x);
            bbox.min.z = fmin(bbox.min.z, p.y);
            bbox.max.x = fmax(bbox.max.x, p.x);
            bbox.max.z = fmax(bbox.max.z, p.y);
        }
        return bbox;
    }
    Vector3 getRandomPoint() {
        Vector3 randomPoint = { 0 };
        BoundingBox boundingBox = getBoundingBox();
        randomPoint.x = GetRandomValue(boundingBox.min.x, boundingBox.max.x);
        randomPoint.z = GetRandomValue(boundingBox.min.z, boundingBox.max.z);
        randomPoint.y = z + height;
        return randomPoint;
    }
};
struct GameMap {
    std::vector<Wall> walls;
    void draw() {
        rlSetTexture(tile_5.id);
        rlBegin(RL_QUADS);
        for (Wall wall : walls) {
            wall.draw();
        }
        rlEnd();

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
        for (Wall& wall : walls) {
            if (wall.rotating) {
                wall.rotate(wall.rotation * delta);
            }
        }
    }
    Vector3 getRandomSpawnPoint() {
        for (Wall& wall : walls) {
            if (wall.canSpawn) {
                return wall.getRandomPoint();
            }
        }
        return { 0,0,0 };
    }
};