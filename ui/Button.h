#ifndef BUTTON
#define BUTTON
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
    Button(float x, float y, float width, float height, std::string text);

    void disable();
    void enable();
    void draw(sf::RenderWindow &window);
    void update(const sf::Vector2i mousePos, bool buttonPressed);
    void changeColor(sf::Color color) { this->idleColor = color; };
    void changeString(std::string str);
    bool isPressed();

private:
    bool active;
    bool pressed;
    sf::Color idleColor = sf::Color(200, 200, 200);
    sf::Color hoverColor = sf::Color(150, 150, 150);
    sf::Color activeColor = sf::Color(100, 100, 100);
    sf::Font font;
    sf::RectangleShape shape;
    sf::Text text;
};

#endif // BUTTON