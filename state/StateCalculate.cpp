#include "StateCalculate.h"

StateCalculate::StateCalculate() : scoreShower(1100, 350, 200, 100, "Score: ")
{
    this->scoreShower.changeColor(sf::Color(255, 255, 255));
}

void StateCalculate::start(Button &startButton,
                           Button &stopButton)
{
    startButton.disable();
    stopButton.disable();
    this->clock.restart();
    this->scoreShower.changeString("Score : ...");
}

bool StateCalculate::update(sf::RenderWindow &window, FieldControler &controler, Button &startButton,
                            Button &stopButton)
{
    controler.draw(window);
    this->scoreShower.draw(window);

    if (this->score < 0)
    {
        this->score = controler.calculateScore();
        if (this->score > -1)
        {
            this->scoreShower.changeString("Score : " + std::to_string(this->score));
        }
    }

    if (this->clock.getElapsedTime().asSeconds() > 5)
    {
        return true;
    }

    return false;
}

void StateCalculate::stop()
{
    this->score = -1;
}