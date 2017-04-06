#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include "interface_class.h"   
#include "cursor_class.h"
const int getnumberoflines (int numberofblocks)
{ if (numberofblocks==25)
	return 8;
 else 
	return 2;
}

void /*??*/ sendlinestowindow (sf::RenderWindow *window)
{
    sf::RectangleShape netlines [getnumberoflines(Global_interface.numberofblocks)];
    for(int i=0;i<getnumberoflines(Global_interface.numberofblocks)/2;i++)
	{
	sf::Vector2f A ((float)(Global_interface.thicknessoflines+Global_interface.sizeofblock)*5,(float)Global_interface.thicknessoflines);
	netlines[i].setSize(A); //((float)size.x-Global_interface.pixelsfromwindowborder,(float)2);
	netlines[i].setPosition(Global_interface.pixelsfromwindowborder,Global_interface.pixelsfromwindowborder+(Global_interface.sizeofblock*(i+1))+Global_interface.thicknessoflines*(i+1));
	}	
    for(int i=getnumberoflines(Global_interface.numberofblocks)/2;i<getnumberoflines(Global_interface.numberofblocks);i++)	
	{
	sf::Vector2f A ((float)Global_interface.thicknessoflines,(float)(Global_interface.thicknessoflines+Global_interface.sizeofblock)*5); 
	netlines[i].setSize(A) ;
	netlines[i].setPosition(Global_interface.pixelsfromwindowborder+(Global_interface.sizeofblock*(i-3))+Global_interface.thicknessoflines*(i-3),Global_interface.pixelsfromwindowborder );
	}
   
    for(int i=0;i<getnumberoflines(Global_interface.numberofblocks);i++)
	{
	window->draw(netlines[i]);
	}

}

int main()
{
    //for various purposes
    
    
    sf::RenderWindow window (sf::VideoMode(500,500),"SFML works!");
    //sf::RenderWindow window (sf::VideoMode::getDesktopMode(),"SFML works!");
    sf::RectangleShape curser;
    float x=208,y=208;;
    curser.setSize(sf::Vector2f(50,50));
    curser.setPosition(sf::Vector2f(x,y));
    curser.setFillColor(sf::Color::Red);
    sf::Vector2u size = window.getSize();
    keyboard_cursor key_cur;
    key_cur.x_coord=3;
    key_cur.y_coord=1;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
	    if (event.type == sf::Event::KeyPressed)
		switch(event.key.code)
			{
			case (sf::Keyboard::Left):
				key_cur.LEFT_coord();
				break;
			case (sf::Keyboard::Right):
				key_cur.RIGHT_coord();
				break;
			case (sf::Keyboard::Up):
				key_cur.UP_coord();
				break;
			case (sf::Keyboard::Down):
				key_cur.DOWN_coord();
				break;
			}
        }

        window.clear();
	sendlinestowindow(&window);
	window.draw(curser);
	interface iface;
	iface.render_cursor (&window, &key_cur);
	std::string curr = " ";
	curr=curr+std::to_string(x);
	curr+="-";
	curr+=std::to_string(getnumberoflines(Global_interface.numberofblocks));
	curr+="-";
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
