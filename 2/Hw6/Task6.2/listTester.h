#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "uniqueList.h"

class ListTester : public QObject
{
	Q_OBJECT
public:
	explicit ListTester(QObject *parent = 0) : QObject(parent) {}

private:
	UniqueList<int> *list;

private slots:
	void init()
	{
		list = new UniqueList<int>;
	}

	void cleanup()
	{
		delete list;
	}

	void testAddUniqueValue()
	{
		list->addValue(0);
	}

	void testListIsEmpty()
	{
		QVERIFY2(list->isEmpty(), "List should be empty");
		list->addValue(8);
		QVERIFY2(!list->isEmpty(), "List should not be empty");
	}

	void testLengthOfList()
	{
		QVERIFY2(list->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			list->addValue(i);
		QVERIFY2(list->length() == 5, "Incorrect length");
	}

	void testFindValueInList()
	{
		for(int i = 0; i < 5; i++)
			list->addValue(i);
		QVERIFY2(list->isPlaced(3), "Existing element not found");
	}

	void testFindPositionInList()
	{
		for(int i = 0; i < 5; i++)
			list->addValue(i);
		QVERIFY2(list->findPositionOfValue(4) == 1, "Incorrect position");
		QVERIFY2(list->findPositionOfValue(4) != 4, "Incorrect position");
	}

	void testRemoveExistingElement()
	{
		list->addValue(2);
		list->removeValue(2);
		QVERIFY2(!list->isPlaced(2), "The existing item has not been deleted");
	}

	void testAddExistingValue()
	{
		list->addValue(0);
		try
		{
			list->addValue(0);
			QVERIFY2(false, "Exception was not thrown");
		}
		catch(AddExistingValue &)
		{
			QVERIFY(true);
		}
	}

	void testRemoveNotExistingValue()
	{
		try
		{
			list->removeValue(0);
			QVERIFY2(false, "Exception was not thrown");
		}
		catch (RemoveNotExistingValue &)
		{
			QVERIFY(true);
		}
	}
};
