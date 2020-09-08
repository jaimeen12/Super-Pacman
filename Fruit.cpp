#include "Fruit.h"

Fruit::Fruit(float x, float y)
{
    //ctor
    fruit.setRadius(fruitSize);
    fruit.setFillColor(sf::Color::Green);
    fruit.setPosition(sf::Vector2f(x,y));
}

Fruit::~Fruit()
{
    //dtor
}

sf::CircleShape& Fruit::getshape()
{
    return fruit;
}

float Fruit::getfruitsize()
{
    return fruit.getRadius();
}
