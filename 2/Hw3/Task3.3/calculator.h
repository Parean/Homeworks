#pragma once

#include "stackPointer.h"

/**
 * @class Calculator
 * Class to count arithmetic expressions
 * It supports real operands
 */
class Calculator
{
public:
	Calculator(char *string);

	/// @return expression value
	float calculation();
	~Calculator();

private:
	StackPointer *stack;
	char *storage;
	char *expression;
	char *currentSymbol;

	void read();
};
