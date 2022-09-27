#ifndef FIGURE
#define FIGURE
#include <SFML/Graphics.hpp>

enum FigureType
{
    elipse,
    rect,
    circle,
    rhombus
};

class Figure
{
public:
    Figure(int x, int y, sf::Texture &texture, FigureType type);
    sf::Sprite &getSprite() { return sprite; };
    FigureType getType() { return type; };

private:
    sf::Sprite sprite;
    FigureType type;
    void createElipse(int x, int y, sf::Texture &texture);
    void createRect(int x, int y, sf::Texture &texture);
    void createCircle(int x, int y, sf::Texture &texture);
    void createRhombus(int x, int y, sf::Texture &texture);
    void setSprite(int x, int y, int width, int height, sf::Texture &texture);
};

#endif // FIGURE