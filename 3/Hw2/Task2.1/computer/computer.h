#pragma once

#include "infectionchecker/infectionchecker.h"

#include <QString>
#include <QVector>

/**
 * @brief The Computer class
 * Virtual class implements computer without operating system
 */
class Computer
{
public:

	/**
	 * @brief isInfected
     * @return true if computer is tryInfected and false if not
	 */
    bool isInfected() const;

	/**
	 * @brief getProbability
     * @return probability of tryInfection
	 * The probability depends on the type derived class system
	 */
    int getProbability() const;

	/**
	 * @brief getSystem
	 * @return type of operating system
	 */
	virtual QString getSystem() const = 0;

    /**
     * @brief tryInfect computer tries infect its neighbours
     * @param infectionChecker that decides whether the neighbor is infected
     * @return num of infected computers
     */
    int tryInfect(InfectionChecker *infectionChecker);

    /**
     * @brief tryInfected computer will infected if isInfected true
     * @return true if infected false if not
     */
    bool tryInfected(bool isInfected);
    void connectWithOtherComputer(Computer *otherComputer);
    bool isConnectWithOtherComputer(Computer *otherComputer) const;
    bool areNeighboursInfected() const;

protected:
    Computer(int probability): probabilityOfInfection(probability) {}

private:
    QVector<Computer *> neighbours;
    int const probabilityOfInfection = 0;
    bool computerInfected = false;
};

