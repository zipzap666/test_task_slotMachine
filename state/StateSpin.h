#ifndef STATE_SPIN
#define STATE_SPIN
#include "StateInterface.h"

class StateSpin : public StateInterface
{
public:
    StateSpin(){};

    void start(Button &startButton,
               Button &stopButtton) override;
    bool update(sf::RenderWindow &window, FieldControler &field, Button &startButton,
                Button &stopButton) override;
    void stop() override;

private:
    sf::Clock clock;
};

#endif // STATE_SPIN