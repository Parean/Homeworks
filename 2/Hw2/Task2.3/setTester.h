#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "sortedSet.h"

class SetTester : public QObject
{
	Q_OBJECT
public:
	explicit SetTester(QObject *parent = 0) : QObject(parent) {}

private:
	SortedSet *set;
	int const sizeOfList = 10;

private slots:
	void init()
	{
		set = new SortedSet;
	}

	void cleanup()
	{
		delete set;
	}

	void testCompareForEquality()
	{
		ListPointer *firstList = new ListPointer;
		ListPointer *secondList = new ListPointer;
		for (int i = 0; i < sizeOfList; i++)
		{
			firstList->addValue(i);
			secondList->addValue(i);
		}
		QVERIFY2(ListsComparator::compare(firstList, secondList) == 0,
				 "Incorrect comparison");
	}

	void testCompareForInequality()
	{
		ListPointer *firstList = new ListPointer;
		ListPointer *secondList = new ListPointer;
		for (int i = 0; i < sizeOfList; i++)
		{
			firstList->addValue(i);
			secondList->addValue(i);
		}
		firstList->addValue(100);
		QVERIFY2(ListsComparator::compare(firstList, secondList) == 1,
				 "Incorrect comparison");
	}

	void testAddInSet()
	{
		ListPointer *list = new ListPointer;
		for (int i = 0; i < sizeOfList; i++)
		{
			list->addValue(i);
		}
		set->addInSet(list);
		QVERIFY2(ListsComparator::compare(list, set->findElement(sizeOfList)) == 0,
				 "The element was not added");
	}

	void testFindElementInEmptySet()
	{
		QVERIFY2(!set->findElement(sizeOfList), "Function return the element that is missing in the set");
	}

	void testFindElement()
	{
		ListPointer *list = new ListPointer;
		for (int i = 0; i < sizeOfList; i++)
		{
			list->addValue(i);
		}
		set->addInSet(list);
		QVERIFY2(set->findElement(sizeOfList)->length() == sizeOfList, "The element was not found");
	}

	void testDeleteElemenFromEmptySet()
	{
		set->deleteElement(sizeOfList);
	}

	void testDeleteElement()
	{
		ListPointer *list = new ListPointer;
		for (int i = 0; i < sizeOfList; i++)
		{
			list->addValue(i);
		}
		set->addInSet(list);
		set->deleteElement(sizeOfList);
		QVERIFY2(!set->findElement(sizeOfList), "The element was not deleted");
	}
};
