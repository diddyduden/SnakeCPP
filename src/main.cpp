#include <iostream>
#include <raylib.h>
#include <vector>

class SnakeCube {
private:
    const int snakeWidth = 40;
    const int snakeHeight = 40;
    const int block = 40;
    Color snakeColor = SKYBLUE;

public:
    //get
    int getSnakeWidth() { return snakeWidth; }
    int getSnakeHeight() { return snakeHeight; }
    int getBlock() { return block; }
    Color getColor() { return snakeColor; }
};

class SnakeHead : public SnakeCube {
private:
    int snakeX = 120;
    int snakeY = 120;

public:
    //methods
    void movement() {
        if (IsKeyPressed(KEY_W)) {
            snakeY -= getBlock();
            std::cout << "pressed W key" << std::endl;
        }
        if (IsKeyPressed(KEY_A)) {
            snakeX -= getBlock();
            std::cout << "pressed A key" << std::endl;
        }
        if (IsKeyPressed(KEY_S)) {
            snakeY += getBlock();
            std::cout << "pressed S key" << std::endl;
        }
        if (IsKeyPressed(KEY_D)) {
            snakeX += getBlock();
            std::cout << "pressed D key" << std::endl;
            std::cout << snakeX << std::endl;
        }
    }

    //get 
    int getSnakeX() { return snakeX; }
    int getSnakeY() { return snakeY; }

    //sets
    void setSnakeX(int xPos) { snakeX = xPos; }
    void setSnakeY(int yPos) { snakeY = yPos; }
};

class Apple {
private:
    const int appleWidth = 40;
    const int appleHeight = 40;

    //random spawn intial spawn
    int appleX = GetRandomValue(0, 20) * 40;
    int appleY = GetRandomValue(0, 20) * 40;

public:
    //methods
    void appleRespawn() {
        appleX = GetRandomValue(0, 20) * 40;
        appleY = GetRandomValue(0, 20) * 40;
    }

    //get
    int getAppleWidth() { return appleWidth; }
    int getAppleHeight() { return appleHeight; }

    int getAppleX() { return appleX; }
    int getAppleY() { return appleY; }

    //set
    void setAppleX(int xPos) { appleX = xPos; };
    void setAppleY(int yPos) { appleY = yPos; };
};

int main() {
    //game definitions
    const int width = 840;
    const int height = 840;

    InitWindow(width, height, "Snake");
    SetTargetFPS(60);

    //colors
    Color snakeGrass = {161, 255, 104, 255 };
        
    //initialize things
    SnakeHead snake;
    Apple apple;

    //game loop
    while (WindowShouldClose() == false) {
        BeginDrawing();

        //bakgrunden
        ClearBackground(snakeGrass);


        //snake egenskaper o sånt idk
        snake.movement();
        Rectangle snakeRect = { snake.getSnakeX(), snake.getSnakeY(), snake.getSnakeHeight(), snake.getSnakeHeight() };
        DrawRectangleRec(snakeRect, snake.getColor());

        //apple
        Rectangle appleRect = { apple.getAppleX(), apple.getAppleY(), apple.getAppleWidth(), apple.getAppleHeight() };
        DrawRectangleRec(appleRect, RED);


        //collision med apple, kollision med vägg o sigsjälv soon
        if (CheckCollisionRecs(snakeRect, appleRect)) {
            std::cout << "hi";
            apple.appleRespawn();
            
         //snake coverage funktion?
        }

        EndDrawing();
    }
    CloseWindow();
}

/* pink color
// Color snakeGrass = { 255, 214, 222, 255 };
//behöver ingen constructor för alla värden kommer ju startas likadant?

//theme? ändra tema (färger på orm bakgrund osv)


        
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
        */


/*
äpplerespanwas, check
create a new snake cube position of the last tail segment or at the head 
*/





//main class är snake cube
// snkaehead är en subklass av snake cube , har movmeents etc
//

/*
alla snake cube ska ha en direction som tas från previous
snake head ger fixar direction först, sätts i movement, dir = right osv
skapa en lista och sätta objekten så att du kan använda listor och nås med index


*/