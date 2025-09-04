#include <iostream>
#include <raylib.h>

int main() {

    //game definitions
    const int width = 700;
    const int height = 700;

    //colors
    Color snakeGrass = {161, 255, 104, 255 };

    InitWindow(width, height, "Snake");
    SetTargetFPS(60);

    //game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(snakeGrass);
        
        DrawRectangle(100, 100, 50, 50, RED);







        EndDrawing();
    }
    CloseWindow();

    return 0;
}



// pink color
// Color snakeGrass = { 255, 214, 222, 255 };