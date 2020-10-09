#include "Rect.h"
#include <math.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

//inside Rect struct, what function are we going to implement? Rect().
//Separating declarations from implementations
Rect::Rect() {
    x = 0;
    y = 0;
    red = 1;
    green = 0.55;
    blue = 0;

    w = 0.3;
    h = 0.3;

    selected = false;
    gamePush = 'a';

}

Rect::Rect(float x, float y, float w, float h) {
    //anytime a parameter and a variable have the same name, use this->name to specify the variable being inserted.
    //in this case, x and y by itself refers to the parameter, while this->x and this->y refer to the variable declared in the object
    this->x = x;
    this->y = y;
    red = 1;
    green = 0.55;
    blue = 0;

    this->w = w;
    this->h = h;

    selected = false;
    gamePush = 'a';

}

Rect::Rect(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

    selected = false;
    gamePush = 'a';
}

void Rect::draw() {
    if (selected) {
        if (gamePush == 'x'){ 
            //This creates the 'X' in our tic-tac-toe game
            glColor3f(1, 1, 1);

            glBegin(GL_LINES); 
    
            glVertex3f(x, y, 0.1);
            glVertex3f(x+w, y-h, 0.1);

            glVertex3f(x+w, y, 0.1);
            glVertex3f(x, y-h, 0.1);

            glEnd();

            glColor3f(red, green, blue);

            glBegin(GL_POLYGON);

            glVertex3f(x, y, 0.1);
            glVertex3f(x+w, y, 0.1);
            glVertex3f(x+w, y-h, 0.1);
            glVertex3f(x, y-h, 0.1);

            glEnd();
        }
        else if (gamePush == 'o') {
            //creates the 'O'
            glColor3f(1,1,1);
            glBegin (GL_POINTS); 

            float theta = 0;
            float inc = M_PI/300; 
            for (theta; theta <=2*M_PI; theta += inc) {
            glVertex3f((cos(theta)*.2 + x + (w/2)), (sin(theta)*.2 + y - (h/2)), 0.1);
            }
            glEnd(); 
            
            glColor3f(red, green, blue);

            glBegin(GL_POLYGON);

            glVertex3f(x, y, 0.1);
            glVertex3f(x+w, y, 0.1);
            glVertex3f(x+w, y-h, 0.1);
            glVertex3f(x, y-h, 0.1);

            glEnd();
        }
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

bool Rect::contains(float x, float y) {
    return x > this->x && x < this->x + this->w && y < this->y && y > this->y - this->h;
}

void Rect::moveUp() {
    y+=0.05;
}
void Rect::moveDown(){
    y-=0.05;
}
void Rect::moveLeft(){
    x-=0.05;
}
void Rect::moveRight(){
    x+=0.05;
}

void Rect::select(char value) {
    if (gamePush == 'a') {
        selected = true;
        gamePush = value;
    }
}

void Rect::deselect() {
    selected = false;
}