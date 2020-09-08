#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include<string>

using namespace std;

class Player
{
private:
    sf::CircleShape player;
    float playerSize=20.f;

    string direction="";

public:
    Player();
    ~Player();
    void checkBounds(sf::RenderTarget& target);
    void render(sf::RenderTarget& target);
    string trackInput();
    sf::Vector2f getPosition();
    float getSize();

    sf::CircleShape& getShape();



};

#endif // PLAYER_H
