#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "network.h"

class NetworkTester : public QObject
{
    Q_OBJECT

public:
    explicit NetworkTester(QObject *parent = 0):
        QObject(parent) {}

private:
    int numOfInfected = 0;

private slots:
    void init()
    {
        numOfInfected = 0;
    }

    void trivialNetwork()
    {
        Network network(1);
        numOfInfected = network.getNumOfInfected();
        network.start();
        QVERIFY2(network.getNumOfInfected() == numOfInfected, "Single computer can't change state");
    }

    void checkInfectionSecuence()
    {
        for (int i = 2; i < 100; i++)
        {
            numOfInfected = 0;
            Network network(i);
            while(!network.isEnd())
            {
                network.checkInfection();
                QVERIFY2(numOfInfected <= network.getNumOfInfected(), "Number of infected computers has decreased");
                numOfInfected = network.getNumOfInfected();
            }
        }
    }

    void correctOrderOfInfection()
    {
        bool isCorrectOrder = true;
        int size = 5;
        Network network(size);
        auto lastStatusOfInfection = network.getStatusOfInfection();
        auto edges = network.getNetwork();
        while(!network.isEnd())
        {
            network.checkInfection();
            auto currentStatusOfInfection = network.getStatusOfInfection();

            for (int i = 0; i < size; i++)
            {
                if(currentStatusOfInfection.at(i) - lastStatusOfInfection.at(i))
                {
                    bool isCorrectOrder = false;
                    for (int j = 0; j < size; j++)
                    {
                        if (edges.at(i).at(j) == (lastStatusOfInfection.at(j) == true))
                        {
                            isCorrectOrder = true;
                            break;
                        }
                    }
                }
            }
            lastStatusOfInfection = currentStatusOfInfection;
        }
        QVERIFY2(isCorrectOrder, "Computers infected incorrectly");
    }
};



