#include <stdio.h>
#include <iostream>
#include "List.h"

int main()
{
	List *sortedList = createList();
	setlocale(LC_CTYPE, "Russian");
	printf("Список операций: \n 0 - Exit; \n 1 - Add a value to sorted list;\n");
	printf(" 2 - Remove a value from sorted list; \n 3 - Print list. \n");
	char digit = '4';
	char value[20] = "0";
	while (digit != '0')
	{
		printf("\nВыберите операцию и введите цифру\n");
		scanf("%c", &digit);
		if (digit == '1')
		{
			printf("\nВведите значение\n");
			scanf("%s", &value);
			addInList(value, sortedList);
		}
		if (digit == '2')
		{
			printf("\nВведите значение\n");
			scanf("%s", &value);
			removeAValue(sortedList, value);
		}
		if (digit == '3')
		{
			printf("\nОтсортированный лист: ");
			printList(sortedList);
		}
		if (digit != '0' && digit != '1' && digit != '2' && digit != '3')
		{
			printf("\nОшибка ввода\n");
			break;
		}
		if (digit != '0')
			scanf("%c", &digit);
	}
	printf("\nВы закончили\n\n");
	deleteList(sortedList);
}