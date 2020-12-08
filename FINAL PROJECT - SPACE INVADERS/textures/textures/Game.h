#ifndef GAME_H
#define GAME_H
#include <string>

#include "Ship.h"
#include "App.h"

class Ship;
class enemySwarm;
class Game {

public: 
    Game();
    char gameCheck;
    void popTravel(Rect*, Ship*);
    void collisionCheck(Rect*, Rect*, Rect*, Ship*);
    void popCollisionCheck(Rect*, Rect*);
    void renderText(std::string text,
    float x,
    float y,
    void* font,
    float r, 
    float g,
    float b);
    void init();
    void draw();

    Ship* ship;
    void shipMoveLeft();
    void shipMoveRight();
    TexRect* player;
    TexRect* enemyVisual;
    enemySwarm* enemies;
    void projectilePop();
    void popInit();
    void idle();
    bool popinit;
};

#endif