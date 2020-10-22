#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"
#include "Ship.h"
#include "Game.h"

class Ship; //previously this wasn't included but help was received from an online forum
//linked here: https://stackoverflow.com/questions/17333934/class-name-does-not-name-a-type-in-c

class Game;

class App: public GlutApp {
    
    Rect* enemyRect;
    bool popinit;
public:
    Ship* ship;
    Game* gameRun;
    void projectilePop();
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    ~App();
    
};

#endif
