#include "GameRender.h"
#include "iostream"

GameRender::GameRender() : window(sf::VideoMode(1500, 900), "Test slot"),
                           startButton(1100, 200, 200, 100, "Start"),
                           stopButton(1100, 700, 200, 100, "Stop")
{
    this->dimondsImg.loadFromFile(pathImg);
    this->texture.loadFromImage(dimondsImg);
    this->controler.createField(texture);
    this->stateMachine.start(startButton, stopButton);

    this->createHud();
}

GameRender::~GameRender()
{
    for (auto i = this->hud.begin(); i != this->hud.end(); i++)
    {
        delete (*i);
    }

    this->hud.clear();
}

void GameRender::gameCycle()
{
    auto field = this->controler.getField();

    while (window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }

        this->window.clear(sf::Color(255, 255, 255));

        this->stateMachine.update(this->window, this->controler, this->startButton, this->stopButton);

        this->drawHud();

        this->window.display();
    }
}

void GameRender::drawHud()
{
    for (auto elem : this->hud)
    {
        this->window.draw(*elem);
    }
}

void GameRender::createHud()
{
    sf::RectangleShape *shape = new sf::RectangleShape(sf::Vector2f(850.f, 65.f));
    shape->setFillColor(sf::Color(255, 255, 255));
    shape->setPosition(sf::Vector2f(0.f, 840.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(850.f, 65.f));
    shape->setFillColor(sf::Color(255, 255, 255));
    shape->setPosition(sf::Vector2f(0.f, 0.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(800.f, 5.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(50.f, 65.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(800.f, 5.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(50.f, 835.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(5.f, 775.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(50.f, 65.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(5.f, 775.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(250.f, 65.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(5.f, 775.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(450.f, 65.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(5.f, 775.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(650.f, 65.f));

    this->hud.push_back(shape);

    shape = new sf::RectangleShape(sf::Vector2f(5.f, 775.f));
    shape->setFillColor(sf::Color(0, 0, 0));
    shape->setPosition(sf::Vector2f(850.f, 65.f));

    this->hud.push_back(shape);
}