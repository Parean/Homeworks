#include <stdio.h>
#include <iostream>
#include "Stack.h"
#include "Queue.h"

bool isPlusOrMinus(Stack *&storage)
{
	return (lookInStack(storage) == '-' || lookInStack(storage) == '+');
}

bool isAsteriskOrSlash(Stack *&storage)
{
	return (lookInStack(storage) == '*' || lookInStack(storage) == '/');
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Stack *storage = createStack();
	Queue *outputQueue = createQueue();
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
	if (checkError)
	{
		printf("\nВыражение в постфиксной записи — \n");
		while (!queueIsEmpty(outputQueue))
		{
			printf("%c", getOutOfQueue(outputQueue));
		}
		printf("\n\n");
	}
	deleteQueue(outputQueue);
	deleteStack(storage);
}