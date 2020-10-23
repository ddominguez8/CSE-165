#include <iostream>
#include "App.h"
#include "Ship.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    ship = new Ship();
    //ship = new Rect();
    enemyRect = new Rect (0.3, 0.8, 0.2, 0.2, 1, 0, 0);
    gameRun = new Game();
    
}

void App::draw() {
    ship->shipVisual->draw();
    
    enemyRect->draw();
    if (ship->getPop() == true && ship->pop->getY() < 1) { //add functionality for boundary or collision check
        ship->pop->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);

    }
    if (key == 32) {
        ship->popInitialize();
        gameRun->popTravel(ship->pop, ship);
        redraw();
        
    }
    if (key == 'w') {
        //move up
        ship->shipVisual->moveUp();
        gameRun->popTravel(ship->pop, ship);
        redraw();
        gameRun->collisionCheck(ship->shipVisual, enemyRect, ship->pop, ship);
    }
    if (key == 'a') {
        //move left
        ship->shipVisual->moveLeft();
        gameRun->popTravel(ship->pop, ship);
        redraw();
        gameRun->collisionCheck(ship->shipVisual, enemyRect, ship->pop, ship);
        //gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
    if (key == 's') {
        //move down
        ship->shipVisual->moveDown();
        gameRun->popTravel(ship->pop, ship);
        redraw();
        gameRun->collisionCheck(ship->shipVisual, enemyRect, ship->pop, ship);
        //gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
    if (key == 'd') {
        //move right
        ship->shipVisual->moveRight();
        gameRun->popTravel(ship->pop, ship);
        redraw();
        gameRun->collisionCheck(ship->shipVisual, enemyRect, ship->pop, ship);
        //gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
}
void App::appIdle() {
    this->idle();
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete ship;
    delete enemyRect;
}


