#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "virus.h"
#include "computer/ubuntucomputer.h"
#include "computer/debiancomputer.h"
#include "computer/windowscomputer.h"

class VirusTester : public QObject
{
	Q_OBJECT

public:
	explicit VirusTester(QObject *parent = 0):
		QObject(parent) {}

private:
    Virus virus;
	int numOfInfected = 0;
	int numOfInfection = 1000;

	void deleteComputer(Computer *computer)
	{
		delete computer;
	}

private slots:
	void init()
	{
		numOfInfected = 0;
	}

    void testDebianComputer()
    {
        for (int i = 0; i < numOfInfection; i++)
        {
            Computer *computer = new DebianComputer;
            virus.tryInfect(computer);
            if(computer->isInfected())
                numOfInfected++;
            deleteComputer(computer);
        }
        float probability = numOfInfected / static_cast<float>(numOfInfection);
        QVERIFY2(probability < 0.4 && probability > 0.2, "Computers are tryInfected with incorrect probability");
    }

	void testUbuntuComputer()
	{
		for (int i = 0; i < numOfInfection; i++)
		{
			Computer *computer = new UbuntuComputer;
            virus.tryInfect(computer);
			if(computer->isInfected())
				numOfInfected++;
			deleteComputer(computer);
		}
        float probability = numOfInfected / static_cast<float>(numOfInfection);
        QVERIFY2(probability < 0.5 && probability > 0.3, "Computers are tryInfected with incorrect probability");
	}

    void testWindowsComputer()
    {
        for (int i = 0; i < numOfInfection; i++)
        {
            Computer *computer = new WindowsComputer;
            virus.tryInfect(computer);
            if(computer->isInfected())
                numOfInfected++;
            deleteComputer(computer);
        }
        float probability = numOfInfected / static_cast<float>(numOfInfection);
        QVERIFY2(probability < 0.6 && probability > 0.4, "Computers are tryInfected with incorrect probability");

    }
};



