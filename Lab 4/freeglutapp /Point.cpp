#include "Point.h"
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std; 

Point::Point(float x, float y, float r, float g, float b){
	this->x = x;
	this->y = y;

	this->r = r;
	this->g = g;
	this->b = b;
}

void Point::draw() {
    if (pointEraser) {
        cout << "erasing" << endl;
        glColor3f(1, 1, 1);
        glPointSize(10);

        glBegin(GL_POINTS);

        glVertex2f(x, y);

        glEnd();
    }
    else{
        cout << "brushing" << endl;
        glColor3f(r, g, b); 
        glPointSize(10);

        glBegin(GL_POINTS);

        glVertex2f(x,y);

        glEnd();
    }
}

// void Point::brushPush() {
//     brush = true;
//     pointEraser = false;
// }
// void Point::eraserPush() {
//     eraser = true;
//     brush = false;
// }
// void Point::redPush() {
//     red = true;
//     teal = false;
// }
// void Point::tealPush() {
//     teal = true;
//     red = false;
// }