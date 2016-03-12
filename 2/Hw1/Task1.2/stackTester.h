#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "stackArray.h"
#include "stackPointer.h"

class StackTester : public QObject
{
	Q_OBJECT
public:
	explicit StackTester(QObject *parent = 0) : QObject(parent) {}

private:
	Stack *arrayStack;
	Stack *pointerStack;

private slots:
	void init()
	{
		arrayStack = new StackArray;
		pointerStack = new StackPointer;
	}

	void cleanup()
	{
		delete arrayStack;
		delete pointerStack;
	}

	void testPushInPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(!pointerStack->isEmpty(), "Stack is empty");
	}

	void testPushInArrayStack()
	{
		for(int i = 0; i < 5; i++)
			arrayStack->push(i);
		QVERIFY2(!arrayStack->isEmpty(), "Stack is empty");
	}

	/**
	 * Function "increaseStack" is called when the array is full
	 * and increases its size by half, so to test it enough to
	 * add to the Stack more elements than its initial size
	 */
	void testIncreaseArrayStack()
	{
		for(int i = 0; i < 20; i++)
			arrayStack->push(i);
	}

	void testTopPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->top() == 4, "Incorrect value");
	}

	void testTopArrayStack()
	{
		for(int i = 0; i < 5; i++)
			arrayStack->push(i);
		QVERIFY2(arrayStack->top() == 4, "Incorrect value");
	}

	void testPopFromPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->pop() == 4, "Incorrect value");
		QVERIFY2(pointerStack->pop() != 4, "Incorrect value");
	}

	void testPopFromArrayStack()
	{
		for(int i = 0; i < 5; i++)
			arrayStack->push(i);
		QVERIFY2(arrayStack->pop() == 4, "Incorrect value");
		QVERIFY2(arrayStack->pop() != 4, "Incorrect value");
	}

	void testFindValueInPointerStack()
	{
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->findPositionOfValue(4) == 1, "Incorrect position");
		QVERIFY2(pointerStack->findPositionOfValue(4) != 4, "Incorrect position");
	}

	void testFindValueInArrayStack()
	{
		for(int i = 0; i < 5; i++)
			arrayStack->push(i);
		QVERIFY2(arrayStack->findPositionOfValue(4) == 4, "Incorrect position");
		QVERIFY2(arrayStack->findPositionOfValue(4) != 1, "Incorrect position");
	}

	void testLengthOfPointerStack()
	{
		QVERIFY2(pointerStack->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			pointerStack->push(i);
		QVERIFY2(pointerStack->length() == 5, "Incorrect length");
	}

	void testLengthOfArrayStack()
	{
		QVERIFY2(arrayStack->length() == 0, "Incorrect length");
		for(int i = 0; i < 5; i++)
			arrayStack->push(i);
		QVERIFY2(arrayStack->length() == 5, "Incorrect length");
	}

	void testPointerStackIsEmpty()
	{
		QVERIFY2(pointerStack->isEmpty(), "Stack is not empty");
		pointerStack->push(8);
		QVERIFY2(!pointerStack->isEmpty(), "Stack is not empty");
	}

	void testArrayStackIsEmpty()
	{
		QVERIFY2(arrayStack->isEmpty(), "Stack is not empty");
		arrayStack->push(8);
		QVERIFY2(!arrayStack->isEmpty(), "Stack is not empty");
	}
};
