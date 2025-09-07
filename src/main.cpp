#include <iostream>
#include <raylib.h>
#include <random>

class SnakeHead {
    //size and positioning, important vars
private:
    const int snakeWidth = 40;
    const int snakeHeight = 40;
    const int block = 40;
    
    int snakeX = 120;
    int snakeY = 120;

    bool isCollided = false;
    Color snakeColor = SKYBLUE;

public:
    //methods
    void movement() {
        if (IsKeyPressed(KEY_W)) {
            snakeY -= block;
            std::cout << "pressed W key" << std::endl;
        }
        if (IsKeyPressed(KEY_A)) {
            snakeX -= block;
            std::cout << "pressed A key" << std::endl;
        }
        if (IsKeyPressed(KEY_S)) {
            snakeY += block;
            std::cout << "pressed S key" << std::endl;
        }
        if (IsKeyPressed(KEY_D)) {
            snakeX += block;
            std::cout << "pressed D key" << std::endl;
        }
    }

    void eatApple() {

    }

    void collide() {

    }

    //get 
    int getSnakeX() { return snakeX; }
    int getSnakeY() { return snakeY; }

    bool getIsCollided() { return isCollided; }

    int getSnakeWidth() { return snakeWidth; }
    int getSnakeHeight() { return snakeHeight; }

    Color getColor() { return snakeColor; }

    //sets
    void setSnakeX(int xPos) { snakeX = xPos; }
    void setSnakeY(int yPos) { snakeY = yPos; }

    void setIsCollided(bool collided) { isCollided = collided; }   
};

class SnakeCube : SnakeHead {
private:


public:


};

class Apple {
private:
    const int appleWidth = 40;
    const int appleHeight = 40;

    //random siffra gånger 32 som är mindre än 700 totalt
    //

    std::random_device rd;
    std::mt19937 gen(rd());






    //random spawn intial spawn
    int appleX = GetRandomValue(0, 700);
    int appleY = GetRandomValue(0, 700);





public:
    //methods
    void appleRespawn() {
        appleX = GetRandomValue(0, 700);
        appleY = GetRandomValue(0, 700);
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
    const int width = 800;
    const int height = 800;

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