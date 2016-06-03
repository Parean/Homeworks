#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "listPointer.h"

class ListTester : public QObject
{
	Q_OBJECT
public:
	explicit ListTester(QObject *parent = 0) : QObject(parent) {}

private:
	ListPointer *pointerList;

private slots:
	void init()
	{
		pointerList = new ListPointer;
	}

	void cleanup()
	{
		delete pointerList;
	}

	void testAddInPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
	}

	void testFindValueInPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->findPositionOfValue(4) == 1, "Incorrect position");
		QVERIFY2(pointerList->findPositionOfValue(4) != 4, "Incorrect position");
	}

	void testRemoveFromPointerList()
	{
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->removeValue(2), "The existing item has not been deleted");
		QVERIFY2(!pointerList->removeValue(2), "You cannot delete a nonexistent element");
	}

	void testLengthOfPointerList()
	{
		QVERIFY2(pointerList->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			pointerList->addValue(i);
		QVERIFY2(pointerList->length() == 5, "Incorrect length");
	}

	void testPointerListIsEmpty()
	{
		QVERIFY2(pointerList->isEmpty(), "List is not empty");
		pointerList->addValue(8);
		QVERIFY2(!pointerList->isEmpty(), "List is not empty");
	}
};
