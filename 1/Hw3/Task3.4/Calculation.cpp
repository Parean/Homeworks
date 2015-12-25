#include "Stack.h"
#include "Queue.h"
#include <stdio.h>
#include <iostream>

void calculate(char token, Stack *storage)
{
	switch (token)
	{
	case '+':
	{
				storage->head->next->next->value = storage->head->next->next->value + storage->head->next->value;
				pop(storage);
				break;
	}
	case '-':
	{
				storage->head->next->next->value = storage->head->next->next->value - storage->head->next->value;
				pop(storage);
				break;
	}
	case '*':
	{
				storage->head->next->next->value = storage->head->next->next->value * storage->head->next->value;
				pop(storage);
				break;
	}
	case '/':
	{
				storage->head->next->next->value = storage->head->next->next->value / storage->head->next->value;
				pop(storage);
				break;
	}
	}
}

void calculation(Stack *&storage, Queue *&outputQueue)
{
	setlocale(LC_CTYPE, "Russian");
	char token = '\0';
	while (!queueIsEmpty(outputQueue))
	{
		token = outputQueue->first->next->value;
		if (token >= '0' && token <= '9')
		{
			int number = token - '0';
			addInStack(number, storage);
		}
		else if (token != '\n')
			calculate(token, storage);
		getOutOfQueue(outputQueue);
	}
	printf("\nЗначение выражения равно %d, c точностью до округления\n\n", lookInStack(storage));
}