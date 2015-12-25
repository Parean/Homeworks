#include <stdio.h>
#include <iostream>
#include "Stack.h"
#include "Queue.h"

bool isPlusOrMinus(Stack *&storage)
{
	return (storage->head->next->value == '-' || storage->head->next->value == '+');
}

bool isAsteriskOrSlash(Stack *&storage)
{
	return (storage->head->next->value == '*' || storage->head->next->value == '/');
}

bool transformation(Stack *&storage, Queue *&outputQueue)
{
	setlocale(LC_CTYPE, "Russian");
	char token = '0';
	bool checkError = true;
	printf("Введите выражение\n");
	while (token != '\n')
	{
		scanf("%c", &token);
		if ((token >= '0') && (token <= '9'))
			addInQueue(token, outputQueue);
		if (token == '(')
			addInStack(token, storage);
		if (token == '*' || token == '/')
		{
			while (!stackIsEmpty(storage) && isAsteriskOrSlash(storage))
			{
				addInQueue(pop(storage), outputQueue);
			}
			if (stackIsEmpty(storage) || isPlusOrMinus(storage) || lookInStack(storage) == '(')
				addInStack(token, storage);
		}
		if (token == '+' || token == '-')
		{
			while (!stackIsEmpty(storage) && (isAsteriskOrSlash(storage) || isPlusOrMinus(storage)))
			{
				addInQueue(pop(storage), outputQueue);
			}
			if (stackIsEmpty(storage) || lookInStack(storage) == '(')
				addInStack(token, storage);
		}
		if (token == ')')
		{
			while (!stackIsEmpty(storage) && (isAsteriskOrSlash(storage) || isPlusOrMinus(storage)))
			{
				addInQueue(pop(storage), outputQueue);
			}
			if (stackIsEmpty(storage))
			{
				printf("\nОшибка ввода, не соблюдается баланс скобок\n\n");
				checkError = false;
				break;
			}
			if (lookInStack(storage) == '(')
			{
				pop(storage);
			}
		}
		if (token == '\n')
		{
			while (!stackIsEmpty(storage) && (isAsteriskOrSlash(storage) || isPlusOrMinus(storage)))
			{
				addInQueue(pop(storage), outputQueue);
			}
			if (!stackIsEmpty(storage) && lookInStack(storage) == '(')
			{
				printf("\nОшибка ввода, не соблюдается баланс скобок\n\n");
				checkError = false;
				break;
			}
		}
	}
	return checkError;
}