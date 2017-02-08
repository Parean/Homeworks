#include "computer/computer.h"

bool Computer::isInfected() const
{
    return computerInfected;
}

void Computer::setInfected()
{
    computerInfected = true;
}

void Computer::connectWithOtherComputer(Computer *otherComputer)
{
    this->neighbours.append(otherComputer);
    otherComputer->neighbours.append(this);
}

void Computer::tryInfect(Generator *generator)
{
    for(auto n : neighbours)
    {

    }
}

void Computer::tryInfected(int probability)
{

}
