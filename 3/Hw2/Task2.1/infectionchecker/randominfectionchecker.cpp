#include "randominfectionchecker.h"

#include <QTime>

RandomInfectionChecker::RandomInfectionChecker()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
}

bool RandomInfectionChecker::isInfected(int probability) const
{
    return probability < (qrand() % 100);
}
