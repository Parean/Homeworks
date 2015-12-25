#include "lexer.h"

enum
{
	start,
	firstSign,
	secondSign,
	integerPart,
	fractionalPart,
	point,
	degree,
	order
};

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isNumber(FILE *&file)
{
	int state = start;
	char symbol = 0;
	fscanf(file, "%c", &symbol);
	while (symbol != ' ' && symbol != '\n' && !feof(file))
	{
		switch (state)
		{
		case start:
		{
			if (symbol == '+' || symbol == '-')
				state = firstSign;
			else if (isDigit(symbol))
				state = integerPart;
			else
				return false;
			break;
		}
		case firstSign:
		{
			if (isDigit(symbol))
				state = integerPart;
			else
				return false;
			break;
		}
		case integerPart:
		{
			if (isDigit(symbol))
				break;
			else if (symbol == '.')
				state = point;
			else if (symbol == 'E' || symbol == 'e')
				state = order;
			else
				return false;
			break;
		}
		case point:
		{
			if (isDigit(symbol))
				state = fractionalPart;
			else
				return false;
			break;
		}
		case fractionalPart:
		{
			if (isDigit(symbol))
				break;
			else if (symbol == 'E' || symbol == 'e')
				state = order;
			else
				return false;
			break;
		}
		case order:
		{
			if (symbol == '+' || symbol == '-')
				state = secondSign;
			else if (isDigit(symbol))
				state = degree;
			else
				return false;
			break;
		}
		case secondSign:
		{
			if (isDigit(symbol))
				state = degree;
			else
				return false;
			break;
		}
		case degree:
		{
			if (isDigit(symbol))
				break;
			else
				return false;
			break;
		}
		}
		fscanf(file, "%c", &symbol);
	}
	return state == integerPart || state == fractionalPart || state == degree;
}