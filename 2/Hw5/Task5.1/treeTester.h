#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "operator.h"

class TreeTester : public QObject
{
	Q_OBJECT
public:
	explicit TreeTester(QObject *parent = 0) : QObject(parent) {}

private:
	TreeNode *expression;
	char *string;

private slots:
	void init()
	{
		string = "(* (+ 1 1) (/ (- 9 3) 2)";
		expression = new Operator(string);
	}

	void cleanup()
	{
		delete expression;
	}

	void testCalculation()
	{
		QVERIFY2(expression->calculate() == 6, "Incorrect result");
	}
};
