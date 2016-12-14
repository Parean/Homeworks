#pragma once

#include <QString>

#include "computer.h"

/**
 * @brief The UbuntuComputer class
 * Class implements computer with "ubuntu" operating system
 */
class UbuntuComputer : public Computer
{
public:
	virtual QString getSystem() const
	{
		return QString("ubuntu");
	}

	virtual int getProbability() const
	{
		return probabilityOfInfection;
	}

private:
	int const probabilityOfInfection = 40;
};
