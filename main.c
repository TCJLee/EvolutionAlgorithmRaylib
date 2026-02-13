#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#ifndef WIDTH
#define WIDTH 800
#endif

#ifndef HEIGHT
#define HEIGHT 600
#endif

#define RADIUS 50.0

#define VEL_MAGNITUDE 200.0

#define MOUSE_STRENGTH 30.0

int uniqueRand(int max, int curr) {
    int res = rand() % max;
    if (res == curr) res += 1;
    res %= max;
    return res;
}

int main() {
    InitWindow(WIDTH, HEIGHT, "EVOLVE");

    Color bgColor = {0x11, 0x15, 0x18, 0xff};

    Color ballColors[] = {
        {0x9d, 0x00, 0x00, 0xff},
        {0x00, 0x9d, 0x00, 0xff},
        {0x00, 0x00, 0x9d, 0xff},
        {0x47, 0x47, 0xaf, 0xff},
        {0x00, 0xaf, 0x95, 0xff},
        {0xaf, 0x95, 0x00, 0xff}
    };
    int colorCount = sizeof(ballColors) / sizeof(Color);

    int currBallColorI = 0;

    Vector2 pos = {RADIUS + 10, RADIUS + 10};

    Vector2 vel = {1, 1};

    vel = Vector2Scale(Vector2Normalize(vel), VEL_MAGNITUDE);

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 direction = Vector2Normalize(Vector2Subtract(GetMousePosition(), pos));
            direction = Vector2Scale(direction, MOUSE_STRENGTH);
            vel = Vector2ClampValue(
                Vector2Add(vel, direction),
                VEL_MAGNITUDE, VEL_MAGNITUDE);
        }
        pos.x += (float) vel.x * dt;
        pos.y += (float) vel.y * dt;

        if (pos.x + RADIUS >= WIDTH || pos.x - RADIUS <= 0) {
            vel.x *= -1;
            pos.x += (float) vel.x * dt;
            currBallColorI = uniqueRand(colorCount, currBallColorI);
        }
        if (pos.y + RADIUS >= HEIGHT || pos.y - RADIUS <= 0) {
            vel.y *= -1;
            pos.y += (float) vel.y * dt;
            currBallColorI = uniqueRand(colorCount, currBallColorI);
        }

        BeginDrawing();
        ClearBackground(bgColor);

        DrawCircle(pos.x, pos.y, RADIUS, ballColors[currBallColorI]);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}