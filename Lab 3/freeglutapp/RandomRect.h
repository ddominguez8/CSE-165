#ifndef RANDOMRECT_H
#define RANDOMRECT_H

struct RandomRect {
    float x;
    float y;
    float w;
    float h;

    float red;
    float green;
    float blue;

    bool contains(float x, float y);


    bool selected;
    void select();
    void deselect();
    void contains();
    bool corner(float x, float y);

    void draw();
    

    RandomRect(float x, float y, float w, float h, float red, float green, float blue);

};

#endif