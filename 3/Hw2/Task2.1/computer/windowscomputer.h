#pragma once

#include <QString>

#include "computer/computer.h"

/**
 * @brief The WindowsComputer class
 * Class implements computer with "windows" operating system
 */
class WindowsComputer : public Computer
{
public:
    WindowsComputer(): Computer(30) {}

	virtual QString getSystem() const
	{
		return QString("windows");
	}
};
