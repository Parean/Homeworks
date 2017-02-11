#pragma once

#include "infectionchecker.h"

/**
 * @brief The RandomInfectionChecker class
 * It decides whether the neighbor is infected on the basis of random and input probability
 */
class RandomInfectionChecker: public InfectionChecker
{
public:
    RandomInfectionChecker();
    bool isInfected(int probability) const;
};
