#ifndef _GAME_H
#define _GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class Game
{
public:
    void Start();
//SFML Related graphic
    static sf::RenderWindow StartWindow; 
private:
    sf::VideoMode VMChoose();
};


#endif //_GAME_H
