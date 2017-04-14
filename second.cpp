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
    sf::RectangleShape netlines [getnumberoflines(G_i.NoB)];
    for(int i=0;i<getnumberoflines(G_i.NoB)/2;i++)
	{
	sf::Vector2f A ((float)(G_i.thick+G_i.SoB)*5,(float)G_i.thick);
	netlines[i].setSize(A); //((float)size.x-Global_interface.pixelsfromwindowborder,(float)2);
	netlines[i].setPosition(G_i.indent,G_i.indent+(G_i.SoB*(i+1))+G_i.thick*(i+1));
	}	
    for(int i=getnumberoflines(G_i.NoB)/2;i<getnumberoflines(G_i.NoB);i++)	
	{
	sf::Vector2f A ((float)G_i.thick,(float)(G_i.thick+G_i.SoB)*5); 
	netlines[i].setSize(A) ;
	netlines[i].setPosition(G_i.indent+(G_i.SoB*(i-3))+G_i.thick*(i-3),G_i.indent );
	}
   
    for(int i=0;i<getnumberoflines(G_i.NoB);i++)
	{
	window->draw(netlines[i]);
	}

}

int main()
{
    //for various purposes
    
    
    sf::RenderWindow window (sf::VideoMode(500,500),"SFML works!");
    //sf::RenderWindow window (sf::VideoMode::getDesktopMode(),"SFML works!");
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

        sf::Vector2u size = window.getSize();
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
