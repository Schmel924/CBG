#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
   
struct oyvey {
const   int pixelsfromwindowborder=50;
const	int sizeofblock=50;
const	int thicknessoflines=2;
const static int numberofblocks=25;
} Global_interface;

const int getnumberoflines (int numberofblocks)
{ if (numberofblocks==25)
	return 8;
 else 
	return 2;
}

int main()
{
    sf::RenderWindow window (sf::VideoMode::getDesktopMode(),"SFML works!");
    sf::RectangleShape curser;
    float x=500,y=500;;
    curser.setSize(sf::Vector2f(50,50));
    curser.setPosition(sf::Vector2f(x,y));
    curser.setFillColor(sf::Color::Red);
    sf::Vector2u size = window.getSize();
    sf::RectangleShape netlines [getnumberoflines(Global_interface.numberofblocks)];
    for(int i=0;i<getnumberoflines(Global_interface.numberofblocks)/2;i++)
	{
	sf::Vector2f A ((float)10+Global_interface.sizeofblock*5,(float)2);
	netlines[i].setSize(A); //((float)size.x-Global_interface.pixelsfromwindowborder,(float)2);
	netlines[i].setPosition(Global_interface.pixelsfromwindowborder,Global_interface.pixelsfromwindowborder+(Global_interface.sizeofblock*(i+1))+Global_interface.thicknessoflines*(i+1));
	}	
    for(int i=getnumberoflines(Global_interface.numberofblocks)/2;i<getnumberoflines(Global_interface.numberofblocks);i++)	
	{
	sf::Vector2f A ((float)2,(float)10+Global_interface.sizeofblock*5); 
	netlines[i].setSize(A) ;
	netlines[i].setPosition(Global_interface.pixelsfromwindowborder+(Global_interface.sizeofblock*(i-3))+Global_interface.thicknessoflines*(i-3),Global_interface.pixelsfromwindowborder );
	}
   
    sf::Font font;
    font.loadFromFile("arial.ttf");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
	window.draw(curser);
	std::string curr = " ";
	curr=curr+std::to_string(x);
	curr+="-";
	curr+=std::to_string(getnumberoflines(Global_interface.numberofblocks));
	curr+="-";
	curr=curr+std::to_string(y);
	sf::Text secon(curr,font,50);
	secon.setPosition(100,500);
	window.draw(secon);
    for(int i=0;i<getnumberoflines(Global_interface.numberofblocks);i++)
	{
	window.draw(netlines[i]);
	}

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
