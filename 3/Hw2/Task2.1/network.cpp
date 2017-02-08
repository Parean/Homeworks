#include <iostream>

#include <QThread>
#include <QtAlgorithms>

#include "network.h"

Network::Network(int number, InfectionChecker *newInfectionChecker):
    numOfComputers(number),
    numOfInfected(1),
    infectionChecker(newInfectionChecker)
{
    if (number < 1)
        throw IncorrectNumberOfComputers();

    for (int i = 0; i < numOfComputers; i++)
    {
        Computer *computer = createComputer();
        network.push_back(computer);
    }

    network[0]->tryInfected(true);
    generateNetwork();
}

Network::Network(QVector<Computer *> &computers, InfectionChecker *newInfectionChecker):
    infectionChecker(newInfectionChecker),
    numOfComputers(computers.length())
{
    network.resize(numOfComputers);
    qCopy(computers.begin(), computers.end(), network.begin());

    for(int i = 0; i < numOfComputers; i++)
        numOfInfected += network[i]->isInfected();
}

Network::~Network()
{
    network.clear();
}

void Network::generateNetwork()
{
    bool grafIsConnected = false;
    for (int i = 0; i < numOfComputers - 1; i++)
    {
        while(!grafIsConnected)
        {
            for (int j = i + 1; j < numOfComputers; j++)
            {
                bool isConnected = qrand() % 2;
                if (isConnected)
                {
                    network[i]->connectWithOtherComputer(network[j]);
                    grafIsConnected = true;
                }
            }
        }
        grafIsConnected = false;
    }
}

Computer *Network::createComputer()
{
    systems state = static_cast<systems>(qrand() % 3);

    switch (state)
    {
    case windows:
    {
        return new WindowsComputer;
    }
    case ubuntu:
    {
        return new UbuntuComputer;
    }
    case debian:
    {
        return new DebianComputer;
    }
    }
}

void Network::makeStep()
{
    if (isEnd())
        return;

    for (int i = 0; i < numOfComputers; i++)
    {
        if (network[i]->isInfected())
        {
            numOfInfected += network[i]->tryInfect(infectionChecker);
        }
    }
}

int Network::getNumOfInfected() const
{
    return numOfInfected;
}

void Network::printStatus() const
{

    std::cout << "\n\n-----------------------------------------"
                 "\nCurrent status:\n\n";

    for (int i = 0; i < numOfComputers; i++)
    {
        std::cout << "Computer " << i + 1 << " is ";
        if (network[i]->isInfected())
            std::cout << "infected\n";
        else
            std::cout << "not infected\n";
    }

    std::cout << "\nThe total number of infected computers: " << numOfInfected << "\n\n";
}

QVector<Computer *> Network::getComputers() const
{
     QVector<Computer *> computers(network);
     return computers;
}

QVector<bool> Network::getStatusOfInfection() const
{
    QVector<bool> status(numOfComputers);
    for(int i = 0; i < numOfInfected; i++)
    {
        status[i] = network[i]->isInfected();
    }

    return status;
}

void Network::printNetwork() const
{
    for (int i = 0; i < numOfComputers; i++)
    {
        for (int j = 0; j < numOfComputers; j++)
        {
            if (i == j || network[i]->isConnectWithOtherComputer(network[j]))
                std::cout << 1 << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << "\n";
    }
}

void Network::start(int steps)
{
    std::cout << "\nNumber of computers in the network: " << numOfComputers;
    std::cout << "\nCurrent network:\n\n";
    printNetwork();

    std::cout << "\n\nThe network have started to work\n"
                 "You will receive a status report";
    QThread::sleep(2);

    for(int i = 0; i < steps; i++)
    {
        printStatus();
        if (numOfComputers == numOfInfected)
        {
            std::cout << "\nAll computers are infected\n\n";
            return;
        }

        makeStep();
        QThread::sleep(4);
    }
}

bool Network::isEnd() const
{
    return numOfInfected == numOfComputers;
}
