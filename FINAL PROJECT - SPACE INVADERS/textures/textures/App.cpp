#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    //We initialize an instance of the Game as gameRun so that we  can call it back as an object later
    //In the constructor we initalize all variables/objects needed for the entire game
    gameRun = new Game();
} 

void App::draw() const {
    //Draws all objects in the game
    gameRun->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);

    }
    if (key == 32) {
        //We initalize the projectile so that we can visually see it on screen
        gameRun->popInit();
        redraw();
        
    }
    if (key == 'a') {
        //Move the ship left and update the x value
        gameRun->shipMoveLeft();
        redraw();
    }
    if (key == 'd') {
        //Move the ship right and update the x value
        gameRun->shipMoveRight();
        redraw();
    }
}



void App::idle(){
    //Certain functions need to run idle so we call this 
    gameRun->idle();
    redraw();
}

App::~App(){   
    std::cout << "Exiting..." << std::endl;
}
