#include <stdio.h>
#include <iostream>
#include "list.h"

int main()
{
	List *list = createList();
	setlocale(LC_CTYPE, "Russian");
	printf("������� ���������� ������\n");
	int number = 0;
	scanf("%d", &number);
	for (int i = number; i > 1; i--)
		addInList(i, list);
	printf("������� ������������� �������\n");
	int numberOfKilled = 0;
	scanf("%d", &numberOfKilled);
	if (numberOfKilled == 1)
		printf("����� ��������� � %d\n\n", number);
	else
	{
		for (int j = 0; j < number - 1; j++)
		{
			for (int i = 1; i < numberOfKilled - 1; i++)
				shift(list);
			getOutOfList(list);
			shift(list);
		}
		printf("����� ��������� � %d\n\n", lookInList(list));
	}
	deleteList(list);
}