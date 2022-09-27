#ifndef STATE_MACHINE
#define STATE_MACHINE
#include "StateSpin.h"
#include "StateIdle.h"
#include "StateCalculate.h"
#include <memory>

class StateMachine
{
    class StateNode
    {
    public:
        std::unique_ptr<StateInterface> state;
        std::shared_ptr<StateNode> next;

        StateNode() : next(nullptr), state(nullptr){};
    };

public:
    StateMachine();

    void nextState();
    void start(Button &startButton, Button &stopButtton);
    void update(sf::RenderWindow &window, FieldControler &controler,
                Button &startButton, Button &stopButton);
    void stateActivate();

private:
    std::shared_ptr<StateNode> curentState;
};

#endif // STATE_MACHINE