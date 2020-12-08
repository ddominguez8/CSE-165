#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Game.h"
#include "enemySwarm.h"

class Game;

class App: public GlutApp {
public:

    Game* gameRun;

    friend void timer(int id);
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void idle();
    
    ~App();
};

#endif
