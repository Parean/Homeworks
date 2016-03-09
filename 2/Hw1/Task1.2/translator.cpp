#include "translator.h"
#include <iostream>

Translator::Translator(KindOfStack kind, char *string)
{
	switch (kind)
	{
	case array:
		stack = new StackArray;
		break;
	case pointer:
		stack = new StackPointer;
		break;
	}
	inputString = string;
}

bool Translator::isPlusOrMinus() const
{
	
	return (stack->top() == '-' || stack->top() == '+');
}

bool Translator::isAsteriskOrSlash() const
{
	return (stack->top() == '*' || stack->top() == '/');
}

char *Translator::translation()
{
	bool checkError = true;
	char *outputString = new char[300];
	int numberOfSymbols = 0;
	while (*inputString != '\0')
	{
		if (isdigit(*inputString))
		{
			while (isdigit(*inputString))
				outputString[numberOfSymbols++] = *inputString++;
			outputString[numberOfSymbols++] = ' ';
		}
		if (*inputString == '(')
			stack->push(*inputString);
		if (*inputString == '*' || *inputString == '/')
		{
			while (!stack->isEmpty() && isAsteriskOrSlash())
			{
				outputString[numberOfSymbols++] = stack->pop();
				outputString[numberOfSymbols++] = ' ';
			}
			if (stack->isEmpty() || isPlusOrMinus() || stack->top() == '(')
				stack->push(*inputString);
		}
		if (*inputString == '+' || *inputString == '-')
		{
			while (!stack->isEmpty() && (isAsteriskOrSlash() || isPlusOrMinus()))
			{
				outputString[numberOfSymbols++] = stack->pop();
				outputString[numberOfSymbols++] = ' ';
			}
			if (stack->isEmpty() || stack->top() == '(')
				stack->push(*inputString);
		}
		if (*inputString == ')')
		{
			while (!stack->isEmpty() && (isAsteriskOrSlash() || isPlusOrMinus()))
			{
				outputString[numberOfSymbols++] = stack->pop();
				outputString[numberOfSymbols++] = ' ';
			}
			if (stack->isEmpty())
			{
				checkError = false;
				break;
			}
			if (stack->top() == '(')
			{
				stack->pop();
			}
		}
		inputString++;
	}
	while (!stack->isEmpty() && (isAsteriskOrSlash() || isPlusOrMinus()))
	{
		outputString[numberOfSymbols++] = stack->pop();
		outputString[numberOfSymbols++] = ' ';
	}
	outputString[numberOfSymbols++] = '\0';
		if (!stack->isEmpty() && stack->top() == '(')
		checkError = false;
	if (checkError)
		return outputString;
	else
		return 0;
}

Translator::~Translator()
{
	delete stack;
}
