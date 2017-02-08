#pragma once

#include <QString>

#include "computer/computer.h"

/**
 * @brief The DebianComputer class
 * Class implements computer with "debian" operating system
 */
class DebianComputer : public Computer
{
public:
	virtual QString getSystem() const
	{
		return "debian";
	}

	virtual int getProbability() const
	{
		return probabilityOfInfection;
	}

private:
	int const probabilityOfInfection = 30;
};
