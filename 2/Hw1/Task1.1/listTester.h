#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "listArray.h"
#include "listPointer.h"

class ListTester : public QObject
{
	Q_OBJECT
public:
	explicit ListTester(QObject *parent = 0) : QObject(parent) {}

private:
	List *arrayList;
	List *pointerList;

private slots:
	void init()
	{
		arrayList = new ListArray;
		pointerList = new ListPointer;
	}

	void cleanup()
	{
		delete arrayList;
		delete pointerList;
	}

	void testAddInPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
	}

	void testAddInArrayList()
	{
		for(int i = 0; i < 5; i++)
			arrayList->addValue(i);
	}

	/**
	 * Function "increaseList" is called when the array is full
	 * and increases its size by half, so to test it enough to
	 * add to the list more elements than its initial size
	 */
	void testIncreaseArrayList()
	{
		for(int i = 0; i < 20; i++)
			arrayList->addValue(i);
	}

	void testFindValueInPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->findPositionOfValue(4) == 1, "Incorrect position");
		QVERIFY2(pointerList->findPositionOfValue(4) != 4, "Incorrect position");
	}

	void testFindValueInArrayList()
	{
		for(int i = 0; i < 5; i++)
			arrayList->addValue(i);
		QVERIFY2(arrayList->findPositionOfValue(4) == 4, "Incorrect position");
		QVERIFY2(arrayList->findPositionOfValue(4) != 1, "Incorrect position");
	}

	void testRemoveFromPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->removeValue(2), "The existing item has not been deleted");
		QVERIFY2(!pointerList->removeValue(2), "You cannot delete a nonexistent element");
	}

	void testRemoveFromArrayList()
	{
		for(int i = 0; i < 5; i++)
			arrayList->addValue(i);
		QVERIFY2(arrayList->removeValue(2), "The existing item has not been deleted");
		QVERIFY2(!arrayList->removeValue(2), "You cannot delete a nonexistent element");
	}

	void testLengthOfPointerList()
	{
		QVERIFY2(pointerList->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->length() == 5, "Incorrect length");
	}

	void testLengthOfArrayList()
	{
		QVERIFY2(arrayList->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			arrayList->addValue(i);
		QVERIFY2(arrayList->length() == 5, "Incorrect length");
	}

	void testPointerListIsEmpty()
	{
		QVERIFY2(pointerList->isEmpty(), "List is not empty");
		pointerList->addValue(8);
		QVERIFY2(!pointerList->isEmpty(), "List is not empty");
	}

	void testArrayListIsEmpty()
	{
		QVERIFY2(arrayList->isEmpty(), "List is not empty");
		arrayList->addValue(8);
		QVERIFY2(!arrayList->isEmpty(), "List is not empty");
	}
};
