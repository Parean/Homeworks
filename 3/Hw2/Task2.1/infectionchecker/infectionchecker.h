#pragma once

/**
 * @brief The InfectionChecker class
 * It represent object that decides whether the computer is infected
 */
class InfectionChecker
{
public:
    virtual bool isInfected(int probability) const = 0;
    virtual ~InfectionChecker() {}
};
