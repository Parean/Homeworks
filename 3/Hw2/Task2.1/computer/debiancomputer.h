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
    DebianComputer(): Computer(30) {}

	virtual QString getSystem() const
	{
        return QString("debian");
	}
};
