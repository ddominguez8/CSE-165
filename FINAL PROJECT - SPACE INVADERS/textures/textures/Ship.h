#ifndef SHIP_H
#define SHIP_H

#include "Rect.h"
#include "App.h"

class Ship: public Rect {

public:
    bool popinit;
    Rect* pop;
    void popInitialize();
    Rect* shipVisual;
    bool getPop() const ;

    Ship();
};

#endif