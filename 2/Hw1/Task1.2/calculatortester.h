#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "calculator.h"

class CalculatorTester : public QObject
{
	Q_OBJECT
public:
	explicit CalculatorTester(QObject *parent = 0) : QObject(parent) {}

private:
	Calculator *calculator = nullptr;

private slots:

	void cleanup()
	{
		delete calculator;
	}


	void testOfNumber()
	{
		calculator = new Calculator(array, "7\0");
		QVERIFY2(calculator->calculation() == 7, "Incorrect result");
	}

	void testOfAddition()
	{
		calculator = new Calculator(array, "6+5\0");
		QVERIFY2(calculator->calculation() == 11, "Incorrect result");
	}

	void testOfSubtraction()
	{
		calculator = new Calculator(array, "6-5\0");
		QVERIFY2(calculator->calculation() == 1, "Incorrect result");
	}

	void testOfMultiply()
	{
		calculator = new Calculator(array, "6*5\0");
		QVERIFY2(calculator->calculation() == 30, "Incorrect result");
	}

	void testOfDivision()
	{
		calculator = new Calculator(array, "30/6\0");
		QVERIFY2(calculator->calculation() == 5, "Incorrect result");
	}

	void testOfSimpleExpression()
	{
		calculator = new Calculator(array, "4*18-6/2+7\0");
		QVERIFY2(calculator->calculation() == 76, "Incorrect result");
	}

	void testOfExpressionWithBrackets()
	{
		calculator = new Calculator(array, "5*5*(34+(234/3)*345/(16-7))\0");
		QVERIFY2(calculator->calculation() == 75600, "Incorrect result");
	}
};
