#include "computer/computer.h"

bool Computer::isInfected() const
{
    return computerInfected;
}


int Computer::getProbability() const
{
    return probabilityOfInfection;
}

void Computer::connectWithOtherComputer(Computer *otherComputer)
{
    this->neighbours.append(otherComputer);
    otherComputer->neighbours.append(this);
}

bool Computer::isConnectWithOtherComputer(Computer *otherComputer) const
{
    return neighbours.contains(otherComputer);
}

int Computer::tryInfect(InfectionChecker *infectionChecker)
{
    int numOfInfected = 0;
    for(auto n : neighbours)
    {
        if (n->isInfected())
            continue;

        numOfInfected += n->tryInfected(infectionChecker->isInfected(probabilityOfInfection));
    }

    return numOfInfected;
}

bool Computer::areNeighboursInfected() const
{
    for(auto n : neighbours)
    {
        if (n->isInfected())
            return true;
    }

    return false;
}

bool Computer::tryInfected(bool isInfected)
{
    return computerInfected = isInfected;
}
