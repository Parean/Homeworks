#include"parser.h"

bool E1(FILE *&file);
bool T(FILE *&file);
bool T1(FILE *&file);
bool F(FILE *&file);

bool E(FILE *file)
{
	if (T(file))
		return E1(file);
	return false;
}

bool E1(FILE *&file)
{
	char symbol = 0;
	fscanf(file, "%c", &symbol);
	if (symbol == '-' || symbol == '+')
	{
		char space = 0;
		fscanf(file, "%c", &space);
		if (space == ' ' && T(file))
			return E1(file);
		else
			return false;
	}
	else
		ungetc(symbol, file);
	return true;
}

bool T(FILE *&file)
{
	if (F(file))
	{
		return T1(file);
	}
	else
		return false;
}

bool T1(FILE *&file)
{
	char symbol = 0;
	fscanf(file, "%c", &symbol);
	if (symbol == '/' || symbol == '*')
	{
		char space = 0;
		fscanf(file, "%c", &space);
		if (space == ' ' && F(file))
			return T1(file);
		else
			return false;
	}
	else
		ungetc(symbol, file);
	return true;
}

bool F(FILE *&file)
{
	return isNumber(file);
}