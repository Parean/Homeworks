#pragma once

#include "generator.h"

class FakeGenerator: public Generator
{
public:
    FakeGenerator();
    bool getProbability() const;
};
