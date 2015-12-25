#include <stdio.h>
#include <iostream>
#include "stack.h"


void calculate(char token, Stack *storage, bool &checkError)
{
	if (!isEmpty(storage))
	{
		int firstValue = 0;
		int secondValue = 0;
		switch (token)
		{
		case '+':
		{			
					firstValue = lookInStack(storage);
					pop(storage);
					secondValue = lookInStack(storage);
					pop(storage);
					addInStack(firstValue + secondValue, storage);
					break;
		}
		case '-':
		{
					firstValue = lookInStack(storage);
					pop(storage);
					secondValue = lookInStack(storage);
					pop(storage);
					addInStack(firstValue - secondValue, storage);
					break;
		}
		case '*':
		{
					firstValue = lookInStack(storage);
					pop(storage);
					secondValue = lookInStack(storage);
					pop(storage);
					addInStack(firstValue * secondValue, storage);
					break;
		}
		case '/':
		{
					firstValue = lookInStack(storage);
					pop(storage);
					secondValue = lookInStack(storage);
					pop(storage);
					addInStack(firstValue / secondValue, storage);
					break;
		}
		}
	}
	else
	{
		printf("\nОшибка во введенном выражении\n\n");
		checkError = false;
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите выражение в постфиксной записи\n");
	Stack *storage = createStack();
	char token = '\0';
	bool checkError = true;
	while (token != '\n')
	{
		scanf("%c", &token);
		if (token >= '0' && token <= '9')
		{
			int number = token - '0';
			addInStack(number, storage);
		}
		else if (token != '\n')
			calculate(token, storage, checkError);
	}
	if (!isEmpty)
	{
		printf("\nОшибка во введенном выражении\n\n");
		checkError = false;
	}
	if (checkError)
		printf("\nЗначение выражения равно %d\n\n", lookInStack(storage));
	deleteStack(storage);
}