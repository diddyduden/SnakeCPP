#include <iostream>
#include <raylib.h>

int main() {
    //game definitions
    const int width = 700;
    const int height = 700;

    //snake
    const int snakeHeadWidth = 60;
    const int snakeHeadHeight = 60;

    int snakeX = 100;
    int snakeY = 100;

    //colors
    Color snakeGrass = {161, 255, 104, 255 };

    InitWindow(width, height, "Snake");
    SetTargetFPS(60);

    //game loop
    while (WindowShouldClose() == false) {
        BeginDrawing();

        ClearBackground(snakeGrass);


        DrawGrid(32, 0);

        //wasd keybinds
        if (IsKeyPressed(KEY_W)) {
            snakeY -= 64;
        }
        if (IsKeyPressed(KEY_A)) {
            snakeX -= 64;
        }
        if (IsKeyPressed(KEY_S)) {
            snakeY += 64;
        }
        if (IsKeyPressed(KEY_D)) {
            snakeX += 64;
        }

        DrawRectangle(snakeX, snakeY, snakeHeadWidth, snakeHeadHeight, RED);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}



// pink color
// Color snakeGrass = { 255, 214, 222, 255 };