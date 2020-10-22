#include "Ship.h"


Ship::Ship() {
    shipVisual = new Rect();
    
    popinit = false;
}

void Ship::popInitialize() {
    pop = new Rect(shipVisual->getX(), shipVisual->getY(), 0.1, 0.1, 0, 1, 0);
    popinit = true;

}

bool Ship::getPop() const {
    return popinit;
}

// void Ship::dumb() {
//     std::cout <<"dumb" << std::endl;
// }