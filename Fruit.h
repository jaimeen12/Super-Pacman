#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Fruit
{
private:
    sf::CircleShape fruit;
    float fruitSize = 10;

public:
    Fruit(float x, float y);
    ~Fruit();
    sf::CircleShape& getshape();
    float getfruitsize();


};

#endif // FRUIT_H
