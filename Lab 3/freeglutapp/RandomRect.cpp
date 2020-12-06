#include "RandomRect.h"
#include <cstdlib>
#include <iostream> 

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

RandomRect::RandomRect(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

    selected = false;
}


void RandomRect::draw() {
	if (selected) {

		//this creates the line around the edges
		glColor3f(1, 1, 1);

		glBegin(GL_LINES); 

		glVertex3f(x, y, 0.1);
		glVertex3f(x+w, y, 0.1);

		glVertex3f(x+w, y, 0.1);
		glVertex3f(x+w, y-h, 0.1);

		glVertex3f(x+w, y-h, 0.1);
		glVertex3f(x, y-h, 0.1);

		glVertex3f(x, y-h, 0.1);
		glVertex3f(x,y,0.1);

		glEnd();

		glColor3f(red, green, blue);

        glBegin(GL_POLYGON);

        glVertex3f(x, y, 0.1);
        glVertex3f(x+w, y, 0.1);
        glVertex3f(x+w, y-h, 0.1);
        glVertex3f(x, y-h, 0.1);

        glEnd();
	}
	else {
		
		glColor3f(red, green, blue);

        glBegin(GL_POLYGON);

        glVertex3f(x, y, 0.1);
        glVertex3f(x+w, y, 0.1);
        glVertex3f(x+w, y-h, 0.1);
        glVertex3f(x, y-h, 0.1);

        glEnd();
	}
}

void RandomRect::select() {
    selected = true;
}

void RandomRect::deselect() {
	selected = false;
}
bool RandomRect::corner(float x, float y){
    return (x > (this->x  + this->w* 0.3) && x < this->x + this->w && (y < this->y - this->h*0.7) && y > this->y - this->h);
}
bool RandomRect::contains(float x, float y) {
	return x > this->x && x < this->x + this->w && y < this->y && y > this->y - this->h;
}