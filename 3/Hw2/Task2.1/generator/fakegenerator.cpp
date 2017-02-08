#include "fakegenerator.h"

#include <QTime>

FakeGenerator::RandomGenerator()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

bool FakeGenerator::getProbability() const
{
    return qrand() % 100;
}
