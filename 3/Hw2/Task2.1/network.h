#pragma once

#include <QVector>
#include <QPair>
#include <QtGlobal>

#include "computer.h"
#include "ubuntucomputer.h"
#include "debiancomputer.h"
#include "windowscomputer.h"
#include "virus.h"

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
 * Class represents network of computers with different operating systems, some of which are infected
 */
class Network
{
public:

	/**
	 * @brief Network
	 * The constructor takes as parameter the number of computers in the network
	 */
	Network(int number);
	~Network();

	/**
	 * @brief start
	 * It starts work of the network
	 */
	void start();

	/**
	 * @brief checkInfection
	 * It cheks whether the computers were infected on the current step
	 */
	void checkInfection();

    /**
     * @brief getNumOfInfected
     * @return number of infected computers
     */
    int getNumOfInfected() const;

    QVector<bool> getStatusOfInfection() const;
	void printNetwork() const;
    QVector<QVector<bool> > getNetwork() const;
    bool isEnd() const;

private:
	int numOfInfected = 0;
	int const numOfComputers = 0;
	QVector< QPair<Computer*, QVector<bool>> > network;
    Virus virus;

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
