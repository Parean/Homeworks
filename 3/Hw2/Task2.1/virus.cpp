#include <QtGlobal>

#include "virus.h"

void Virus::tryInfect(Computer *computer)
{
	if (computer->isInfected())
		return;

	int probability = qrand() % 100;
	if (probability < computer->getProbability())
	{
		computer->setInfected();
	}
}
