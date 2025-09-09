#include <iostream>
#include <raylib.h>
#include <vector>

//g�r om snake classerna
//t.ex x och y pos ska finnas p� b�da men det g�r det inte just nu.
//referencces



//fixa constructor f�r snake cube, x och y pos
class SnakeCube {
private:
    const int block = 40;
    const int& snakeWidth = block;
    const int& snakeHeight = block;
    Color snakeColor = SKYBLUE;

    int snakeX;
    int snakeY;

public:
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
    //methods
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


        //snake egenskaper o s�nt idk
        snake.movement();
        Rectangle snakeRect = { snake.getSnakeX(), snake.getSnakeY(), snake.getSnakeHeight(), snake.getSnakeHeight() };
        DrawRectangleRec(snakeRect, snake.getColor());

        //apple
        Rectangle appleRect = { apple.getAppleX(), apple.getAppleY(), apple.getAppleWidth(), apple.getAppleHeight() };
        DrawRectangleRec(appleRect, RED);


        //collision med apple, kollision med v�gg o sigsj�lv soon
        if (CheckCollisionRecs(snakeRect, appleRect)) {
            std::cout << "hi";
            apple.appleRespawn();
            
            //spawn snake cube








         //snake coverage funktion?

                


        }

        EndDrawing();
    }   
    CloseWindow();
}

/* pink color
// Color snakeGrass = { 255, 214, 222, 255 };
//beh�ver ingen constructor f�r alla v�rden kommer ju startas likadant?

//theme? �ndra tema (f�rger p� orm bakgrund osv)


        
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

//logik vector osv
/*
�pplerespanwas, check
create a new snake cube position of the last tail segment or at the head 
push it to vector 
std::vector<SnakeCube> snakeBody; 

*/


//main class �r snake cube
// snkaehead �r en subklass av snake cube , har movmeents etc
//

/*
alla snake cube ska ha en direction som tas fr�n previous
snake head ger fixar direction f�rst, s�tts i movement, dir = right osv
skapa en lista och s�tta objekten s� att du kan anv�nda listor och n�s med index


*/