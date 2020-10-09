/*Collaborations 
	Eivanne Eser, Tyler Brittain, Annoj Vadodkar, Michael Ngo
	Thanks to both of them for helping me persevere despite how draining this was lol.
	Definitely a fun accomplishment
*/

#include <iostream>
#include <math.h>
#include <vector>
#include "Rect.h"

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

vector<Rect*> rects;
int countVar = 0;
int option = 0;
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

	// rects[0]->draw();


	//open this back up later
	for (int i = 0; i < rects.size(); i++) {
		rects[i]->draw();
	}

	
	// one.draw();
	// two.draw();

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

void gameCheck() {
	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[1]->gamePush && rects[1]->gamePush == rects[2]->gamePush) {
		if (rects[0]->gamePush == 'x') {//x wins first row
			cout << "X wins" << endl;
			exit (0);
		} 

	}

	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[1]->gamePush && rects[1]->gamePush == rects[2]->gamePush) {
		if (rects[0]->gamePush == 'o') { //o wins first row
				cout << "O wins" << endl;
				exit (0);
			
			}
	}

	if (rects[3]->gamePush != 'a'&& rects[3]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[5]->gamePush) {
		if (rects[3]->gamePush == 'x') {// x wins second row
			cout << "X wins" << endl;
			exit (0);
			}
	}

	if (rects[3]->gamePush != 'a'&& rects[3]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[5]->gamePush) {
	if (rects[3]->gamePush == 'o') {// o wins second row
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[6]->gamePush != 'a'&& rects[6]->gamePush == rects[7]->gamePush && rects[7]->gamePush == rects[8]->gamePush) {
	if (rects[6]->gamePush == 'x') {// x wins last row
		cout << "X wins" << endl;
		exit (0);
		}
	}

	if (rects[6]->gamePush != 'a'&& rects[6]->gamePush == rects[7]->gamePush && rects[7]->gamePush == rects[8]->gamePush) {
	if (rects[6]->gamePush == 'o') {// o wins last row
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[3]->gamePush && rects[3]->gamePush == rects[6]->gamePush) {
	if (rects[0]->gamePush == 'x') {// x wins first column
		cout << "X wins" << endl;
		exit (0);
		}
	}
	
	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[3]->gamePush && rects[3]->gamePush == rects[6]->gamePush) {
	if (rects[0]->gamePush == 'o') {// o wins first column
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[1]->gamePush != 'a'&& rects[1]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[7]->gamePush) {
	if (rects[1]->gamePush == 'x') {// x wins second column
		cout << "X wins" << endl;
		exit (0);
		}
	}

	if (rects[1]->gamePush != 'a'&& rects[1]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[7]->gamePush) {
	if (rects[1]->gamePush == 'o') {// o wins second column
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[2]->gamePush != 'a'&& rects[2]->gamePush == rects[5]->gamePush && rects[5]->gamePush == rects[8]->gamePush) {
	if (rects[2]->gamePush == 'x') {// x wins third column
		cout << "X wins" << endl;
		exit (0);
		}
	}

	if (rects[2]->gamePush != 'a'&& rects[2]->gamePush == rects[5]->gamePush && rects[5]->gamePush == rects[8]->gamePush) {
	if (rects[2]->gamePush == 'o') {// x wins third column
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[8]->gamePush) {
	if (rects[0]->gamePush == 'x') {// x wins diagonal
		cout << "X wins" << endl;
		exit (0);
		}
	}

	if (rects[0]->gamePush != 'a'&& rects[0]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[8]->gamePush) {
	if (rects[0]->gamePush == 'o') {// o wins diagonal
		cout << "O wins" << endl;
		exit (0);
		}
	}

	if (rects[2]->gamePush != 'a'&& rects[2]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[6]->gamePush) {
	if (rects[2]->gamePush == 'x') {// x wins diagonal
		cout << "X wins" << endl;
		exit (0);
		}
	}

	if (rects[2]->gamePush != 'a'&& rects[2]->gamePush == rects[4]->gamePush && rects[4]->gamePush == rects[6]->gamePush) {
	if (rects[2]->gamePush == 'o') {// x wins diagonal
		cout << "O wins" << endl;
		exit (0);
		}
	}
	if (countVar == 9) {
		cout << "Tie game!"<< endl;
		exit (0);
	}
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

	// Your code here...
	
	switch (option) {
		case 2:
		if (s == GLUT_DOWN) {
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i]->contains(mx,my)) {
				if ((countVar % 2 == 0)) {
					rects[i]->select('x');
					countVar++;
					break;
				}
				else if ((countVar % 2 != 0)) {
					rects[i]->select('o');
					countVar++;
					break;
				}
			}
		}
	}
		break;
		case 1: 

		if (s == GLUT_DOWN) {
		for (int i= 0; i < rects.size(); i++) {
			if (rects[i]->contains(mx,my)) {
				if ((countVar % 2 == 0)) {
					rects[i]->select('x');
					countVar++;
					break;
				}
			}
		}
		}

		for (int j = 0; j < rects.size(); j++) {
			if ((countVar % 2 != 0)) {
				if (rects[j]->gamePush == 'a') {
					rects[j]->select('o');
					countVar++;
					break;
				}
			}
		}

		break;
		default: 
		break;
	}


	gameCheck();
	// if (one.contains(mx,my)) {
	// 	one.select();
	// }
	// else {
	// 	one.deselect();
	// }

	// if (two.contains(mx,my)) {
	// 	two.select();
	// }
	// else {
	// 	two.deselect();
	// }

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
	
	rects.push_back(new Rect(-0.8, 0.8, 0.5, 0.5));
	rects.push_back(new Rect(-0.2, 0.8, 0.5, 0.5));
	rects.push_back(new Rect(0.4, 0.8, 0.5, 0.5));

	rects.push_back(new Rect(-0.8, 0.2, 0.5, 0.5));
	rects.push_back(new Rect(-0.2, 0.2, 0.5, 0.5));
	rects.push_back(new Rect(0.4, 0.2, 0.5, 0.5));

	rects.push_back(new Rect(-0.8, -0.4, 0.5, 0.5));
	rects.push_back(new Rect(-0.2, -0.4, 0.5, 0.5));
	rects.push_back(new Rect(0.4, -0.4, 0.5, 0.5));

	cout << "Would you like two player mode or play against a computer?" << endl;
	cout << "Please enter 1 for one player mode and play against a computer or 2 for two player mode: ";
	cin >> option;

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
