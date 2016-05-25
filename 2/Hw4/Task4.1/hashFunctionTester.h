#pragma once

#include <QTcore/QObject>
#include <QtTest/QTest>

#include "hashFaq6.h"
#include "hashLy.h"
#include "hashRot13.h"

class HashFunctionTester : public QObject
{
	Q_OBJECT
public:
	explicit HashFunctionTester(QObject *parent = 0) : QObject(parent) {}

private:
	HashFunction *hashLy = new HashLy();
	HashFunction *hashRot13 = new HashRot13();
	HashFunction *hashFaq6 = new HashFaq6();
	QString string = "Value";
	int size = 50;

private slots:

	void cleanupTestCase()
	{
		delete hashLy;
		delete hashRot13;
		delete hashFaq6;
	}

	void testHashLyCalculate()
	{
		QVERIFY2(hashLy->hashCalculate(string, size) == 34, "Function return incorrect value");
	}

	void testHashFaq6Calculate()
	{
		QVERIFY2(hashFaq6->hashCalculate(string, size) == 3, "Function return incorrect value");
	}

	void testHashRot13Calculate()
	{
		QVERIFY2(hashRot13->hashCalculate(string, size) == 7, "Function return incorrect value");
	}
};



