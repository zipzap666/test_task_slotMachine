#include "StateSpin.h"

void StateSpin::start(Button &startButton,
                      Button &stopButton)
{
    this->clock.restart();

    startButton.disable();
    stopButton.enable();
}

bool StateSpin::update(sf::RenderWindow &window, FieldControler &controler, Button &startButton,
                       Button &stopButton)
{
    controler.startSpin();
    controler.draw(window);
    stopButton.draw(window);

    if (stopButton.isPressed() || (this->clock.getElapsedTime().asSeconds() > 10.f))
    {
        controler.stopSpin();
        stopButton.disable();
    }

    if (controler.spinIsStoped())
    {
        return true;
    }
    return false;
}

void StateSpin::stop() {}