#ifndef PAINT_H
#define PAINT_H

struct Paint {
    float mousex; 
    float mousey;

    void create(); 
    Paint();
    void drawButtons();
    void drawPoints();
    void painting(float mousex, float mousey);
    bool eraser;
    bool brush;
    bool red;
    bool teal;
    
    char tool;
    char color;

    void eraserPush();
    void brushPush();
    void redPush();
    void tealPush();
};

#endif