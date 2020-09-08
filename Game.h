#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <string>
#include<vector>

#include "Ghost.h"
#include "Player.h"
#include "Maze.h"

using namespace std;


class Game
{
private:

    sf::RenderWindow* window;
    sf::RenderWindow* splashScreen;
    sf::Event event;
    sf::Font font;
    sf::Text splashText;

    void initsplashscreen();
    void initialiseWindow();
    void initialiseMaze();

    void checkExit();
    void update();


    void createGhost();
    int maxGhosts=10;
    void render();
    void renderMaze();
    void playerMove(string direction);
    float playerspeed=10.f;

    Player player;
    Maze maze;

    vector<Ghost> ghosts;



public:
    Game();
    ~Game();
    void run();



};

#endif // GAME_H
