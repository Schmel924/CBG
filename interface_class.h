#ifndef INTERFACE_CLASS_H
#define INTERFACE_CLASS_H

#include <SFML/Graphics.hpp>

class keyboard_cursor ;


const static struct oyvey {
const int pixelsfromwindowborder = 50;
const int sizeofblock = 50;
const int thicknessoflines = 2;
const static int numberofblocks = 25;
} Global_interface;

class interface {
public:
	int a;
	int render_cursor (sf::RenderWindow *, keyboard_cursor *);
};

#endif //INTERFACE_CLASS_H 
