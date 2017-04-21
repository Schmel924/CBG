#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <string>
#include "interface_class.h"   
#include "cursor_class.h"
const int getnumberoflines (int numberofblocks)
{ 
switch (numberofblocks)
{
case 25: return 8;
case 64: return 14;
case 100: return 18;
}
//(sqrt(NoB)-1)*2; ???????
return 2;
}

sf::Vector2i getnumberofblocks (sf::VideoMode VM)
{
sf::Vector2i NoB;
int height = VM.height / 50;
height-=2;
int width = VM.width / 50;
width -=2;
NoB.x = width;
NoB.y = height;
return NoB;
}

void /*??*/ fillnetlines (sf::RectangleShape netlines[], sf::Vector2u size)
{
    for(int i=0;i<getnumberoflines(G_i.NoB)/2;i++)
	{
	sf::Vector2f A (/*(float)(G_i.thick+G_i.SoB)*5*/
			(float)size.x-G_i.indent*2,(float)G_i.thick);
	netlines[i].setSize(A); //((float)size.x-Global_interface.pixelsfromwindowborder,(float)2);
	netlines[i].setPosition(G_i.indent,G_i.indent+(G_i.SoB*(i+1))+G_i.thick*(i+1));
	}	
    for(int i=getnumberoflines(G_i.NoB)/2;i<getnumberoflines(G_i.NoB);i++)	
	{
	sf::Vector2f A ((float)G_i.thick,/*(float)(G_i.thick+G_i.SoB)*5*/
					(float)size.y-G_i.indent*2); 
	netlines[i].setSize(A) ;
	netlines[i].setPosition(G_i.indent+(G_i.SoB*(i+1-getnumberoflines(G_i.NoB)/2))+G_i.thick*(i+1-getnumberoflines(G_i.NoB)/2),G_i.indent );
	}

}
void /*??*/ sendlinestowindow (sf::RenderWindow *window, sf::RectangleShape netlines [])
{
   
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
    getnumberofblocks(sf::VideoMode(500,500));
    interface iface;
    //keyboard_cursor key_cur;
    iface.key_cur.x_coord=3;
    iface.key_cur.y_coord=1;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    sf::Vector2u size = window.getSize();
    sf::RectangleShape netlines [getnumberoflines(G_i.NoB)];
    fillnetlines (netlines, size); 
    fprintf(stderr,"%u -- %u-",size.x,size.y); 
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
				iface.key_cur.LEFT_coord();
				break;
			case (sf::Keyboard::Right):
				iface.key_cur.RIGHT_coord();
				break;
			case (sf::Keyboard::Up):
				iface.key_cur.UP_coord();
				break;
			case (sf::Keyboard::Down):
				iface.key_cur.DOWN_coord();
				break;
			case (sf::Keyboard::Return):
				iface.choosecityblock();
				window.setActive();
				break;		
		}
        }

        window.clear();
	sendlinestowindow(&window,netlines);
	iface.render_cursor (&window);
        window.display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{window.close();}
    }

    return 0;
}
