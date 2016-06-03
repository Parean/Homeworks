#include "operand.h"

Operand::Operand(char *&string)
{
	while(*string != ' ' && *string != ')')
		value = value * 10 + (*string++ - '0');
}

void Operand::print() const
{
	cout << value;
}

int Operand::calculate() const
{
	return value;
}
