#ifndef GAME_H
#define GAME_H

#include "Ship.h"

class Game {

public: 
    Game();
    void shipCollisionCheck(Rect*, Rect*);
};

#endif