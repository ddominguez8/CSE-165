#include "Button.h" 
#include "Point.h" 
#include "Paint.h"
#include <deque>
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;


deque<Button*> buttons;
deque<Point*> points;


Paint::Paint() {
    tool = 'b';
    color = 'r';

    buttons.push_back(new Button('b'));
	buttons.push_back(new Button('e'));
	buttons.push_back(new Button('t'));
	buttons.push_back(new Button('r'));
    buttons.push_back(new Button('p'));
}

void Paint::renderText(string text, 
    float x, 
    float y, 
    void* font, 
    float r = 1, 
    float g = 1, 
    float b = 1) {
        //render text function received from Angelo
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / 640)*2;
    }

}

void Paint::drawButtons() {
    //drawing buttons
    for(int i = 0; i < buttons.size(); i++){
		buttons[i]->draw();
	}
    //rendering text along with buttons
    renderText("Lab 4 - NOT MS Paint", -0.4, 0.9, GLUT_BITMAP_HELVETICA_18, 0,0,0);
	renderText("Brush", buttons[0]->x+0.07, buttons[0]->y-0.1, GLUT_BITMAP_HELVETICA_18, 0,0,0);
	renderText("Eraser", buttons[1]->x+0.07, buttons[1]->y-0.1, GLUT_BITMAP_HELVETICA_18, 0,0,0);
	renderText("Colors", buttons[2]->x, buttons[2]->y+0.05, GLUT_BITMAP_HELVETICA_18, 0,0,0);


}

void Paint::drawPoints() {
    //drawing points
    for(int i = 0; i < points.size(); i++){
		points[i]->draw();
	}
}

void Paint::painting(float mousex, float mousey) {
    this->mousex = mousex;
    this->mousey = mousey;
    //checking to see if any buttons were pressed 
    for (int i = 0; i < buttons.size(); i++) {
        if ((buttons[i]->contains(mousex,mousey)) && (buttons[i]->objectSelection == 'e')) {
            eraserPush();
        }
        if ((buttons[i]->contains(mousex,mousey)) && (buttons[i]->objectSelection == 'b')) {
            brushPush();
        }
        if ((buttons[i]->contains(mousex,mousey)) && (buttons[i]->objectSelection == 'r')) {
            redPush();
        }
        if ((buttons[i]->contains(mousex,mousey)) && (buttons[i]->objectSelection == 't')) {
            tealPush();
        }
        if ((buttons[i]->contains(mousex,mousey)) && (buttons[i]->objectSelection == 'p')) {
            purplePush();
        }
    }
    //checking tools to see which one to paint with
    if (tool == 'e')   {
		points.push_front(new Point(mousex, mousey, 1, 1, 1));
    }
	if (tool == 'b' && color == 't')  {
		points.push_front(new Point(mousex, mousey, 0.6, 0.9, 0.7));
	}
    if (tool == 'b' && color == 'r')  {
		points.push_front(new Point(mousex, mousey, 1, 0, 0));
	}
    if (tool == 'b' && color == 'p')  {
		points.push_front(new Point(mousex, mousey, 0.75, 0, 1));
	}
}

void Paint::brushPush() {
    tool = 'b';
}
void Paint::eraserPush() {
    tool = 'e';
}
void Paint::redPush() {
    color = 'r';
}
void Paint::tealPush() {
    color = 't';
}
void Paint:: purplePush() {
    color = 'p';
}