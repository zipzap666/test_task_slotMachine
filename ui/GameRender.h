#include <SFML/Graphics.hpp>
#include "../field/FieldControler.h"
#include "../state/StateMachine.h"
#include "Button.h"
#include <vector>

class GameRender
{
public:
    GameRender();
    ~GameRender();

    void gameCycle();

private:
    void drawHud();
    void createHud();

    sf::RenderWindow window;
    FieldControler controler;

    Button startButton;
    Button stopButton;

    std::vector<sf::RectangleShape *> hud; // smart_ptr dont work correctly with RectangleShape

    StateMachine stateMachine;
    sf::Image dimondsImg;
    sf::Texture texture;
    const char *pathImg = "resources/20165.jpg";
};
