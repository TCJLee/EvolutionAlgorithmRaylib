#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#include "goob.h"

#ifndef WIDTH
#define WIDTH 800
#endif

#ifndef HEIGHT
#define HEIGHT 600
#endif

int main() {
    InitWindow(WIDTH, HEIGHT, "EVOLVE");

    Color bgColor = {0x11, 0x15, 0x18, 0xff};

    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        
        BeginDrawing();
        ClearBackground(bgColor);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}