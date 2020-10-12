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

Button::Button(char objectSelection){
	//default constructor passing objectSelection which creates specific objects
	switch (objectSelection) {
		case 'b': 
		x = -0.8;
		y = 0.8;
		w = 0.3;
		h = 0.15;
		selected = false;
		this->objectSelection = objectSelection;

		break;
		case 'e': 
		x = -0.4;
		y = 0.8;
		w = 0.3;
		h = 0.15;
		selected = false;
		this->objectSelection = objectSelection;

		break;

		case 't': 
		x = 0.8;
		y = 0.8;
		w = 0.15;
		h = 0.3; 
		red = 0.6;
		green = 0.9;
		blue = 0.7;
		selected = false;
		this->objectSelection = objectSelection;

		break;

		case 'r':
		x = 0.8;
		y = 0.4;
		w = 0.15;
		h = 0.3;
		red = 1;
		green = 0;
		blue = 0;

		selected =false;
		this->objectSelection = objectSelection;

		break;

		case 'p': 
		x = 0.8;
		y = 0;
		w = 0.15;
		h = 0.3;
		red = 0.75;
		green = 0;
		blue = 1;

		selected = false;
		this->objectSelection = objectSelection;

		default:
		break;
	}
}

bool Button::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Button::draw(){
	//draw brush and eraser buttons
	if ((objectSelection == 'b') || (objectSelection == 'e')){
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
		
	}
	//draw color buttons
	if ((objectSelection == 't') || (objectSelection == 'r') || (objectSelection == 'p')){
		glColor3f(red, green, blue);
		glBegin(GL_POLYGON); 

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();
	}
}
