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

	Button(float x, float y, float w, float h, char objectSelection);

	Button(float x, float y, float w, float h, float red, float green, float blue);

	void draw();

	bool contains(float x, float y);

	void select();
	void deselect();


};




#endif
