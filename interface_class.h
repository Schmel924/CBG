#ifndef INTERFACE_CLASS_H
#define INTERFACE_CLASS_H

#include <SFML/Graphics.hpp>

class keyboard_cursor ;


struct oyvey {
int pixelsfromwindowborder = 50;
int sizeofblock = 50;
int thicknessoflines = 2;
int numberofblocks = 25;
} Global_interface;

class interface {
public:
	int a;
	int render_cursor (sf::RenderWindow *, keyboard_cursor *);
};

#endif //INTERFACE_CLASS_H 
