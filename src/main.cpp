#include <iostream>
#include "raylib.h"

int main() {

    //game definitions
    const int width = 700;
    const int height = 700;

    //colors
    Color snakeGrass = {255, 214, 222, 255 };

    InitWindow(width, height, "Snake");
    SetTargetFPS(60);

    //game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(snakeGrass);

        DrawText("Snake spel det bara börja liksom!", 200, 280, 30, LIGHTGRAY);






        EndDrawing();
    }
    CloseWindow();

    return 0;
}
