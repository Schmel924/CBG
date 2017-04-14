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
	interface iface;
	iface.render_cursor (&window, &key_cur);
        window.display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{window.close();}
    }

    return 0;
}
