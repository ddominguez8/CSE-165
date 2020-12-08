#pragma once

#include "Rect.h"

class enemySwarm{
public:
	enemySwarm();
    Rect* enemy;

    void draw();
    void move();

    float counter;

};