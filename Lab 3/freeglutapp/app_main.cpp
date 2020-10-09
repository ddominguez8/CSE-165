/*
David Dominguez CSE 165 - Lab 3

COLLABORATIONS: 
Tyler Brittain: Helped explain the concept of how to get the contain corner
Eivanne Eser: Helped explain how rectangles could overlap one another
*/

#include <iostream>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include "RandomRect.h"


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;


// Store the width and height of the window
int width = 640, height = 640;

// Rect one;
// Rect two(-0.5, 0, 0.3, 0.3, 1, 1, 0);

deque<RandomRect*> rects;
float xRelative;
float yRelative;
//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// for(auto i = rects.begin(); i != rects.end(); i++) {
	// 	(*i)->draw();
	// }
	for (int i = 0; i < rects.size(); i++) {
		rects[i]->draw();
	}

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}

//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);
	if (s == GLUT_DOWN) { 
		for (auto i = rects.begin(); i!=rects.end(); i++) {
			if ((*i)->contains(mx,my)) { 
				(*i)->select();
				//rects.erase(i);
				rects.push_front(*i);
				xRelative = rects[0]->x - mx;
				yRelative = rects[0]->y - my;
				break;
			}
			else {
				(*i)->deselect();
			}
		}
	}
	
	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...
		if (rects[0]->contains(mx,my) && !rects[0]->corner(mx,my)) {
			rects[0]->x = mx + xRelative;
			rects[0]->y = my + yRelative;
		}
		if (rects[0]->corner(mx,my) && rects[0]->selected) {
			rects[0]->w = mx - rects[0]->x;
			rects[0]->h = -my + rects[0]->y;
		}
		if ((rects[0]->y - rects[0]->h) > my && (rects[0]->x + rects[0]->w) < mx && rects[0]->selected) {
			rects[0]->w = mx - rects[0]->x;
			rects[0]->h = -my + rects[0]->y;
		} 
		// if ((rects[0]->y - rects[0]->h) < my && (rects[0]->x + rects[0]->w) > mx && rects[0]->selected) {
		// 	rects[0]->w = mx - rects[0]->x;
		// 	rects[0]->h = -my + rects[0]->y;
		// } 
	// rects[0]->x = mx - rects[0]->w/2;
	// rects[0]->y = my - rects[0]->h/2;
	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	// Define what should happen for a given key press 
	switch (key) {
	// case 'w':
	// 	one.moveUp();
	// 	break;
	// case 's':
	// 	one.moveDown();
	// 	break;
	// case 'a':
	// 	one.moveLeft();
	// 	break;
	// case 'd':
	// 	one.moveRight();
	// 	break;						
		// Escape was pressed. Quit the program
	case 27:
		exit(0);
		break;
		// More cases here if you need...
	}
	// After all the state changes, redraw the scene
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	srand (time(NULL));
	//this formula for the random float number was found via: 
	//https://stackoverflow.com/questions/686353/random-float-number-generation
	//float r3 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
	float x = (-0.9)+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.7-(-0.9))));
	float y = x;

	float h = 0.2+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.6-0.2)));
	float w = h;
	
	float red = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float green = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float blue = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	
	rects.push_back(new RandomRect(x,y,w,h,red,green,blue));
	float x2 = (-0.9)+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.7-(-0.9))));
	float y2 = x2;

	float h2 = 0.2+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.6-0.2)));
	float w2 = h2;
	
	float red2 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float green2 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float blue2 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	rects.push_back(new RandomRect(x2,y2,w2,h2,red2,green2,blue2));
	float x3 = (-0.9)+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.7-(-0.9))));
	float y3 = x3;

	float h3 = 0.2+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.6-0.2)));
	float w3 = h3;
	
	float red3 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float green3 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	float blue3 = 0.1+ static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.9-0.1)));
	rects.push_back(new RandomRect(x3,y3,w3,h3,red3,green3,blue3));
	
	

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	// Start with a slightly smaller window (bug in macOS Catalina)
	glutInitWindowSize(width-1, height-1);

	// Create the window
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);
    
	// Resize your window to the desired size (bug in macOS Catalina)
    glutReshapeWindow(width, height);

	// Start the main loop
	glutMainLoop();
}
