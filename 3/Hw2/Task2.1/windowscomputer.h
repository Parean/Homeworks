#pragma once

#include <QString>

#include "computer.h"

/**
 * @brief The WindowsComputer class
 * Class implements computer with "windows" operating system
 */
class WindowsComputer : public Computer
{
public:
	virtual QString getSystem() const
	{
		return QString("windows");
	}

	virtual int getProbability() const
	{
		return probabilityOfInfection;
	}

private:
	int const probabilityOfInfection = 50;
};
