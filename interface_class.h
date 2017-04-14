#ifndef INTERFACE_CLASS_H
#define INTERFACE_CLASS_H

#include <SFML/Graphics.hpp>

class keyboard_cursor ;


static struct oyvey {
int indent = 50;  //aka pixelsfromwindowsborder
int SoB = 50; // aka sizeofblocks
int thick = 2; // aka thicknessoflines
int NoB = 25; // aka numberofblocks
} G_i; // aka Global_interface

class interface {
public:
	int a;
	int render_cursor (sf::RenderWindow *, keyboard_cursor *);
};

#endif //INTERFACE_CLASS_H 
