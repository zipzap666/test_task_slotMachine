#ifndef STATE_CALCULATE
#define STATE_CALCULATE
#include "StateInterface.h"

class StateCalculate : public StateInterface
{
public:
    StateCalculate();

    void start(Button &startButton,
               Button &stopButtton) override;
    bool update(sf::RenderWindow &window, FieldControler &field, Button &startButton,
                Button &stopButton) override;
    void stop() override;

private:
    sf::Clock clock;
    Button scoreShower;
    int score = -1;
};

#endif // STATE_CALCULATE