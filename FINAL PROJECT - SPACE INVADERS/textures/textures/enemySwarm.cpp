#include "enemySwarm.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

enemySwarm::enemySwarm() {
    enemy = new Rect(0, 0.8, 0.2, 0.2, 1, 0, 0);
    counter = 0.0;
}

void enemySwarm::draw() {
    enemy->draw(0);
}

void enemySwarm::move() {
    
    if (enemy->getY() > -0.5) {
        enemy->setY(enemy->getY() - 0.001);
    }

            // if (counter < 0.6) {
        //     counter+=0.1;
        //     enemy->setX(enemy->getX() + counter);
        // }
        // else if (counter > -0.6) {
        //     counter-=0.1;
        //     enemy->setX(enemy->getX() + counter);
        // }

    // while (enemy->getY() > -0.5) {
    //     for (float i = 0; enemy->getX() < 0.6; i+=0.1) {
    //         enemy->setX(enemy->getX() + i);
    //     }
    //     enemy->setY(enemy->getY() - 0.1);
    //     for (float j = 0; enemy->getY() > -0.6; j-=0.1) {
    //         enemy->setX(enemy->getX() + j); 
    //     }
    //     enemy->setY(enemy->getY() - 0.1);
    //     move();
    // }

}
