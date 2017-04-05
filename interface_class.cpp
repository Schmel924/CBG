#include "interface_class.h"
#include "cursor_class.h"
#include "citymap.h"
#include <stdio.h>
sf::Vector2f coordstoPixels (sf::Vector2f cur_coord)
{
sf::Vector2f cur_pos (Global_interface.pixelsfromwindowborder,Global_interface.pixelsfromwindowborder);
cur_pos.x+= cur_coord.x*(Global_interface.thicknessoflines+Global_interface.sizeofblock);

cur_pos.y+= cur_coord.y*(Global_interface.thicknessoflines+Global_interface.sizeofblock);
return cur_pos;
}

int interface::render_cursor (sf::RenderWindow * window, keyboard_cursor * cur)
{
sf::Vector2f cur_coord (cur->getxc(),cur->getyc());
//cur_coord.x+=1;
//cur_coord.y+=1;
//if (cur_coord.x >= citymap::max_block_axis || cur_coord.y >= citymap::max_block_axis)
//	return 1;
//else
sf::RectangleShape Cursor;
Cursor.setSize(sf::Vector2f(Global_interface.sizeofblock-5,Global_interface.sizeofblock-5));
sf::Vector2f cur_pos = coordstoPixels(cur_coord);
cur_pos.x+=2+Global_interface.thicknessoflines;
cur_pos.y+=2+Global_interface.thicknessoflines;
//fprintf (stderr, "x - %f, y - %f!",cur_pos.x, cur_pos.y);
Cursor.setPosition (cur_pos);
Cursor.setFillColor (sf::Color::White);
window->draw(Cursor);
return 0;
} 
