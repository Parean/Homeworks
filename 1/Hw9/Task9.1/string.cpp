#include "string.h"
#include <stdio.h>

void fillTheString(String *string, FILE *file);

String *createEmptyString(int size)
{
	String *string = new String;
	string->size = size;
	string->symbols = new char[string->size];
	for (int i = 0; i < size; i++)
	{
		string->symbols[i] = '\0';
	}
	return string;
}

String *createString(FILE *file)
{
	String *string = createEmptyString(100);
	fillTheString(string, file);
	return string;
}

void fillTheString(String *string, FILE *file)
{
	char symbol = 0;
	int i = 0;
	while (!feof(file))
	{		
		fscanf(file, "%c", &symbol);
		if (symbol == '\n' || feof(file))
			break;
		string->symbols[i] = symbol;
		i++;
		if (i == string->size - 1)
		{
			String *newString = createEmptyString(string->size * 2);
			for (int j = 0; j <= i; j++)
			{
				newString->symbols[j] = string->symbols[j];
			}
			delete[] string->symbols;
			string = newString;
		}
	}
	string->symbols[i] = '\0';
}

String *concatenation(String *string, String *argument)
{
	int i = 0;
	while (string->symbols[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (argument->symbols[j] != '\0')
	{
		if (i == string->size - 1)
		{
			String *newString = createEmptyString(string->size * 2);
			for (int j = 0; j <= i; j++)
			{
				newString->symbols[j] = string->symbols[j];
			}
			delete[] string->symbols;
			string = newString;
		}
		string->symbols[i] = argument->symbols[j];
		j++;
		i++;
	}
	string->symbols[i] = '\0';
	return string;
}

Comparison comparisonOfStrings(String *firstString, String *secondString)
{
	if (returnLength(firstString) < returnLength(secondString))
		return smaller;
	if (returnLength(firstString) > returnLength(secondString))
		return bigger;
	int i = 0;
	while (firstString->symbols[i] != '\0')
	{
		if (firstString->symbols[i] < secondString->symbols[i])
			return smaller;
		if (firstString->symbols[i] > secondString->symbols[i])
			return bigger;
		i++;
	}
	return equivalent;
}

String *returnSubstring(String *string, int position, int length)
{
	String *substring = createEmptyString(100);
	int j = 0;
	int i = 0;
	for (i = position; (i < position + length && string->symbols[i] != '\0'); i++)
	{
		substring->symbols[j] = string->symbols[i];
		if (j == substring->size - 1)
		{
			String *newString = createEmptyString(substring->size * 2);
			for (int k = 0; k <= j; k++)
			{
				newString->symbols[k] = substring->symbols[k];
			}
			delete[] substring->symbols;
			substring = newString;
		}
		j++;
	}
	if (i < position + length)
		return nullptr;
	substring->symbols[j] = '\0';
	return substring;
}

char *stringToChar(String *string)
{
	int size = returnLength(string);
	char *stringInChar = new char[size];
	for (int i = 0; i < size; i++)
	{
		stringInChar[i] = string->symbols[i];
	}
	return stringInChar;
}

String *clone(String *string)
{
	String *newString = createEmptyString(string->size);
	int i = 0;
	while (string->symbols[i] != '\0')
	{
		newString->symbols[i] = string->symbols[i];
		i++;
	}
	newString->symbols[i] = '\0';
	return newString;
}

int returnLength(String *string)
{
	int i = 0;
	while (string->symbols[i] != '\0')
		i++;
	return i+1;
}

void deleteString(String *string)
{
	delete[] string->symbols;
	delete string;
}

bool stringIsEmpty(String *string)
{
	return string->symbols[0] == '\0';
}

