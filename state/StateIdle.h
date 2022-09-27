#ifndef STATE_IDLE
#define STATE_IDLE
#include "StateInterface.h"

class StateIdle : public StateInterface
{
public:
    StateIdle(){};

    void start(Button &startButton,
               Button &stopButtton) override;
    bool update(sf::RenderWindow &window, FieldControler &field, Button &startButton,
                Button &stopButton) override;
    void stop() override;
};

#endif // STATE_IDLE