#include <stdio.h>
#include <iostream>
#include "List.h"

int main()
{
	List *sortedList = createList();
	setlocale(LC_CTYPE, "Russian");
	printf("������ ��������: \n 0 - Exit; \n 1 - Add a value to sorted list;\n");
	printf(" 2 - Remove a value from sorted list; \n 3 - Print list. \n");
	char digit = '4';
	char value[20] = "0";
	while (digit != '0')
	{
		printf("\n�������� �������� � ������� �����\n");
		scanf("%c", &digit);
		if (digit == '1')
		{
			printf("\n������� ��������\n");
			scanf("%s", &value);
			addInList(value, sortedList);
		}
		if (digit == '2')
		{
			printf("\n������� ��������\n");
			scanf("%s", &value);
			removeAValue(sortedList, value);
		}
		if (digit == '3')
		{
			printf("\n��������������� ����: ");
			printList(sortedList);
		}
		if (digit != '0' && digit != '1' && digit != '2' && digit != '3')
		{
			printf("\n������ �����\n");
			break;
		}
		if (digit != '0')
			scanf("%c", &digit);
	}
	printf("\n�� ���������\n\n");
	deleteList(sortedList);
}