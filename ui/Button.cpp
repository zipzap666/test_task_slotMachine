#include "Button.h"
#include "iostream"

using namespace std;

Button::Button(float x, float y, float width, float height, std::string text) : active(false), pressed(false)
{
    this->shape.setPosition(x, y);
    this->shape.setSize(sf::Vector2f(width, height));

    if (!this->font.loadFromFile("./resources/arial.ttf"))
    {
        cout << "can't load font" << endl;
    }

    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(20);
    this->text.setStyle(sf::Text::Bold);
    this->text.setPosition(x + (width / 2.f) - text.size() * 5, y + (height / 2.f) - 10);

    this->shape.setFillColor(sf::Color(200, 200, 200));
}

void Button::draw(sf::RenderWindow &window)
{
    this->update(sf::Mouse::getPosition(window), sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
    window.draw(shape);
    window.draw(text);
}

void Button::update(const sf::Vector2i mousePos, bool buttonPressed)
{
    this->pressed = false;

    if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePos)))
    {
        if (this->active)
        {
            if (buttonPressed)
            {
                this->pressed = true;
                this->shape.setFillColor(activeColor);
            }
            else
            {
                this->shape.setFillColor(hoverColor);
            }
        }
    }
    else
    {
        this->shape.setFillColor(idleColor);
    }
}

void Button::disable()
{
    this->active = false;
}

void Button::enable()
{
    this->active = true;
}

bool Button::isPressed()
{
    return this->pressed;
}

void Button::changeString(std::string str)
{
    this->text.setString(str);
    this->text.setPosition(shape.getPosition().x + (shape.getSize().x / 2.f) - str.size() * 5, shape.getPosition().y + (shape.getSize().y / 2.f) - 10);
}