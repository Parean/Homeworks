#include "calculator.h"
#include "translator.h"

#include <stdlib.h>
#include <iostream>

Calculator::Calculator(char *string)
{
    stack = new StackPointer;
    Translator *translator = new Translator(string);
	currentSymbol = expression = translator->translation();
	delete translator;
	storage = new char[30];
}

void Calculator::read()
{
	for (int i = 0; i < 30; i++)
		storage[i] = 0;
	int count = 0;
	while (*currentSymbol != ' ' && *currentSymbol != '\0')
		storage[count++] = *currentSymbol++;
	if (*currentSymbol == ' ')
		currentSymbol++;
}

float Calculator::calculation()
{
	
	while (*currentSymbol != '\0')
	{
        read();
		switch (*storage)
		{
		case '+':
		{
					float firstValue = stack->pop();
					float secondValue = stack->pop();
					stack->push(firstValue + secondValue);
					break;
		}
		case '-':
		{
					float firstValue = stack->pop();
					float secondValue = stack->pop();
					stack->push(secondValue - firstValue);
					break;
		}
		case '*':
		{
					float firstValue = stack->pop();
					float secondValue = stack->pop();
					stack->push(firstValue * secondValue);
					break;
		}
		case '/':
		{
					float firstValue = stack->pop();
					float secondValue = stack->pop();
					stack->push(secondValue / firstValue);
					break;
		}
		default:
                    stack->push(atof(storage));
		}
	}
	return stack->pop();
}

Calculator::~Calculator()
{
	delete[] expression;
	delete[] storage;
	delete stack;
}
