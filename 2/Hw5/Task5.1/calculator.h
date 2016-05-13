#pragma once

#include "operator.h"
#include "operand.h"

/**
 * @class Calculator
 * Class for calculating arithmetic expressions in the parse tree
 */
class Calculator
{
public:
	Calculator(char *string);
	~Calculator();

	int calculate();

private:
	Operator *root;
};

