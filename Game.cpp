//GAME.CPP
//
#include "Game.h"


sf::VideoMode Game::VMChoose()
{
sf::VideoMode Fullscr = sf::VideoMode::getDesktopMode();
if (Fullscr.width > 1024)
	{Fullscr.width=1024;}
if (Fullscr.height > 640)
	{Fullscr.height=640;}
return Fullscr;
}

void Game::Start(void)
{
   this->StartWindow.create(Game::VMChoose(), "SFML");
}
sf::RenderWindow Game::StartWindow;
