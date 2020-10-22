#include "Game.h" 
#include <iostream>
#include <math.h>

using namespace std;

void Game::shipCollisionCheck(Rect* spaceship, Rect* enemy) {

if (spaceship->getX() > 0 && enemy->getX() > 0 && spaceship->getY() > 0 && enemy->getY() > 0) {
    float tempX = spaceship->getX() - enemy->getX();
    float tempY = enemy->getY() - spaceship->getY();
    if (tempX <= 0.2 && tempY <= 0.2) {
        cout << "yer" << endl;
    }

}
// if (tempX <= 0.2 && tempY <= 0.2) {
//     cout << "yer" << endl;
// }

}

Game::Game() {

}