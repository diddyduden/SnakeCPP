#include <iostream>
#include <raylib.h>

class SnakeHead {
    //size and positioning, important vars
private:
    const int snakeWidth = 60;
    const int snakeHeight = 60;
    
    int snakeX = 100;
    int snakeY = 100;

    bool isCollided = false;
    Color snakeColor = SKYBLUE;

public:
    //methods
    //drawrectanglerect också
    //Rectangle snakeRect();


    void movement() {
        if (IsKeyPressed(KEY_W)) {
            snakeY -= 64;
            std::cout << "pressed W key" << std::endl;
        }
        if (IsKeyPressed(KEY_A)) {
            snakeX -= 64;
            std::cout << "pressed A key" << std::endl;
        }
        if (IsKeyPressed(KEY_S)) {
            snakeY += 64;
            std::cout << "pressed S key" << std::endl;
        }
        if (IsKeyPressed(KEY_D)) {
            snakeX += 64;
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
    const int appleWidth = 60;
    const int appleHeight = 60;

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
    const int width = 700;
    const int height = 700;

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