#ifndef STATE_INTERFACE
#define STATE_INTERFACE
#include "../ui/Button.h"
#include "../field/FieldControler.h"

class StateInterface
{
public:
    virtual void start(Button &startButton, Button &stopButtton) = 0;
    virtual void stop() = 0;
    virtual bool update(sf::RenderWindow &window, FieldControler &field, Button &startButton,
                        Button &stopButton) = 0;
};

#endif // STATE_INTERFACE