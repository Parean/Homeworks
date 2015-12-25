#include <stdio.h>
#include <iostream>
#include "hashTable.h"

void main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = nullptr;
	if ((file = fopen("text.txt", "r")) == NULL)
		return;
	int hashSize = 50;
	int count = 0;
	int index = 0;
	List **hashTable = createHashTable(hashSize);
	bool isRebuilding = false;
	while (!feof(file))
	{
		String *string = createString(file);
		index = hashFunction(string, hashSize);
		addInList(string, hashTable[index], count, isRebuilding, 0);
		if (count / hashSize >= 10)
			hashTable = increaseHashTable(hashSize, hashTable, count);
	}
	int length = 0;
	int maxLength = 0;
	int indexOfMaxLength = 0;
	int emptyCells = 0;
	printf("���������� ������������� ����:\n");
	for (int i = 0; i < hashSize; i++)
	{
		printf("i%d ", i);
		printList(hashTable[i]);
		length = lengthOfList(hashTable[i]);
		if (maxLength < length)
		{
			maxLength = length;
			indexOfMaxLength = i;
		}
		if (listIsEmpty(hashTable[i]))
			emptyCells++;
	}
	printf("\nload factor: %d \n\n", count / hashSize);
	printf("������� ����� �������: %d\n\n", count / (hashSize - emptyCells));
	printf("������������ ����� �������: %d\n�������� ������� � ��� ������:\n", maxLength);
	printList(hashTable[indexOfMaxLength]);
	printf("\n����� ����� ����������� ����: %d\n\n", count);
	printf("����� ������ ����� �������: %d\n\n", emptyCells);
	deleteHashTable(hashSize, isRebuilding, hashTable);
}