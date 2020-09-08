#ifndef GHOST_H
#define GHOST_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Ghost
{
private:
    sf::CircleShape ghost;
    float ghostSize = 10;
    float startPosition = 0;

public:
    Ghost();
    ~Ghost();
    void render(sf::RenderTarget& target);



};

#endif // GHOST_H
