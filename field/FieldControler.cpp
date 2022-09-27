#include "FieldControler.h"

FieldControler::FieldControler()
{
    this->startAceleration = 0.1f;
    this->spinActive = false;
    this->spinStopping = false;
    this->spinStoped = false;
    for (int i = 0; i < 4; i++)
    {
        this->field.push_back(std::vector<std::shared_ptr<Figure>>());
        this->aceleration.push_back(0.f);
    }
}

void FieldControler::createField(sf::Texture &texture)
{
    for (int i = 0; i < 4; i++)
    {
        this->field[i].push_back(std::make_shared<Figure>(i, 0, texture, FigureType::elipse));
        this->field[i].push_back(std::make_shared<Figure>(i, 1, texture, FigureType::rect));
        this->field[i].push_back(std::make_shared<Figure>(i, 2, texture, FigureType::circle));
        this->field[i].push_back(std::make_shared<Figure>(i, 3, texture, FigureType::rhombus));
    }
}

void FieldControler::startSpin()
{
    if (this->spinActive == false)
    {
        this->spinActive = true;
        this->startAceleration = 0.1f;
        this->spinStopping = false;
        srand(time(0));
        for (auto i = aceleration.begin(); i != aceleration.end(); i++)
        {
            *i = ((rand() % 20) / 10.f) + 1.f;
        }
    }
}

void FieldControler::stopSpin()
{
    this->spinActive = true;
    this->spinStopping = true;
}

void FieldControler::draw(sf::RenderWindow &window)
{
    spinStoped = true;
    auto acelerationIt = aceleration.begin();
    for (auto colum : this->field)
    {
        if (spinStopping)
        {
            continueMove = find_if(colum.begin(), colum.end(), [&](std::shared_ptr<Figure> figure) -> bool
                                   { return (figure->getSprite().getPosition().y > 74.7) && (figure->getSprite().getPosition().y < 75.3); }) == colum.end();
        }

        for (auto figure : colum)
        {
            if (this->spinActive && !spinStopping)
            {
                spinStoped = false;
                if ((this->startAceleration <= 1.f) && (acelerationIt == aceleration.begin()))
                {
                    this->startAceleration += 0.0005f;
                }
                figure->getSprite().move(0, 5.f * (*acelerationIt) * this->startAceleration);
            }
            if (spinStopping && (continueMove || ((5.f * (*acelerationIt) * this->startAceleration) > 1)))
            {
                spinStoped = false;
                if (((5.f * (*acelerationIt) * this->startAceleration) > 0.6))
                {
                    this->startAceleration -= 0.00005f;
                }
                figure->getSprite().move(0, 5.f * (*acelerationIt) * this->startAceleration);
            }
            window.draw(figure->getSprite());
            if (figure->getSprite().getPosition().y > 1050)
            {
                figure->getSprite().setPosition(figure->getSprite().getPosition().x, -1200 + figure->getSprite().getPosition().y);
            }
        }
        acelerationIt++;
    }

    if (spinStoped)
    {
        spinActive = false;
    }
}

void FieldControler::alignment()
{
    for (auto colum : this->field)
    {
        for (auto figure : colum)
        {
            if ((figure->getSprite().getPosition().y < 980) && (figure->getSprite().getPosition().y > 970))
                figure->getSprite().setPosition(figure->getSprite().getPosition().x, 975);

            if ((figure->getSprite().getPosition().y < 680) && (figure->getSprite().getPosition().y > 670))
                figure->getSprite().setPosition(figure->getSprite().getPosition().x, 675);

            if ((figure->getSprite().getPosition().y < 380) && (figure->getSprite().getPosition().y > 370))
                figure->getSprite().setPosition(figure->getSprite().getPosition().x, 375);

            if ((figure->getSprite().getPosition().y < 80) && (figure->getSprite().getPosition().y > 70))
                figure->getSprite().setPosition(figure->getSprite().getPosition().x, 75);
        }
    }
}

int FieldControler::calculateScore()
{
    if (!spinStoped)
        return -1;

    this->alignment();

    int score = 0;

    auto iterColum1 = field[0].begin();
    auto iterColum2 = field[1].begin();
    auto iterColum3 = field[2].begin();
    auto iterColum4 = field[3].begin();

    while (!(((*iterColum1)->getSprite().getPosition().y > 74.5) &&
             ((*iterColum1)->getSprite().getPosition().y < 75.5)))
    {
        iterColum1++;
        if (iterColum1 == field[0].end())
            return -1;
    }

    while (!(((*iterColum2)->getSprite().getPosition().y > 74.5) &&
             ((*iterColum2)->getSprite().getPosition().y < 75.5)))
    {
        iterColum2++;
        if (iterColum2 == field[1].end())
            return -1;
    }

    while (!(((*iterColum3)->getSprite().getPosition().y > 74.5) &&
             ((*iterColum3)->getSprite().getPosition().y < 75.5)))
    {
        iterColum3++;
        if (iterColum3 == field[2].end())
            return -1;
    }

    while (!(((*iterColum4)->getSprite().getPosition().y > 74.5) &&
             ((*iterColum4)->getSprite().getPosition().y < 75.5)))
    {
        iterColum4++;
        if (iterColum4 == field[0].end())
            return -1;
    }

    for (int i = 0; i < 3; i++)
    {
        if ((*iterColum1)->getType() == (*iterColum2)->getType())
        {
            if ((*iterColum2)->getType() == (*iterColum3)->getType())
            {
                if ((*iterColum3)->getType() == (*iterColum4)->getType())
                {
                    score += 200;
                }
                else
                {
                    score += 100;
                }
            }
            else
            {
                score += 100;
            }
        }

        if ((*iterColum2)->getType() == (*iterColum3)->getType())
        {
            if ((*iterColum3)->getType() == (*iterColum4)->getType())
            {
                score += 100;
            }
            else
            {
                score += 100;
            }
        }

        if ((*iterColum3)->getType() == (*iterColum4)->getType())
        {
            score += 100;
        }

        iterColum1++;
        iterColum2++;
        iterColum3++;
        iterColum4++;

        if (iterColum1 == field[0].end())
            iterColum1 = field[0].begin();

        if (iterColum2 == field[1].end())
            iterColum2 = field[1].begin();

        if (iterColum3 == field[2].end())
            iterColum3 = field[2].begin();

        if (iterColum4 == field[3].end())
            iterColum4 = field[3].begin();
    }

    return score;
}