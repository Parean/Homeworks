#pragma once

#include <qtCore/QObject>
#include <QtTest/QTest>

#include "hashTable.h"

class HashTableTester : public QObject
{
	Q_OBJECT
public:
	explicit HashTableTester(QObject *parent = 0) : QObject(parent) {}

private:
	HashTable *hashTable;
	QString string = "Value";
	int const size = 10000;

private slots:
	void init()
	{
		hashTable = new HashTable(50);
	}

	void cleanup()
	{
		delete hashTable;
	}

	void testAddOneValueInTable()
	{
		hashTable->addInTable(string);
		QVERIFY2(hashTable->isPlaced(string), "The element was not added");
	}

	void testAddManyElementsInTable()
	{
		for(int i = 0; i < size; i++)
		{
			QString string = QString::number(i);
			hashTable->addInTable(string);
		}
	}

	void testIsPlaced()
	{
		QVERIFY2(!hashTable->isPlaced(string), "The function return incorrect value");
		hashTable->addInTable(string);
		QVERIFY2(hashTable->isPlaced(string), "The function return incorrect value");
	}

	void testRemoveFromTable()
	{
		hashTable->addInTable(string);
		hashTable->removeFromTable(string);
		QVERIFY2(!hashTable->isPlaced(string), "The element was not removed");
	}

	void testFindMaxCollision()
	{
		for(int i = 0; i < size; i++)
		{
			QString string = QString::number(i);
			hashTable->addInTable(string);
		}
		QVERIFY2(hashTable->findMaxCollision() == 16, "The function return incorrect value");
	}

	void testSwitchHashFunction()
	{
		for(int i = 0; i < size; i++)
		{
			QString string = QString::number(i);
			hashTable->addInTable(string);
		}
		hashTable->switchHashFunction(ly);
	}
};

