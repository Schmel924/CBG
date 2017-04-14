#include "interface_class.h"
#include "cursor_class.h"
#include "citymap.h"
#include <stdio.h>

sf::Vector2f coordstoPixels (sf::Vector2f cur_coord)
{
sf::Vector2f cur_pos (G_i.indent,G_i.indent);
cur_pos.x+= cur_coord.x*(G_i.thick+G_i.SoB);

cur_pos.y+= cur_coord.y*(G_i.thick+G_i.SoB);
return cur_pos;
}

int interface::render_cursor (sf::RenderWindow * window, keyboard_cursor * cur)
{
sf::Vector2f cur_coord (cur->getxc(),cur->getyc());
sf::RectangleShape Cursor;
Cursor.setSize(sf::Vector2f(G_i.SoB-5,G_i.SoB-5));
sf::Vector2f cur_pos = coordstoPixels(cur_coord);
cur_pos.x+=2+G_i.thick;
cur_pos.y+=2+G_i.thick;
//fprintf (stderr, "x - %f, y - %f!",cur_pos.x, cur_pos.y);
Cursor.setPosition (cur_pos);
Cursor.setFillColor (sf::Color::White);
window->draw(Cursor);
return 0;
} 
