#ifndef POINT_H
#define POINT_H

struct Point {
	float x;
	float y;

	float r;
	float g;
	float b;

	bool pointEraser;

	void brushPush();
	void eraserPush();
	void redPush();
	void tealPush();
	
	Point(float x, float y, float r, float g, float b);

	void draw();

};

#endif