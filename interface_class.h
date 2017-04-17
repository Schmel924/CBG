#ifndef INTERFACE_CLASS_H
#define INTERFACE_CLASS_H

#include <SFML/Graphics.hpp>
#include "cursor_class.h"
//class keyboard_cursor ;
#include "citymap.h"
//class citymap;

static struct oyvey {
int indent = 50;  //aka pixelsfromwindowsborder
int SoB = 50; // aka sizeofblocks
int thick = 2; // aka thicknessoflines
int NoB = 100; // works as 25  // aka numberofblocks
} G_i; // aka Global_interface

class interface {
public:
	int a;
	int render_cursor (sf::RenderWindow *);
	keyboard_cursor key_cur;
	void choosecityblock();
	citymap maincitymap;
};

#endif //INTERFACE_CLASS_H 
