#pragma once

#include "generator.h"

class RandomGenerator: public Generator
{
public:
    RandomGenerator();
    bool getProbability() const;
};
