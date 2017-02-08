#include <iostream>

#include <QThread>

#include "network.h"

Network::Network(int number):
    numOfComputers(number)
{
    if (number < 1)
        throw IncorrectNumberOfComputers();

    for (int i = 0; i < numOfComputers; i++)
    {
        Computer *computer = createComputer();
        network.push_back(computer);
    }

    network[0]->setInfected();
    generateNetwork();
}

Network::~Network()
{
    for (int i = 0; i < numOfComputers; i++)
        delete network.at(i).first;
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

void Network::checkInfection()
{
    if (isEnd())
        return;

    for (int i = 0; i < numOfComputers; i++)
    {
        if (network[i]->isInfected())
        {
            for (int j = 0; j < numOfComputers; j++)
            {
                if (network.at(i).second.at(j) && !network.at(j).first->isInfected())
                {
                    virus.tryInfect(network.at(j).first);
                    if (network.at(j).first->isInfected())
                        numOfInfected++;
                }
            }
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
        if (network.at(i).first->isInfected())
            std::cout << "tryInfected\n";
        else
            std::cout << "not tryInfected\n";
    }

    std::cout << "\nThe total number of tryInfected computers: " << numOfInfected;
}

void Network::printNetwork() const
{
    for (int i = 0; i < numOfComputers; i++)
    {
        for (int j = 0; j < numOfComputers; j++)
        {
            if (network.at(i).second.at(j))
                std::cout << 1 << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << "\n";
    }
}

QVector<QVector<bool>> Network::getNetwork() const
{
    QVector<QVector<bool>> computers;
    for (int i = 0; i < numOfComputers; i++)
    {
        QVector<bool> edges = QVector<bool>(network.at(i).second);
        computers.push_back(edges);
    }

    return computers;
}

QVector<bool> Network::getStatusOfInfection() const
{
    QVector<bool> computers;
    for (int i = 0; i < numOfComputers; i++)
    {
        computers.append(network.at(i).first->isInfected());
    }

    return computers;
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
            std::cout << "\nAll computers are tryInfected";
            return;
        }

        checkInfection();
        QThread::sleep(4);
    }
}

bool Network::isEnd() const
{
    return numOfInfected == numOfComputers;
}
