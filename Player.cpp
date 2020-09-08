#include "Player.h"

Player::Player()
{
    //ctor
    player.setRadius(playerSize);
    player.setFillColor(sf::Color::Yellow);

}

Player::~Player()
{
    //dtor
}

void Player::checkBounds(sf::RenderTarget& target)
{
    //left
    if(player.getPosition().x<=0.f)
    {
        player.setPosition(0.f,player.getPosition().y);
    }

    //right
    if(player.getPosition().x>=(target.getSize().x-2*playerSize))
    {
        player.setPosition(target.getSize().x-2*playerSize,player.getPosition().y);
    }

    //top
    if(player.getPosition().y<=0.f)
    {
        player.setPosition(player.getPosition().x,0.f);
    }

    //bottom
    if(player.getPosition().y>=(target.getSize().y-2*playerSize))
    {
        player.setPosition(player.getPosition().x,target.getSize().y-2*playerSize);
    }

}


string Player::trackInput()
{
    direction.clear();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
       direction="Up";
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction="Down";
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction="Left";
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction="Right";
    }

    return direction;
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(player);
}

sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}

sf::CircleShape& Player::getShape()
{
    return player;
}

float Player::getSize()
{
    return playerSize;
}
