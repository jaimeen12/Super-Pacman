#include "Maze.h"

Maze::Maze()
{
    //ctor
    initFruit();
    initialiseMaze();

}

Maze::~Maze()
{
    //dtor
}

void Maze::initialiseMaze()
{
    for(float i=0;i<20;i++)
    {
        line =new sf::RectangleShape(sf::Vector2f(200,3));
        if(i<10)
        {
            line->setRotation(90.f);

        }
        line->setFillColor(sf::Color::White);

        gameMaze.push_back(line);
    }
    setMaze();

}

void Maze::initFruit()
{
     for(float i=0;i<maxFruit;i++)
    {
        gameFruit.push_back(Fruit(20*i, 20*i));
        cout<<gameFruit.size()<<endl;
    }
}

sf::RectangleShape& Maze::getShape(int i)
{
    return *gameMaze.at(i);
}

void Maze::renderMaze(sf::RenderTarget& target)
{
    for(auto i:gameMaze)
    {
        target.draw(*i);
    }

    for(auto i:gameFruit)
    {
        target.draw(i.getshape());
    }

}

bool Maze::wallCollision(sf::CircleShape& playerShape)
{
    for(int i=0;i<gameMaze.size();i++)
    {
        if(playerShape.getGlobalBounds().intersects(gameMaze.at(i)->getGlobalBounds()))
        {
            return true;
        }

    }
    return false;
}

void Maze::setMaze()
{
    float distance=30;
    int i=0;
    gameMaze.at(i)->setPosition(100.f,100.f);

    i++;
    gameMaze.at(i)->setPosition(175.f,100.f);

    for(int k=0;k<5;k++)
    {
        gameFruit.at(k).getshape().setPosition(sf::Vector2f(130.f,100.f+k*distance));
    }


    i++;
    gameMaze.at(i)->setPosition(475.f,100.f);

    i++;
    gameMaze.at(i)->setPosition(550.f,100.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+5).getshape().setPosition(sf::Vector2f(500.f,60.f+k*distance));
    }


    i++;
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(175.f,475.f);

    i++;
    gameMaze.at(i)->setPosition(100.f,475.f);

    i++;
    gameMaze.at(i)->setPosition(175.f,475.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+19).getshape().setPosition(sf::Vector2f(120.f,435.f+k*distance));
    }

    i++;
    gameMaze.at(i)->setSize(sf::Vector2f(275,3));
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(100.f,400.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+26).getshape().setPosition(sf::Vector2f(150.f+k*distance,435.f));
    }

    i++;
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(550.f,100.f);

    i++;
    gameMaze.at(i)->setSize(sf::Vector2f(275,3));
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(475.f,25.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+12).getshape().setPosition(sf::Vector2f(500.f+k*distance,60.f));
    }



    i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(475.f,400.f);

    i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(550.f,400.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+47).getshape().setPosition(sf::Vector2f(500.f, 410.f+k*distance));
    }


    i++;
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(550.f,600.f);

    i++;
    gameMaze.at(i)->setSize(sf::Vector2f(275,3));
    gameMaze.at(i)->setRotation(0.f);
    gameMaze.at(i)->setPosition(475.f,675.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+54).getshape().setPosition(sf::Vector2f(500.f+k*distance,630.f));
    }


     i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(300.f,100.f);

    i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(375.f,100.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+33).getshape().setPosition(sf::Vector2f(330.f,100.f+k*distance));
    }

     i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(650.f,250.f);

     i++;
    gameMaze.at(i)->setRotation(90.f);
    gameMaze.at(i)->setPosition(725.f,250.f);

    for(int k=0;k<7;k++)
    {
        gameFruit.at(k+40).getshape().setPosition(sf::Vector2f(670.f,250.f+k*distance));
    }



}

void Maze::fruitCollision(sf::CircleShape& playerShape)
{
    for(int i=0;i<gameFruit.size();i++)
    {
        if(playerShape.getGlobalBounds().intersects(gameFruit.at(i).getshape().getGlobalBounds()))
        {
            gameFruit.erase(gameFruit.begin()+i);
        }

    }

}

