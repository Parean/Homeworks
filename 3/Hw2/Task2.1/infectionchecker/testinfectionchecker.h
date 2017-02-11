#pragma once

#include "infectionchecker.h"

#include <QList>

/**
 * @brief The TestInfectionChecker class
 * It decides whether the neighbor is infected only on the basis of input probability
 */
class TestInfectionChecker: public InfectionChecker
{
public:
    bool isInfected(int probability) const;
    void addTestProbabilitiy(int probability);
    void clearTestProbabilities();

private:
    QList<int> testProbabilities;
};
