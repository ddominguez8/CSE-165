#ifndef NOTMSPAINT_H
#define NOTMSPAINT_H

struct Point {
	float x;
	float y;

	float r;
	float g;
	float b;


	Point(float x, float y, float r, float g, float b);

	void draw();

};

#endif