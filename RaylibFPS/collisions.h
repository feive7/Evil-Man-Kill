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
    Vector2 getNormal() {
        Vector2 dir = p2 - p1;
        return Vector2Normalize({dir.y,-dir.x});
    }
};
class Wall {
public:
    Vector2 points[4];
    float z;
    float height;
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
    void draw() {
        for (int i = 0; i < 4; i++) {
            Vector2 p1 = points[i];
            Vector2 p2 = points[(i+1)%4];
            rlTexCoord2f(0, 1); rlVertex3f(p1.x, z, p1.y);
            rlTexCoord2f(0, 0); rlVertex3f(p1.x, z + height, p1.y);
            rlTexCoord2f(1, 0); rlVertex3f(p2.x, z + height, p2.y);
            rlTexCoord2f(1, 1); rlVertex3f(p2.x, z, p2.y);
        }

        rlTexCoord2f(0, 0); rlVertex3f(points[0].x, z, points[0].y);
        rlTexCoord2f(0, 1); rlVertex3f(points[1].x, z, points[1].y);
        rlTexCoord2f(1, 1); rlVertex3f(points[2].x, z, points[2].y);
        rlTexCoord2f(1, 0); rlVertex3f(points[3].x, z, points[3].y);

        rlTexCoord2f(1, 0); rlVertex3f(points[3].x, z + height, points[3].y);
        rlTexCoord2f(1, 1); rlVertex3f(points[2].x, z + height, points[2].y);
        rlTexCoord2f(0, 1); rlVertex3f(points[1].x, z + height, points[1].y);
        rlTexCoord2f(0, 0); rlVertex3f(points[0].x, z + height, points[0].y);
    }
};
struct GameMap {
    std::vector<Wall> walls;
    void draw() {
        for (Wall wall : walls) {
            wall.draw();
        }
    }
};