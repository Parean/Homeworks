#pragma once

#include <QTime>

#include "computer.h"

/**
 * @brief The Virus class
 * Class implements virus which can infect the computer with a some probability of infection,
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
	 * @brief infect
	 * Function to infect the computer
	 */
    void infect(Computer *computer);
};
