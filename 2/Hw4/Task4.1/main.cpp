#include <stdio.h>

#include "hashTable.h"

enum
{
	stop,
	add,
	check,
	del,
	statistic,
	switchFunction
};

int main()
{
	HashTable *hashTable = new HashTable(50);
	int state = -1;
	int wordSize = 25;
	char *string = new char[wordSize];
	printf("This program tests the hash table functions\n\nMenu:\n\n"
		   " 0 - Exit\n"
		   " 1 - Add new element\n"
		   " 2 - Check presence of element\n"
		   " 3 - Remove element from table\n"
		   " 4 - Show statistics\n"
		   " 5 - Switch hash function\n");
	while(state)
	{
		printf("\nEnter the number\n");
		scanf("%d", &state);
		switch(state)
		{
		case add:
		{
			printf("\nEnter the value\n");
			scanf("%s", string);
			hashTable->addInTable(string);
			break;
		}
		case check:
		{
			printf("\nEnter the value\n");
			scanf("%s", string);
			if (hashTable->isPlaced(string))
				printf("\nElement is placed\n");
			else
				printf("\nElement is not placed\n");
			break;
		}
		case del:
		{
			printf("\nEnter the value\n");
			scanf("%s", string);
			hashTable->removeFromTable(string);
			break;
		}
		case statistic:
		{
			hashTable->getStatistic();
			break;
		}
		case switchFunction:
			printf("\nSelect the function:\n"
				   " 0 - FAQ6\n 1 - Ly\n 2 - Rot13\n");
			KindOfFunction value;
			scanf("%d", &value);
			hashTable->switchHashFunction(value);
		}
	}
	delete hashTable;
}
