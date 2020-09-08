#include "Ghost.h"

Ghost::Ghost()
{
    //ctor
    ghost.setRadius(ghostSize);
    ghost.setFillColor(sf::Color::Blue);
    ghost.setPosition(sf::Vector2f(0.f,0.f));
    startPosition+=100.f;
}

Ghost::~Ghost()
{
    //dtor
}

void Ghost::render(sf::RenderTarget& target)
{

    target.draw(ghost);
}
