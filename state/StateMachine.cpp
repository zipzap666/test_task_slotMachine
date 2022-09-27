#include "StateMachine.h"

StateMachine::StateMachine()
{
    this->curentState = std::make_shared<StateNode>();
    this->curentState->state = std::make_unique<StateIdle>();

    this->curentState->next = std::make_shared<StateNode>();
    this->curentState->next->state = std::make_unique<StateSpin>();

    this->curentState->next->next = std::make_shared<StateNode>();
    this->curentState->next->next->state = std::make_unique<StateCalculate>();
    this->curentState->next->next->next = curentState;
}

void StateMachine::nextState()
{
    this->curentState = this->curentState->next;
}

void StateMachine::start(Button &startButton, Button &stopButton)
{
    this->curentState->state->start(startButton, stopButton);
}

void StateMachine::update(sf::RenderWindow &window, FieldControler &controler, Button &startButton, Button &stopButton)
{
    if (this->curentState->state->update(window, controler, startButton, stopButton))
    {
        this->curentState->state->stop();
        this->nextState();
        this->curentState->state->start(startButton, stopButton);
    }
}