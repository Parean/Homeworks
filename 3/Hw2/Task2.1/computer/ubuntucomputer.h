#pragma once

#include <QString>

#include "computer/computer.h"

/**
 * @brief The UbuntuComputer class
 * Class implements computer with "ubuntu" operating system
 */
class UbuntuComputer : public Computer
{
public:
    UbuntuComputer(): Computer(40) {}

	virtual QString getSystem() const
	{
		return QString("ubuntu");
	}
};
