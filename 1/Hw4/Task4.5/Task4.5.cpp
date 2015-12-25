#include <stdio.h>
#include <iostream>
#include "list.h"

int main()
{
	List *list = createList();
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите количество воинов\n");
	int number = 0;
	scanf("%d", &number);
	for (int i = number; i > 1; i--)
		addInList(i, list);
	printf("¬ведите периодичность убийств\n");
	int numberOfKilled = 0;
	scanf("%d", &numberOfKilled);
	if (numberOfKilled == 1)
		printf("Ќомер выжившего Ч %d\n\n", number);
	else
	{
		for (int j = 0; j < number - 1; j++)
		{
			for (int i = 1; i < numberOfKilled - 1; i++)
				shift(list);
			getOutOfList(list);
			shift(list);
		}
		printf("Ќомер выжившего Ч %d\n\n", lookInList(list));
	}
	deleteList(list);
}