//CITYMAP.CPP
//PART of INTERFACE
#include "citymap.h"
#include <SFML/Graphics.hpp>
#include <string>

sf::Vector2i getNoB (sf::VideoMode VM)
{
sf::Vector2i NoB;
NoB.x=(VM.height/50) -2;
NoB.y=(VM.width/50)-2;
return NoB;
}

void citymap::showcityblock(sf::Vector2i block_coords)
{
sf::RenderWindow miniwin;
miniwin.create(sf::VideoMode(200,200),"miniwin");
sf::Font minifont;
minifont.loadFromFile("arial.ttf");
sf::Text minitext;
sf::Vector2i NoBs = getNoB(sf::VideoMode::getDesktopMode());
std::string messag = "INFO HERE\n"+ std::to_string(NoBs.y);
minitext.setString (messag);
minitext.setFont (minifont);
minitext.setFillColor (sf::Color::White);
minitext.setPosition (10.0f,10.0f);
miniwin.clear();
miniwin.draw(minitext);
miniwin.display();
sf::Clock clock;
while (miniwin.isOpen())
{
sf::Time elapsed = clock.getElapsedTime();
if (elapsed.asSeconds()>=4.0f)
	{miniwin.close();}
}
}
