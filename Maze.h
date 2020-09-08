#ifndef MAZE_H
#define MAZE_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Fruit.h"

#include <vector>
#include <iostream>

using namespace std;


class Maze
{
private:
      vector<sf::RectangleShape*> gameMaze;
      vector<Fruit> gameFruit;
      sf::RectangleShape* line;
      float maxFruit = 61;
public:
    Maze();
    ~Maze();
    void initialiseMaze();
    void renderMaze(sf::RenderTarget& target);
    bool wallCollision(sf::CircleShape& playerShape);
    sf::RectangleShape& getShape(int i);
    void setMaze();
    void initFruit();
    void fruitCollision(sf::CircleShape& playerShape);



};

#endif // MAZE_H
