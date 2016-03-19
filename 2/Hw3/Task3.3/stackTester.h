#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "stackPointer.h"

class StackTester : public QObject
{
	Q_OBJECT
public:
	explicit StackTester(QObject *parent = 0) : QObject(parent) {}

private:
	StackPointer *pointerStack;

private slots:
	void init()
	{
		pointerStack = new StackPointer;
	}

	void cleanup()
	{
		delete pointerStack;
	}

	void testPushInPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(!pointerStack->isEmpty(), "Stack is empty");
	}

	void testTopPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->top() == 4, "Incorrect value");
	}

	void testPopFromPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->pop() == 4, "Incorrect value");
		QVERIFY2(pointerStack->pop() != 4, "Incorrect value");
	}

	void testFindValueInPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->findPositionOfValue(4) == 1, "Incorrect position");
		QVERIFY2(pointerStack->findPositionOfValue(4) != 4, "Incorrect position");
	}

	void testLengthOfPointerStack()
	{
		QVERIFY2(pointerStack->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->length() == 5, "Incorrect length");
	}

	void testPointerStackIsEmpty()
	{
		QVERIFY2(pointerStack->isEmpty(), "Stack is not empty");
		pointerStack->push(8);
		QVERIFY2(!pointerStack->isEmpty(), "Stack is not empty");
	}
};
