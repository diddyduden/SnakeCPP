#include <iostream>
#include <raylib.h>
#include <vector>

class SnakeCube {
private:
    const int block = 40;
    const int snakeWidth = block;
    const int snakeHeight = block;
    Color snakeColor = SKYBLUE;

    int snakeX;
    int snakeY;

    //1 = up, höger
    int dirX;
    int dirY;

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

    int getDirX() { return dirX; }
    int getDirY() { return dirY; }

    //sets
    void setSnakeX(int xPos) { snakeX = xPos; }
    void setSnakeY(int yPos) { snakeY = yPos; }

    void setDirX(int x) { dirX = x; }
    void setDirY(int y) { dirY = y; }
};

class SnakeHead : public SnakeCube {
private:
    //int prevHeadX;
    //int prevHeadY;
    
public:
    SnakeHead(int x, int y) : SnakeCube(x, y) {
        setSnakeX(x);
        setSnakeY(y);
    }

    void snakeGrow(std::vector<SnakeCube>& snakeBody) {
        SnakeCube& tail = snakeBody.back();

        int newX = tail.getSnakeX() - tail.getDirX();
        int newY = tail.getSnakeY() - tail.getDirY();

        snakeBody.push_back(SnakeCube(newX, newY));
    }

    void update(std::vector<SnakeCube>& snakeBody) {
        int currentX = getSnakeX();
        int currentY = getSnakeY();

        int currentDirX = getDirX();
        int currentDirY = getDirY();

        movement();

        if (currentX != getSnakeX() || currentY != getSnakeY()) {
            int prevX = currentX;
            int prevY = currentY;

            int prevDirX = currentDirX;
            int prevDirY = currentDirY;

            for (auto& cube : snakeBody) {
                int tempX = cube.getSnakeX();
                int tempY = cube.getSnakeY();

                int tempDirX = cube.getDirX();
                int tempDirY = cube.getDirY();

                cube.setSnakeX(prevX);
                cube.setSnakeY(prevY);

                cube.setDirX(prevDirX);
                cube.setDirY(prevDirY);

                prevX = tempX;
                prevY = tempY;

                prevDirX = tempDirX;
                prevDirY = tempDirY;
            }
        }
        //behövs inte?
        //prevHeadX = currentX;
        //prevHeadY = currentY;
    }

    void movement() {
        if (IsKeyPressed(KEY_W)) {
            setSnakeY(getSnakeY() - getBlock());
            std::cout << getSnakeY() << std::endl;
            setDirX(0);
            setDirY(-getBlock());
        }
        if (IsKeyPressed(KEY_A)) {
            setSnakeX(getSnakeX() - getBlock());
            std::cout << getSnakeX() << std::endl;
            setDirX(-getBlock());
            setDirY(0);
        }
        if (IsKeyPressed(KEY_S)) {
            setSnakeY(getSnakeY() + getBlock());
            std::cout << getSnakeY() << std::endl;
            setDirX(0); 
            setDirY(getBlock());
        }
        if (IsKeyPressed(KEY_D)) {
            setSnakeX(getSnakeX() + getBlock());
            std::cout << getSnakeX() << std::endl;
            setDirX(getBlock());
            setDirY(0);
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

        //draw cubes + if collision with itself
        for (auto& cube : snakeBody) {
            Rectangle cubeRect = cube.drawRect();

            //om du går ut ur mappen eller collision med sig själv
            if (CheckCollisionRecs(cubeRect, snakeRect) || 
                snakeHead.getSnakeX() > width - snakeHead.getBlock()  ||
                snakeHead.getSnakeX() < 0 ||
                snakeHead.getSnakeY() > height - snakeHead.getBlock() ||
                snakeHead.getSnakeY() < 0) {

                std::cout << "u dead";
            }
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

//play audio when moving, eating, death
//when dead -> start new game?
//apple cant spawn on snake place ? how to do?
//new vector for all free squares, have apple spawn in only free squares.