#include <iostream>
#include "Button.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

Button::Button(){
	x = -0.4;
	y = 0.75;
	red = 0;
	green = 0;
	blue = 0;

	w = 0.3;
	h = 0.15;

	selected = false;
}

Button::Button(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 0;
	green = 0;
	blue = 0;

	this->w = w;
	this->h = h;

	selected = false;

	
}

Button::Button(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;

	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

	selected = false;
}

bool Button::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Button::select(){
	selected = true;
}

void Button::deselect(){
	selected = false;
}

/*void Button::renderText(
    string text, 
    float x, 
    float y, 
    void* font, 
    float r = 1, 
    float g = 1, 
    float b = 1
	){
	int width = 640;
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / width)*2;
    }
}*/

void Button::draw(){

	if (selected){

		glColor3f(0,0,0);
		glBegin(GL_LINES);

		glVertex2f(x, y);
		glVertex2f(x+w, y);

		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);
		
		glVertex2f(x, y-h);
		glVertex2f(x, y);

		glEnd();
		
		glColor3f(red, green, blue);

		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();

		
	}
	else{
		glColor3f(red, green, blue);

		glBegin(GL_LINES);

		glVertex2f(x, y);
		glVertex2f(x+w, y); 

		glVertex2f(x+w, y);
		glVertex2f(x+w,y-h);

		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glVertex2f(x, y-h);
		glVertex2f(x,y);

		glEnd();

		//renderText("Lab 4 - NOT MS Paint", (x + 0.1), (y + 0.1), GLUT_BITMAP_HELVETICA_18, 0,0,0);
	}
}
