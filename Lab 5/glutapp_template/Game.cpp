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

void Game::collisionCheck(Rect* spaceship, Rect* enemy, Rect* pop, Ship* ship) {

float compareX1 = spaceship->getX() + spaceship->getW();
float compareX2 = enemy->getX() + enemy->getW();

float compareY1 = spaceship->getY() + spaceship->getH(); 
float compareY2 = enemy->getY() + enemy->getH();

// float enemyLeftSide = (spaceship->getX() + spaceship->getW()) - enemy->getX();

// float compareTopRightX = (spaceship->getX() + spaceship->getW()) - (enemy->getX() + enemy->getW());


if ((compareX1 > enemy->getX()) && (compareX2 > spaceship->getX()) && (compareY1 > enemy->getY()) && (compareY2 > spaceship->getY())){
   gameCheck = 'o';
}

//projectile collision check
if (ship->popinit) {
float compareX3 = pop->getX() + enemy->getW();
float compareX4 = enemy->getX() + enemy->getW();

float compareY3 = pop->getY() + enemy->getH(); 
float compareY4 = enemy->getY() + enemy->getH();

if ((compareX3 > enemy->getX()) && (compareX4 > pop->getX()) && (compareY3 > enemy->getY()) && (compareY4 > pop->getY())){
   gameCheck = 'u';
}
}


// if (spaceship->getX() >= 0 && enemy->getX() >= 0) {
//     if (enemyLeftSide < 0.19) {
//         cout << "yerleftside" << endl;
//     }
// }



//old implementations below

  // float tempX = spaceship->getX() - enemy->getX();
    // float tempY = enemy->getY() - spaceship->getY();
    // if (tempX <= 0.2 && tempY <= 0.2) {
    //     cout << "yer" << endl;
    // }
// if (tempX <= 0.2 && tempY <= 0.2) {
//     cout << "yer" << endl;
// }

}

void Game::popTravel(Rect* projectile, Ship* ship) {
    if (ship->popinit) {
    float temp = projectile->getY() + 0.1;
    projectile->setY(temp); 
    }
   
}

void Game::popCollisionCheck(Rect* pop, Rect* enemy) {

float compareX1 = pop->getX() + pop->getW();
float compareX2 = enemy->getX() + enemy->getW();

float compareY1 = pop->getY() + pop->getH(); 
float compareY2 = enemy->getY() + enemy->getH();

if ((compareX1 > enemy->getX()) && (compareX2 > pop->getX()) && (compareY1 > enemy->getY()) && (compareY2 > pop->getY())){
   //
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
    gameCheck = 'r';
}