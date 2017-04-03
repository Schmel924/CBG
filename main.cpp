#include "Game.h"

int main ()
{
Game game;
game.Start();
sf::RectangleShape again;
again.setSize(sf::Vector2f(50,50));
again.setPosition(sf::Vector2f(50,50));
game.StartWindow.clear();
game.StartWindow.draw(again);
game.StartWindow.display();
while (game.StartWindow.isOpen())
{
;
}
;
return 0;
}
