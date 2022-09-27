#include "Figure.h"

// figure scales in info.txt

Figure::Figure(int x, int y, sf::Texture &texture, FigureType _type) : type(_type)
{
    switch (this->type)
    {
    case FigureType::elipse:
        setSprite(371, 255, 547, 750, texture);
        createElipse(x, y, texture);
        break;
    case FigureType::rect:
        setSprite(1458, 278, 490, 742, texture);
        createRect(x, y, texture);
        break;
    case FigureType::circle:
        setSprite(2382, 308, 727, 709, texture);
        createCircle(x, y, texture);
        break;
    case FigureType::rhombus:
        setSprite(3374, 247, 817, 817, texture);
        createRhombus(x, y, texture);
        break;
    }
}

void Figure::setSprite(int x, int y, int width, int height, sf::Texture &texture)
{
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

// sprite position x = 371, y = 255, width = 547, height = 750, scaleH = 1 scaleW = 1

void Figure::createElipse(int x, int y, sf::Texture &texture)
{
    float scale = 0.205f;
    float offset = ((817 * 0.92f) - 547) * 0.205f * 0.5f + 75;
    this->sprite.setPosition((200 * x) + offset, 300 * y - 225);
    this->sprite.scale(scale, scale);
}

// sprite position x = 1458, y = 278, width = 490, height = 742, scaleH = 1.01 scaleW = 1.11

void Figure::createRect(int x, int y, sf::Texture &texture)
{
    float scale = 0.205f * 1.01f;
    float offset = ((817 * 0.92f) - (490 * 1.01f)) * 0.205f * 0.5f + 75;
    this->sprite.setPosition((200 * x) + offset, 300 * y - 225);
    this->sprite.scale(scale, scale);
}

// sprite position x = 2382, y = 308, width = 727, height = 709, scaleH = 1.06 scaleW = 0.75

void Figure::createCircle(int x, int y, sf::Texture &texture)
{
    float scale = 0.205f * 1.06f;
    float offset = ((817 * 0.92f) - (727 * 1.06f)) * 0.205f * 0.5f + 75;
    this->sprite.setPosition((200 * x) + offset, (300 * y) - 225);
    this->sprite.scale(scale, scale);
}

// sprite position x = 3374, y = 247, width = 817, height = 817, scaleH = 0.92 scaleW = 0.67

void Figure::createRhombus(int x, int y, sf::Texture &texture)
{
    float scale = 0.205f * 0.92f;
    float offset = 0.205f * 0.5f + 75;
    this->sprite.setPosition((200 * x) + offset, 300 * y - 225);
    this->sprite.scale(scale, scale);
}