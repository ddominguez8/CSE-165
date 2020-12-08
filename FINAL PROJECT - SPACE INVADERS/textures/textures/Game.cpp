#include "Game.h" 
#include <iostream>
#include <math.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

void Game::draw() {
    //Draws the player 
    player->draw(0);
    //Draws the visual representation of the enemy
    enemyVisual->draw();
    /*This does two things. 1- Checks that the projectile has been initalized via popInit()
    2-checks the boundary so that it doesn't infinitely keep drawing itself out of bounds*/
    if (ship->getPop() == true && ship->pop->getY() < 1) {
        ship->pop->draw(0);
    }
    //The variable gameCheck will provide the information on whether or not the game is continuing or has ended.
    //The renderText will display the game result accordingly.
    if (gameCheck == 'o') {
        renderText("GAME OVER", -0.2, 0, GLUT_BITMAP_TIMES_ROMAN_24, 1,1,1);
    }
    if (gameCheck == 'u') {
        renderText("YOU WIN", -0.2, 0, GLUT_BITMAP_TIMES_ROMAN_24, 1,1,1);
    }
}

void Game::popInit() {
    //Initializes the projectile
    ship->popInitialize();
}

void Game::shipMoveLeft() {
    //Moves the ship to the left then updates the x value
    ship->shipVisual->moveLeft();
    player->setX(ship->shipVisual->getX());
}

void Game::shipMoveRight() {
    //Moves the ship to the right then updates the x value
    ship->shipVisual->moveRight();
    player->setX(ship->shipVisual->getX());
}

void Game::idle() {
    //The projectile will move in a smooth motion after it has been initalized
    popTravel(ship->pop, ship);
    //This constantly checks the status of the game based on a collision
    collisionCheck(ship->shipVisual, enemies->enemy, ship->pop, ship);
    //Moves the enemy down based on the y value decrement
    enemies->move();
    //Sets the visual of the enemy y position
    enemyVisual->setY(enemies->enemy->getY());
}

void Game::collisionCheck(Rect* spaceship, Rect* enemy, Rect* pop, Ship* ship) {
//These are all sides of a rectangle collision check
float compareX1 = spaceship->getX() + spaceship->getW();
float compareX2 = enemy->getX() + enemy->getW();

float compareY1 = spaceship->getY() + spaceship->getH(); 
float compareY2 = enemy->getY() + enemy->getH();

//This simply compares the player position with the spaceship position and if all conditions pass, there is a collision 
//and the game is over
if ((compareX1 > enemy->getX()) && (compareX2 > spaceship->getX()) && (compareY1 > enemy->getY()) && (compareY2 > spaceship->getY())){
   gameCheck = 'o';
}

//This checks to see if the projectile has collided with the enemy and if so, the game is over
if (ship->popinit) {
float compareX3 = pop->getX() + enemy->getW();
float compareX4 = enemy->getX() + enemy->getW();

float compareY3 = pop->getY() + enemy->getH(); 
float compareY4 = enemy->getY() + enemy->getH();

if ((compareX3 > enemy->getX()) && (compareX4 > pop->getX()) && (compareY3 > enemy->getY()) && (compareY4 > pop->getY())){
   gameCheck = 'u';
}
}

}

void Game::popTravel(Rect* projectile, Ship* ship) {
    //First it checks if the projectile has been initalized, then adds onto the current y value of the projectile and sets it.
    if (ship->popinit) {
    float temp = projectile->getY() + 0.005;
    projectile->setY(temp); 
    }
   
}

void::Game::renderText(string text,
float x,
float y,
void* font,
float r = 1, 
float g = 1,
float b = 1) {
    glColor3f(r,g,b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w/640)*2;
    }
}

Game::Game() {
    //The default gameCheck value is r to make sure it cannot be a premature game ending.
    gameCheck = 'r';
    //Initialization of all objects and variables
    ship = new Ship();
    player = new TexRect ("player.jpg",ship->shipVisual->getX(),ship->shipVisual->getY(),ship->shipVisual->getW(), ship->shipVisual->getH());
    enemies = new enemySwarm();
    enemyVisual = new TexRect ("space invader.jpg", enemies->enemy->getX(), enemies->enemy->getY(), enemies->enemy->getW(), enemies->enemy->getH());
}