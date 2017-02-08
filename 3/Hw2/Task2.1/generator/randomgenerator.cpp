#include "randomgenerator.h"

#include <QTime>

RandomGenerator::RandomGenerator()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

bool RandomGenerator::getProbability() const
{
    return qrand() % 100;
}
