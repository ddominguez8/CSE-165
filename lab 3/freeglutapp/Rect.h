//This Rect.h was made possible with help from Angelo Kyrilov
//Notes for understanding what our .h file does: 
/*
.h files are meant for defining certain objects with given attributes.
do not put using namespace std; or else it will force the whole .cpp file to be ran in that namespace, regardless
of what namespace was declared before

Why do the if statement and define below?  
"It ensures that if you have it included it doesn't get included again, because that will result in 
duplicate definitions, and linker will complain. Protects it from being included multiple times."
*/

#ifndef RECT_H
#define RECT_H

//Why not class? The default visibility of structs are completely public! 
struct Rect {
    //We don't specify default values in this file
	float x;
	float y;

	
    float red;
	float green; 
	float blue;

    //this replaced eL
	float w;
	float h;


    bool playeroneselected;

    bool selected;

    char gamePush;

	Rect(); // This is a default constructor (takes no parameters)
    
    //Different type of constructors we specify that are valid: 
	Rect(float x, float y, float w, float h);

	Rect(float x, float y, float w, float h, float red, float green, float blue);

    //Draws rectangle based on the values declared beforehand
	void draw();

    bool contains(float x, float y);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void select(char value);
    void deselect();
};




#endif