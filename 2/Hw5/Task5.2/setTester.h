#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "set.h"

class SetTester : public QObject
{
	Q_OBJECT
public:
	explicit SetTester(QObject *parent = 0) : QObject(parent) {}

private:
	SortedSet<int> *set;
	int value;

private slots:
	void init()
	{
		set = new SortedSet<int>;
		value = 10;
	}

	void cleanup()
	{
		delete set;
	}

	void testAddOneElementInSet()
	{
		set->addInSet(value);
		QVERIFY2(set->isPlaced(value), "The element was not added");
	}

	void testManyElementsInSet()
	{
		for (int i = 0; i < value; i++)
			set->addInSet(i);

		for (int i = 0; i < value; i++)
			QVERIFY2(set->isPlaced(i), "The element was not added");
	}

	void testIsPlacedInEmptySet()
	{
		QVERIFY2(!set->isPlaced(value), "Function return the element that is missing in the set");
	}

	void testFindElement()
	{
		set->addInSet(value);
		QVERIFY2(set->isPlaced(value), "The element was not found");
	}

	void testDeleteElemenFromEmptySet()
	{
		set->deleteElement(value);
	}

	void testDeleteElement()
	{
		set->addInSet(value);
		set->deleteElement(value);
		QVERIFY2(!set->isPlaced(value), "The element was not deleted");
	}

	void testIntersectionOfSets()
	{
		SortedSet<int> *secondSet = new SortedSet<int>;
		int const size = 10;
		int firstArray[size];
		int secondArray[size];

		for(int i = 0; i < size; i++)
		{
			firstArray[i] = i;
			secondArray[i] = i - 5;
			set->addInSet(firstArray[i]);
			secondSet->addInSet(secondArray[i]);
		}

		SortedSet<int> *resultSet = SortedSet<int>::intersectionOfSets(set, secondSet);
		for(int i = 0; i < 5; i++)
			QVERIFY2(resultSet->isPlaced(i), "The function adds not all elements");

		delete secondSet;
		delete resultSet;
	}

	void testMergeOfSets()
	{
		SortedSet<int> *secondSet = new SortedSet<int>;
		int const size = 10;
		int firstArray[size];
		int secondArray[size];

		for(int i = 0; i < size; i++)
		{
			firstArray[i] = i;
			secondArray[i] = i + 5;
			set->addInSet(firstArray[i]);
			secondSet->addInSet(secondArray[i]);
		}

		SortedSet<int> *resultSet = SortedSet<int>::mergeOfSets(set, secondSet);
		for(int i = 0; i < 15; i++)
			QVERIFY2(resultSet->isPlaced(i), "The function adds not all elements");

		delete secondSet;
		delete resultSet;
	}

};
