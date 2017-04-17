//CITYMAP.CPP
//PART of INTERFACE
#include "citymap.h"
#include <SFML/Graphics.hpp>
#include <string>
void citymap::showcityblock(sf::Vector2i block_coords)
{
sf::RenderWindow miniwin;
miniwin.create(sf::VideoMode(200,200),"miniwin");
sf::Font minifont;
minifont.loadFromFile("arial.ttf");
sf::Text minitext;
std::string messag = std::to_string(block_coords.x);
minitext.setString (messag);
miniwin.clear();
miniwin.draw(minitext);
miniwin.display();
sf::Clock clock;
while (true)
{
sf::Time elapsed = clock.getElapsedTime();
if (elapsed.asSeconds()>=4.0f)
	{miniwin.close();}
}
}
