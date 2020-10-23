/*
Collaborators: Tyler Brittain, Ivan Eser
Ivan helped by drawing out rects and showing their relations to one
another during a collision.
*/
#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 640, 640, "GLUT App");

    app->run();
}
