#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "calculator.h"

class TreeTester : public QObject
{
	Q_OBJECT
public:
	explicit TreeTester(QObject *parent = 0) : QObject(parent) {}

private:
	Calculator *expression;
	char *string;

private slots:

	void cleanup()
	{
		delete expression;
	}

	void testOfAddition()
	{
		string = "(+ 1 1)";
		expression = new Calculator(string);
		QVERIFY2(expression->calculate() == 2, "Incorrect result");
	}

	void testOfSubtraction()
	{
		string = "(- 1 1)";
		expression = new Calculator(string);
		QVERIFY2(expression->calculate() == 0, "Incorrect result");
	}

	void testOfMultiply()
	{
		string = "(* 7 5)";
		expression = new Calculator(string);
		QVERIFY2(expression->calculate() == 35, "Incorrect result");
	}

	void testOfDivision()
	{
		string = "(/ 35 5)";
		expression = new Calculator(string);
		QVERIFY2(expression->calculate() == 7, "Incorrect result");
	}

	void testOfExpression()
	{
		string = "(* (+ 1 1) (/ (- 9 3) 2)";
		expression = new Calculator(string);
		QVERIFY2(expression->calculate() == 6, "Incorrect result");
	}
};
