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
	Calculator *calculator;

private slots:
	void init()
	{
		calculator = new Calculator(array, "5*5*(34+(234/3)*345/(16-7))\0");
	}

	void cleanup()
	{
		delete calculator;
	}

	void testCalculation()
	{
		QVERIFY2(calculator->calculation() == 75600, "Incorrect result");
	}
};
