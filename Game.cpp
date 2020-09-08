#include "Game.h"

using namespace std;

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
    delete window;
    delete splashScreen;

}

void Game::run()
{
    initsplashscreen();
    initialiseWindow();
    while(window->isOpen())
    {
        update();
        render();
    }

}

void Game::initsplashscreen()
{
    splashScreen = new sf::RenderWindow(sf::VideoMode(900,700),"Splashscreen",sf::Style::Close);
    splashScreen->setFramerateLimit(60);
    if(!this->font.loadFromFile("Pacifico.ttf"))
    {
        std::cout<<"ERROR::GAME::INITFONTS::COULD NOT LOAD Pacifico.ttf"<<std::endl;
    }

     splashText.setFont(this->font);
    splashText.setFillColor(sf::Color::White);
    splashText.setCharacterSize(25);
    splashText.setString("Legend \n Up arrow = Move up \n Down arrow = Move down \n Left arrow = Move left \n Right arrow = Move right \n \n PRESS ENTER TO PLAY ");

    while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        splashScreen->clear();

        splashScreen->draw(splashText);

        splashScreen->display();
    }

}

void Game::initialiseWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(900,700),"SuperPacman",sf::Style::Close);
    window->setFramerateLimit(60);

}




void Game::update()
{
    checkExit();
    createGhost();
    playerMove(player.trackInput());
    player.checkBounds(*window);
    maze.fruitCollision(player.getShape());

}

void Game::render()
{
    window->clear();



    for(auto i : ghosts)
    {
        i.render(*window);
    }

    player.render(*window);

    maze.renderMaze(*window);

    window->display();
}



void Game::checkExit()
{
    while(window->pollEvent(event))
    {

        if(event.type==sf::Event::Closed)
        {
            this->window->close();
            break;
        }
    }
}

void Game::createGhost()
{
    if(ghosts.size()<maxGhosts)
    {
        ghosts.push_back(Ghost());
        //cout<<ghosts.size()<<endl;
    }
}

void Game::playerMove(string direction)
{
    if(direction == "Down")
    {
        player.getShape().move(0.f,playerspeed);
        if(maze.wallCollision(player.getShape()))
        {
            player.getShape().move(0.f,-playerspeed);
        }
    }

    if(direction == "Up")
    {
        player.getShape().move(0.f,-playerspeed);
        if(maze.wallCollision(player.getShape()))
        {
            player.getShape().move(0.f,playerspeed);
        }
    }

    if(direction == "Left")
    {
        player.getShape().move(-playerspeed,0.f);
        if(maze.wallCollision(player.getShape()))
        {
            player.getShape().move(playerspeed,0.f);
        }
    }

    if(direction == "Right")
    {
        player.getShape().move(playerspeed,0.f);
        if(maze.wallCollision(player.getShape()))
        {
            player.getShape().move(-playerspeed,0.f);
        }
    }
//
//    float x = input.x;
//    float y = input.y;
//
//

//
//    for(float i=0; i<20;i++)
//    {
//        //left
////        if(player.getShape().getGlobalBounds().intersects(gameMaze.at(i)->getGlobalBounds()))
////        {
////            cout<<"in walls"<<endl;
////            player.getShape().setPosition(gameMaze.at(i)->getGlobalBounds().left,player.getPosition().y);
////        }
//
//        //right
//        if((player.getPosition().x+2*player.getSize()) == gameMaze.at(i)->getPosition().x && player.getPosition().y == gameMaze.at(i)->getPosition().y)
//        {
//            cout<<"in walls"<<endl;
//            player.getShape().setPosition(gameMaze.at(i)->getPosition().x,player.getShape().getPosition().y);
//        }
//    }
}


