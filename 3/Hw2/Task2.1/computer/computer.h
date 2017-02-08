#pragma once

#include "generator/generator.h"

#include <QString>
#include <QVector>

/**
 * @brief The Computer class
 * Virtual class implements computer without operating system
 */
class Computer
{
public:
	virtual ~Computer() {}

	/**
	 * @brief isInfected
     * @return true if computer is tryInfected and false if not
	 */
    bool isInfected() const;

	/**
	 * @brief setInfected
     * Function to make computer tryInfected
	 */
    void setInfected();

	/**
	 * @brief getProbability
     * @return probability of tryInfection
	 * The probability depends on the type derived class system
	 */
	virtual int getProbability() const = 0;

	/**
	 * @brief getSystem
	 * @return type of operating system
	 */
	virtual QString getSystem() const = 0;

    void tryInfect(Generator *generator);
    void tryInfected(int probability);
    void connectWithOtherComputer(Computer *otherComputer);

protected:
	int const probabilityOfInfection = 0;

private:
    QVector<Computer *> neighbours;
	bool computerInfected = false;
};

