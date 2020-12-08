#include <math.h>
#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rect::Rect(){
	x = -0.1;
	y = -0.6;
	r = 1;
	g = 1;
	b = 1;

	w = 0.2;
	h = 0.2;
}

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	r = 1;
	g = 1;
	b = 1;

	this->w = w;
	this->h = h;
}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;

	this->r = r;
	this->g = g;
	this->b = b;

	this->w = w;
	this->h = h;
}

Rect::Rect(const Rect& other){
	x = other.x;
	y = other.y;

	r = other.r;
	g = other.g;
	b = other.b;

	w = other.w;
	h = other.h;
}

bool Rect::operator== (const Rect& other){
	return 	x == other.x && 
			y == other.y && 
			h == other.h && 
			r == other.r && 
			g == other.g && 
			b == other.b;
}

Rect::~Rect(){
	// There is nothing to do here for now...
}

bool Rect::contains(float x, float y) const {
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}


void Rect::draw(float z) const {

	glColor3f(r, g, b);
	
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

float Rect::getX() const {
	return x;
}

float Rect::getY() const {
	return y;
}

float Rect::getW() const {
	return w;
}

float Rect::getH() const {
	return h;
}

float Rect::getR() const {
	return r;
}

float Rect::getG() const {
	return g;
}

float Rect::getB() const {
	return b;
}

void Rect::setX(float x){
	this->x = x;
}

void Rect::setY(float y){
	this->y = y;
}

void Rect::setW(float w){
	this->w = w;
}

void Rect::setH(float h){
	this->h = h;
}

void Rect::moveUp() {
	y+=0.1;
}

void Rect::moveDown() {
	y-=0.1;
}

void Rect::moveLeft() {
	x-=0.1;
}

void Rect::moveRight() {
	x+=0.1;
}