#include "operand.h"

Operand::Operand(char *&string)
{
	value = *string++ - '0';
}

void Operand::print() const
{
	cout << value;
}

int Operand::calculate() const
{
	return value;
}
