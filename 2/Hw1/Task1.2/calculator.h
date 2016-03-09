#pragma once
#include "stackArray.h"
#include "stackPointer.h"

/**
 * @class Calculator
 * Class to count arithmetic expressions
 * It supports integer operands
 */
class Calculator
{
public:
    Calculator(KindOfStack kind, char *string);


    /// @return expression value
    float calculation();
	~Calculator();
private:
	Stack *stack;
	char *storage;
	char *expression;
	char *currentSymbol;

    void read();
};

