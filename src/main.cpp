#include <iostream>
#include <raylib.h>
#include <vector>

//gör om snake classerna
//t.ex x och y pos ska finnas på båda men det gör det inte just nu.
//referencces

//fixa constructor för snake cube, x och y pos
class SnakeCube {
private:
    const int block = 40;
    const int& snakeWidth = block;
    const int& snakeHeight = block;
    Color snakeColor = SKYBLUE;

    int snakeX;
    int snakeY;

public:
    //constructor
    SnakeCube(int xSnakePos, int ySnakePos) {
        snakeX = xSnakePos;
        snakeY = ySnakePos;
    }

    //methods
    Rectangle drawRect() {
        Rectangle snakeRect = { (float)getSnakeX(), (float)getSnakeY(), (float)getSnakeHeight(), (float)getSnakeHeight() };
        DrawRectangleRec(snakeRect, getColor());
        return snakeRect;
    }

    void snakeGrow() {
            
    }

    //get
    int getSnakeWidth() { return snakeWidth; }
    int getSnakeHeight() { return snakeHeight; }
    int getBlock() { return block; }

    Color getColor() { return snakeColor; }

    int getSnakeX() { return snakeX; }
    int getSnakeY() { return snakeY; }

    //sets
    void setSnakeX(int xPos) { snakeX = xPos; }
    void setSnakeY(int yPos) { snakeY = yPos; }
};

class SnakeHead : public SnakeCube {
public:
    SnakeHead(int x, int y) : SnakeCube(x, y) {
        setSnakeX(x);
        setSnakeY(y);
    }

    //movement
    void movement() {
        if (IsKeyPressed(KEY_W)) {
            setSnakeY(getSnakeY() - getBlock());
            std::cout << "pressed W key" << std::endl;
        }
        if (IsKeyPressed(KEY_A)) {
            setSnakeX(getSnakeX() - getBlock());
            std::cout << "pressed A key" << std::endl;
        }
        if (IsKeyPressed(KEY_S)) {
            setSnakeY(getSnakeY() + getBlock());
            std::cout << "pressed S key" << std::endl;
        }
        if (IsKeyPressed(KEY_D)) {
            setSnakeX(getSnakeX() + getBlock());
            std::cout << "pressed D key" << std::endl;
        }
    }
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

    //drawing
    Rectangle drawAppleRect() {
        Rectangle appleRect = { (float)getAppleX(), (float)getAppleY(), (float)getAppleHeight(), (float)getAppleWidth() };
        DrawRectangleRec(appleRect, RED);
        return appleRect;
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
    SnakeHead snakeHead(120, 120);
    Apple apple;
    std::vector<SnakeCube> snakeBody;

    //game loop
    while (WindowShouldClose() == false) {
        BeginDrawing();

        //bakgrunden
        ClearBackground(snakeGrass);

        //snake egenskaper o sånt idk
        snakeHead.movement();
        snakeHead.drawRect();
        Rectangle snakeRect = snakeHead.drawRect();


        //apple
        apple.drawAppleRect();
        Rectangle appleRect = apple.drawAppleRect();




        

        //collision apple detection
        if (CheckCollisionRecs(snakeRect, appleRect)) {
            apple.appleRespawn();
            snakeBody.push_back(SnakeCube(100, 100));





            //spawn snake cube
         //snake coverage funktion?

        }

        EndDrawing();
    }   
    CloseWindow();
}