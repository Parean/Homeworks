#include <stdio.h>

#include "stackArray.h"
#include "stackPointer.h"
#include "translator.h"
#include "calculator.h"
#include "stackTester.h"
#include "translatorTester.h"
#include "calculatorTester.h"

void testOfComponents()
{
	StackTester stackTester;
	QTest::qExec(&stackTester);
	TranslatorTester translatorTester;
	QTest::qExec(&translatorTester);
	CalculatorTester calculatorTester;
	QTest::qExec(&calculatorTester);
}

int main()
{
	testOfComponents();
	printf("\n\n\nEnter the expression\n\n");
	int size = 300;
	char *expression = new char[size];
	gets(expression);
	int kind = 0;
	printf("\nEnter\n  0 - to use the stackArray\n"
		   "  1 - to use the stackPointer\n\n");
	scanf("%d", &kind);
	Calculator *calculator = nullptr;
	switch(kind)
	{
	case array:
	{
		calculator = new Calculator(array, expression);
		break;
	}
	case pointer:
		calculator = new Calculator(pointer, expression);
	}
	printf("\n\nResult: %.3f", calculator->calculation());
	delete calculator;
}
