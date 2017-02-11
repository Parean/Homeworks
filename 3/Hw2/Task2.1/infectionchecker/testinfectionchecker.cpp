#include "testinfectionchecker.h"

bool TestInfectionChecker::isInfected(int probability) const
{
    return testProbabilities.contains(probability);
}

void TestInfectionChecker::addTestProbabilitiy(int probability)
{
    testProbabilities.append(probability);
}

void TestInfectionChecker::clearTestProbabilities()
{
    testProbabilities.clear();
}
