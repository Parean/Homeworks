#pragma once

#include <QVector>
#include <QPair>
#include <QtGlobal>

#include "infectionchecker/infectionchecker.h"
#include "computer/computer.h"
#include "computer/ubuntucomputer.h"
#include "computer/debiancomputer.h"
#include "computer/windowscomputer.h"

/**
 * @brief The IncorrectNumberOfComputers class
 * The class represents the exception that is thrown when user try to create a
 * network with an invalid number of computers
 */
class IncorrectNumberOfComputers {};

/**
 * @brief The systems enum
 * It represent types of operating systems in the network
 */
enum systems { windows, ubuntu, debian };

/**
 * @brief The Network class
 * Class represents network of computers with different operating systems, some of which are tryInfected
 */
class Network
{
public:

	/**
	 * @brief Network
     * The constructor takes as parameter the number of computers in the network and infection checker
	 */
    Network(int number, InfectionChecker *newInfectionChecker);

    /**
     * @brief Network
     * The constructor takes as parameter computers and infection checker
     */
    Network(QVector<Computer *> &computers, InfectionChecker *newInfectionChecker);
	~Network();

	/**
	 * @brief start
     * It starts work of the network
	 */
    void start(int steps);

	/**
     * @brief makeStep
     * It cheks whether the computers were infected on the current step
	 */
    void makeStep();

    /**
     * @brief getNumOfInfected
     * @return number of infected computers
     */
    int getNumOfInfected() const;

    /**
     * @brief getComputers
     * @return computers of network
     */
    QVector<Computer *> getComputers() const;

    /**
     * @brief getStatusOfInfection
     * if computer with index "i" is infected – array[i] == true, if not – array[i] == false
     */
    QVector<bool> getStatusOfInfection() const;

	void printNetwork() const;

    /**
     * @brief isEnd
     * @return true if all computers are infected
     */
    bool isEnd() const;

private:
    int numOfInfected = 0;
	int const numOfComputers = 0;
    QVector<Computer *> network;
    InfectionChecker *infectionChecker = nullptr;

    /**
     * @brief createComputer
     * It creates computer with random operating system
     * @return new computer
     */
    Computer *createComputer();

    /**
     * @brief generateNetwork
     * It creates random connected network
     */
    void generateNetwork();

    /**
     * @brief printStatus
     * Print status of the network on the current step
     */
    void printStatus() const;
};
