#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bag.h"

class BagTester : public QObject
{
	Q_OBJECT
public:
	explicit BagTester(QObject *parent = 0) : QObject(parent) {}

private:
	Bag<int> *bag;
	int value;

private slots:
	void init()
	{
		bag = new Bag<int>;
		value = 10;
	}

	void cleanup()
	{
		delete bag;
	}

	void testAddOneElementInSet()
	{
		bag->addInSet(value, 1);
		QVERIFY2(bag->isPlaced(value), "The element was not added");
	}

	void testAddManyElementsInSet()
	{
		for (int i = 0; i < value; i++)
			bag->addInSet(i, 1);

		for (int i = 0; i < value; i++)
			QVERIFY2(bag->isPlaced(i), "The element was not added");
	}

	void testAddManySameElementsInSet()
	{
		for (int i = 0; i < value; i++)
			bag->addInSet(1, 1);
		QVERIFY2(bag->getNumOfElements(1) == value, "The function adds not all elements");
	}

	void testIsPlacedInEmptySet()
	{
		QVERIFY2(!bag->isPlaced(value), "Function return the element that is missing in the bag");
	}

	void testFindElement()
	{
		bag->addInSet(value, 1);
		QVERIFY2(bag->isPlaced(value), "The element was not found");
	}

	void testDeleteElementFromEmptySet()
	{
		bag->deleteElement(value, 1);
	}

	void testDeleteElement()
	{
		bag->addInSet(value, 1);
		bag->deleteElement(value, 1);
		QVERIFY2(!bag->isPlaced(value), "The element was not deleted");
	}

	void testRemovePartOfSameElements()
	{
		for (int i = 0; i < value; i++)
			bag->addInSet(1, 1);
		bag->deleteElement(1, 3);
		QVERIFY2(bag->getNumOfElements(1) == 7, "The function delete not all elements");
	}

	void testDeletingOfNonexistentElements()
	{
		bag->addInSet(1, 10);
		try
		{
			bag->deleteElement(1, 11);
			QVERIFY2(false, "Exception was not thrown");
		}
		catch (DeletingOfNonexistentElements &)
		{
			QVERIFY(true);
		}
	}

	void testIntersectionOfSets()
	{
		Bag<int> *secondSet = new Bag<int>;
		int const size = 10;
		int firstArray[size];
		int secondArray[size];

		for(int i = 0; i < size; i++)
		{
			firstArray[i] = i;
			secondArray[i] = i - 5;
			bag->addInSet(firstArray[i], 3);
			secondSet->addInSet(secondArray[i], 2);
		}

		Bag<int> *resultSet = Bag<int>::intersectionOfSets(bag, secondSet);
		for(int i = 0; i < 5; i++)
			QVERIFY2(resultSet->getNumOfElements(i) == 2, "The function adds not all elements");

		delete secondSet;
		delete resultSet;
	}

	void testMergeOfSets()
	{
		Bag<int> *secondSet = new Bag<int>;
		int const size = 10;
		int firstArray[size];
		int secondArray[size];

		for(int i = 0; i < size; i++)
		{
			firstArray[i] = i;
			secondArray[i] = i + 5;
			bag->addInSet(firstArray[i], 2);
			secondSet->addInSet(secondArray[i], 3);
		}

		Bag<int> *resultSet = Bag<int>::mergeOfSets(bag, secondSet);
		for(int i = 0; i < 5; i++)
			QVERIFY2(resultSet->getNumOfElements(i) == 2, "The function adds not all elements");
		for(int i = 6; i < 10; i++)
			QVERIFY2(resultSet->getNumOfElements(i) == 5, "The function adds not all elements");
		for(int i = 10; i < 15; i++)
			QVERIFY2(resultSet->getNumOfElements(i) == 3, "The function adds not all elements");

		delete secondSet;
		delete resultSet;
	}

};
