#pragma once
#include "stackArray.h"
#include "stackPointer.h"

class Calculator
{
public:
    Calculator(kindOfStack kind, char *string);
	float calculation();
	~Calculator();
private:
	Stack *stack;
	void reader();
	char *storage;
	char *expression;
	char *currentSymbol;
};

