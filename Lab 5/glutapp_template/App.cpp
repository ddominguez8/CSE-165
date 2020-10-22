#include <iostream>
#include "App.h"
#include "Ship.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    ship = new Ship();
    //ship = new Rect();
    enemyRect = new Rect (-0.1, 0.8, 0.2, 0.2, 1, 0, 0);
    gameRun = new Game();
    
}

void App::draw() {
    ship->shipVisual->draw();
    // ship2->draw();
    //Ship::ship->draw();
    
    enemyRect->draw();
    if (ship->getPop() == true) { //add functionality for boundary or collision check
        ship->pop->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);

    }
    if (key == 32) {
        ship->popInitialize();
        redraw();
    }
    if (key == 'w') {
        //move up
        ship->shipVisual->moveUp();
        redraw();
        gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
    if (key == 'a') {
        //move left
        ship->shipVisual->moveLeft();
        redraw();
        gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
    if (key == 's') {
        //move down
        ship->shipVisual->moveDown();
        redraw();
        gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
    if (key == 'd') {
        //move right
        ship->shipVisual->moveRight();
        redraw();
        gameRun->shipCollisionCheck(ship->shipVisual, enemyRect);
    }
}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete ship;
    delete enemyRect;
}


