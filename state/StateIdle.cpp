#include "StateIdle.h"

void StateIdle::start(Button &startButton,
                      Button &stopButton)
{
    startButton.enable();
    stopButton.disable();
}

bool StateIdle::update(sf::RenderWindow &window, FieldControler &controler, Button &startButton,
                       Button &stopButton)
{
    controler.draw(window);
    startButton.draw(window);

    if (startButton.isPressed())
    {
        return true;
    }
    return false;
}

void StateIdle::stop() {}