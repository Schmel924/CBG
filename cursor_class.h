#ifndef CURSOR_CLASS_H
#define CURSOR_CLASS_H
#include <SFML/Graphics.hpp>
class keyboard_cursor{
public:
	int x_coord;
	int y_coord;
	void UP_coord ();
	void DOWN_coord();
	void LEFT_coord();
	void RIGHT_coord();	
	keyboard_cursor() {x_coord=3;y_coord=3;};
	sf::Vector2i GetCoords();
	int getxc () {return x_coord;};
	int getyc () {return y_coord;};
};
#endif //CURSOR_CLASS_H
