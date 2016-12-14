#include <iostream>
#include <QTime>
#include <QThread>

#include "network.h"

Network::Network(int number):
	numOfComputers(number)
{
	if (number < 1)
		throw IncorrectNumberOfComputers();

	QTime midnight(0,0,0);
	qsrand(midnight.secsTo(QTime::currentTime()));


	for (int i = 0; i < numOfComputers; i++)
	{
		QVector<bool> edges(number);
		Computer *computer = createComputer();
		if (qrand() % 2)
		{
			computer->setInfected();
			numOfInfected++;
		}

		QPair<Computer*, QVector<bool>> pair(computer, edges);
		network.push_back(pair);
	}

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
		grafIsConnected = false;
		while(!grafIsConnected)
		{
			for (int j = i + 1; j < numOfComputers; j++)
			{
				bool isConnected = qrand() % 2;
				if (isConnected)
				{
					network[i].second.replace(j, true);
					network[j].second.replace(i, true);
					grafIsConnected = true;
				}
			}
		}
	}
}

Computer *Network::createComputer()
{
	systems state = static_cast<systems>(qrand() % 3);
	Computer *computer = nullptr;

	switch (state)
	{
	case windows:
	{
		computer = new WindowsComputer;
		break;
	}
	case ubuntu:
	{
		computer = new UbuntuComputer;
		break;
	}
	case debian:
	{
		computer = new DebianComputer;
	}
	}

	return computer;
}

void Network::checkInfection()
{
    if (isEnd())
        return;

	for (int i = 0; i < numOfComputers; i++)
	{
		if (network.at(i).first->isInfected())
		{
			for (int j = 0; j < numOfComputers; j++)
			{
				if (network.at(i).second.at(j) && !network.at(j).first->isInfected())
				{
                    virus.infect(network.at(j).first);
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
			std::cout << "infected\n";
		else
			std::cout << "not infected\n";
	}

	std::cout << "\nThe total number of infected computers: " << numOfInfected;
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

void Network::start()
{
    std::cout << "\nNumber of computers in the network: " << numOfComputers;
    std::cout << "\nCurrent network:\n\n";
    printNetwork();

	std::cout << "\n\nThe network have started to work\n"
				 "You will receive a status report";
	QThread::sleep(2);

	if (numOfComputers == 1 && !network.at(0).first->isInfected())
	{
		std::cout << "\nSingle computer in the network is not infected";
		return;
	}

	while(true)
	{
        printStatus();
		if (numOfComputers == numOfInfected)
		{
			std::cout << "\nAll computers are infected";
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
