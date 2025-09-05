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
    Color snakeColor = RED;

public:
    //methods
    int movement() {
        if (IsKeyPressed(KEY_W)) {
            snakeY -= 64;
            return snakeY;
            std::cout << "pressed W key";
        }
        if (IsKeyPressed(KEY_A)) {
            snakeX -= 64;
            return snakeX;
            std::cout << "pressed A key";
        }
        if (IsKeyPressed(KEY_S)) {
            snakeY += 64;
            return snakeY;
            std::cout << "pressed S key";
        }
        if (IsKeyPressed(KEY_D)) {
            snakeX += 64;
            return snakeX;
            std::cout << "pressed D key";
        }
    }

    void eatApple() {

    }

    void collide() {

    }

    void update() {
        movement();
    }

    //get 
    int getSnakeX() {
        return snakeX;
    }
    int getSnakeY() {
        return snakeY;
    }
    bool getIsCollided() {
        return isCollided;
    }
    int getSnakeWidth() {
        return snakeWidth;
    }
    int getSnakeHeight() {
        return snakeHeight;
    }
    Color getColor() {
        return snakeColor;
    }

    //sets
    void setSnakeX(int xPos) {
        snakeX = xPos;
    }
    void setSnakeY(int yPos) {
        snakeY = yPos;
    }
    void setIsCollided(bool collided) {
        isCollided = collided;
    }   
};

class SnakeCube : SnakeHead {

};

class Apple {
    //check for snake pos
    //apple can spawn anywhere but snake location

};

int main() {
    //game definitions
    const int width = 700;
    const int height = 700;

    InitWindow(width, height, "Snake");
    SetTargetFPS(60);

    //colors
    Color snakeGrass = {161, 255, 104, 255 };


    //game loop
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(snakeGrass);

        //skapa snakeHead
        SnakeHead snake;
        DrawRectangle(snake.getSnakeX(), snake.getSnakeY(), snake.getSnakeHeight(), snake.getSnakeHeight(), snake.getColor());
        snake.update();

        EndDrawing();
    }
    CloseWindow();
}


// pink color
// Color snakeGrass = { 255, 214, 222, 255 };
//behöver ingen constructor för alla värden kommer ju startas likadant?

//theme? ändra tema (färger på orm bakgrund osv)


        /*
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