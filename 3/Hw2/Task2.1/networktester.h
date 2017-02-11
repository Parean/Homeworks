#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "infectionchecker/testinfectionchecker.h"
#include "infectionchecker/randominfectionchecker.h"
#include "computer/debiancomputer.h"
#include "computer/ubuntucomputer.h"
#include "computer/windowscomputer.h"
#include "network.h"

class NetworkTester : public QObject
{
    Q_OBJECT

public:
    explicit NetworkTester(QObject *parent = 0):
        QObject(parent) {}

private:
    QVector<Computer *> computers;
    TestInfectionChecker *testChecker = new TestInfectionChecker();
    RandomInfectionChecker *randomChecker = new RandomInfectionChecker;

    void computerInfectedWithCorrectProbability()
    {
        testChecker->addTestProbabilitiy(computers[0]->getProbability());

        computers[0]->tryInfected(true);
        computers[0]->connectWithOtherComputer(computers[1]);

        Network network(computers, testChecker);
        network.start(2);
        QVERIFY2(computers[1]->isInfected(), "Computer infected with incorrect probability");
    }

private slots:
    void init()
    {
        testChecker->clearTestProbabilities();
        computers.clear();
    }

    void cleanupTestCase()
    {
        delete testChecker;
        delete randomChecker;
    }

    void firstInfected()
    {
        Network network(1, testChecker);
        network.start(1);
        QVERIFY2(network.getNumOfInfected() == 1, "First computer is not infected");
    }

    void UbuntuComputerInfectedWithCorrectProbability()
    {
        computers << new UbuntuComputer << new UbuntuComputer;
        computerInfectedWithCorrectProbability();
    }

    void DebianComputerInfectedWithCorrectProbability()
    {
        computers << new DebianComputer << new DebianComputer;
        computerInfectedWithCorrectProbability();
    }

    void WindowsComputerInfectedWithCorrectProbability()
    {
        computers << new WindowsComputer << new WindowsComputer;
        computerInfectedWithCorrectProbability();
    }

    void checkInfectionsIncrease()
    {
        int numOfInfected = 0;
        for (int i = 2; i < 100; i++)
        {
            Network network(i, randomChecker);
            while(!network.isEnd())
            {
                network.makeStep();
                QVERIFY2(numOfInfected <= network.getNumOfInfected(), "Number of infected computers has decreased");
                numOfInfected = network.getNumOfInfected();
            }
            numOfInfected = 0;
        }
    }

    void checkInfectionSequence()
    {
        int numOfComputers = 6;

        Network network(numOfComputers, randomChecker);
        auto networkComputers = network.getComputers();

        QVector<bool> infectedNeighbours(numOfComputers);
        for(int i = 0; i < numOfComputers; i++)
        {
            infectedNeighbours[i] = networkComputers[i]->areNeighboursInfected();
        }

        auto statusOfInfectionBeforeStep = network.getStatusOfInfection();
        QVector<bool> statusOfInfectionAfterStep(numOfComputers);

        while(!network.isEnd())
        {
            network.makeStep();

            statusOfInfectionAfterStep = network.getStatusOfInfection();
            for(int i = 0; i < numOfComputers; i++)
            {
                infectedNeighbours[i] = networkComputers[i]->areNeighboursInfected();
                if(statusOfInfectionAfterStep[i] != statusOfInfectionBeforeStep[i])
                {
                    QVERIFY2(infectedNeighbours[i], "Computer was infected, but its neighbours were not");
                }
            }

            statusOfInfectionBeforeStep = statusOfInfectionAfterStep;
        }
    }

    void infectionWithAbsoluteProbability()
    {
        testChecker->addTestProbabilitiy(30);
        testChecker->addTestProbabilitiy(40);
        testChecker->addTestProbabilitiy(50);
        int numOfComputers = 10;

        Network network(numOfComputers, testChecker);
        network.makeStep();
        auto computers = network.getComputers();
        for(int i = 0; i < numOfComputers; i++)
        {
            QVERIFY2(computers[i]->isInfected(), "There is uninfected computer, and it is impossible");
        }
    }

};



