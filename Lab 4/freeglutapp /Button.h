#ifndef BUTTON_H
#define BUTTON_H


struct Button {
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float w;
	float h;
	char objectSelection;

	bool selected;

	Button(char objectSelection); 

	void draw();

	bool contains(float x, float y);


};




#endif
