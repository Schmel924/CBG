#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
   


int main()
{
    sf::RenderWindow window (sf::VideoMode::getDesktopMode(),"SFML works!");
    sf::RectangleShape curser;
    float x=500,y=500;;
    curser.setSize(sf::Vector2f(50,50));
    curser.setPosition(sf::Vector2f(x,y));
    curser.setFillColor(sf::Color::Red);
    sf::Vector2u size = window.getSize();
    sf::Font font;
    font.loadFromFile("arial.ttf");
    std::string refer = " ";
    refer=refer+std::to_string(size.x);
    refer+="--";
    refer=refer+std::to_string(size.y);
    sf::Text text(refer, font,150);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
//      window.draw(shape);
	window.draw(curser);
        window.draw(text);
	std::string curr = " ";
	curr=curr+std::to_string(x);
	curr+="--";
	curr=curr+std::to_string(y);
	sf::Text secon(curr,font,50);
	secon.setPosition(100,500);
	window.draw(secon);
        window.display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{window.close();}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&x>=10)
		{x-=10;curser.setPosition(sf::Vector2f(x,y));/*window.draw(curser);*/}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&x<=1000)
		{x+=10;curser.setPosition(sf::Vector2f(x,y));/*window.draw(curser);*/}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&y>=10)
		{y-=10;curser.setPosition(sf::Vector2f(x,y));/*window.draw(curser);*/}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&y<=550)
		{y+=10;curser.setPosition(sf::Vector2f(x,y));/*window.draw(curser);*/}
    }

    return 0;
}
