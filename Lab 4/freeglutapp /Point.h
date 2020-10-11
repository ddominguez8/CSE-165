#ifndef POINT_H
#define POINT_H

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