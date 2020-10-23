#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "App.h"

class Ship;

class Game {

public: 
    Game();
    void popTravel(Rect*, Ship*);
    void collisionCheck(Rect*, Rect*, Rect*, Ship*);
    void popCollisionCheck(Rect*, Rect*);
};

#endif