#pragma once

#include <QTime>

#include "computer/computer.h"

/**
 * @brief The Virus class
 * Class implements virus which can tryInfect the computer with a some probability of tryInfection,
 * that is determined by the operating system type
 */
class Virus
{
public:
	Virus()
	{
		QTime midnight(0,0,0);
		qsrand(midnight.secsTo(QTime::currentTime()));
	}

	/**
     * @brief tryInfect
     * Function to tryInfect the computer
	 */
    void tryInfect(Computer *computer);
};
