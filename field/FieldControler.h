#ifndef FIELD_CONTROLER
#define FIELD_CONTROLER
#include "Figure.h"
#include "vector"
#include <memory>

class FieldControler
{
public:
    FieldControler();

    void createField(sf::Texture &texture);
    void draw(sf::RenderWindow &window);
    void startSpin();
    void stopSpin();
    bool spinIsStoped() { return spinStoped; };
    int calculateScore();
    std::vector<std::vector<std::shared_ptr<Figure>>> getField() { return field; };

private:
    void alignment();
    bool spinActive;
    bool spinStopping;
    bool continueMove;
    bool spinStoped;
    std::vector<float> aceleration;
    float startAceleration;
    float startSlow;
    std::vector<std::vector<std::shared_ptr<Figure>>> field;
};

#endif // FIELD_CONTROLER