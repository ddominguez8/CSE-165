#ifndef PAINT_H
#define PAINT_H
#include <string>

struct Paint {
    float mousex; 
    float mousey;

    void create(); 
    Paint();
    void drawButtons();
    void drawPoints();
    void painting(float mousex, float mousey);
    
    char tool;
    char color;

    void eraserPush();
    void brushPush();
    void redPush();
    void tealPush();
    void purplePush();

    void renderText(
    std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b
    );
};

#endif