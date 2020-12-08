#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect: public Shape {
protected:
	float x;
	float y;
	float w;
	float h;


public:
	float r;
	float g;
	float b;
	
	Rect();

	Rect(float, float, float, float);

	Rect(float, float, float, float, float, float, float);

	Rect(const Rect&);

	bool operator== (const Rect&);

	~Rect();

	void draw(float z) const;

	bool contains(float, float) const;

	float getX() const ;

	float getY() const ;

	float getW() const ;

	float getH() const ;

	float getR() const ;

	float getG() const ;

	float getB() const ;

	void setX(float x);

	void setY(float y);

	void setW(float w);

	void setH(float h);

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};




#endif
