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
    const int snakeWidth = block;
    const int snakeHeight = block;
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
        Rectangle snakeRect = { (float)getSnakeX(), (float)getSnakeY(), (float)getSnakeWidth(), (float)getSnakeHeight() };
        DrawRectangleRec(snakeRect, getColor());
        return snakeRect;
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
private:
    int prevHeadX;
    int prevHeadY;

public:
    SnakeHead(int x, int y) : SnakeCube(x, y) {
        setSnakeX(x);
        setSnakeY(y);
    }

    void snakeGrow(std::vector<SnakeCube>& snakeBody) {
        SnakeCube& tail = snakeBody.back();
        snakeBody.push_back(SnakeCube(tail.getSnakeX(), getSnakeY()));
    }

    void update(std::vector<SnakeCube>& snakeBody) {
        int currentX = getSnakeX();
        int currentY = getSnakeY();

        movement();

        if (currentX != getSnakeX() || currentY != getSnakeY()) {
            int prevX = currentX;
            int prevY = currentY;

            for (auto& cube : snakeBody) {
                int tempX = cube.getSnakeX();
                int tempY = cube.getSnakeY();

                cube.setSnakeX(prevX);
                cube.setSnakeY(prevY);

                prevX = tempX;
                prevY = tempY;
            }
        }

        prevHeadX = currentX;
        prevHeadY = currentY;
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

    //random spawn initial spawn
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
        Rectangle appleRect = { (float)getAppleX(), (float)getAppleY(), (float)getAppleWidth(), (float)getAppleHeight() };
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
    std::vector<SnakeCube> snakeBody;

    SnakeHead snakeHead(120, 120);
    snakeBody.push_back(SnakeCube(80, 120));
    snakeBody.push_back(SnakeCube(40, 120));
    Apple apple;


    //game loop
    while (WindowShouldClose() == false) {
        BeginDrawing();

        //bakgrunden
        ClearBackground(snakeGrass);

        //snake egenskaper o sånt idk

        snakeHead.update(snakeBody);
        Rectangle snakeRect = snakeHead.drawRect();

        for (auto& cube : snakeBody) {
            cube.drawRect();
        }

        //apple
        Rectangle appleRect = apple.drawAppleRect();


        //collision apple detection
        if (CheckCollisionRecs(snakeRect, appleRect)) {
            apple.appleRespawn();
            snakeHead.snakeGrow(snakeBody);
        }
        EndDrawing();
    }   
    CloseWindow();
}

//cube spawns in the previous position