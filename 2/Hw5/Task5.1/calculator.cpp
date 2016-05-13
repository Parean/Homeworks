#include "calculator.h"

Calculator::Calculator(char *string)
{
	root = new Operator(string);
}

Calculator::calculate()
{
	return root->calculate();
}

Calculator::~Calculator()
{
	delete root;
}
