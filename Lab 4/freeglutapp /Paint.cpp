#include "Button.h" 
#include "Point.h" 
#include "Paint.h"
#include <deque>
#include <iostream>

using namespace std;


deque<Button*> buttons;
deque<Point*> points;

Paint::Paint() {
    // bool eraser = false;
    // bool brush = true;
    // bool teal = false;
    // bool red = true;
    char tool = 'b';
    char color = 'r';

    buttons.push_back(new Button('b'));
	buttons.push_back(new Button('e'));
	buttons.push_back(new Button('t'));
	buttons.push_back(new Button('r'));
}


void Paint::drawButtons() {
    for(int i = 0; i < buttons.size(); i++){
		buttons[i]->draw();
	}
}

void Paint::drawPoints() {
    for(int i = 0; i < points.size(); i++){
		points[i]->draw();
	}
}

void Paint::painting(float mousex, float mousey) {
    this->mousex = mousex;
    this->mousey = mousey;
    if ((tool == 'b') && (color == 'r')) {
		points.push_front(new Point(mousex, mousey, 1, 0, 0));
        cout << "red and brush called" << endl; 
    }
    if (tool == 'e'){
		points.push_front(new Point(mousex, mousey, 1, 1, 1));
	}
	
	if (tool == 'b' && color == 't')  {
		points.push_front(new Point(mousex, mousey, 0.6, 0.9, 0.7));
	}
}

void Paint::brushPush() {
    brush = true;
    eraser = false;
}
void Paint::eraserPush() {
    eraser = true;
    brush = false;
}
void Paint::redPush() {
    red = true;
    teal = false;
}
void Paint::tealPush() {
    teal = true;
    red = false;
}