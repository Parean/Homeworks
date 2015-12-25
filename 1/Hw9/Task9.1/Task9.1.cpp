#include <stdio.h>
#include <iostream>
#include "hashTable.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *firstFile = fopen("text1.txt", "r");
	FILE *secondFile = fopen("text2.txt", "r");
	FILE *thirdFile = fopen("output.txt", "w");
	int hashSize = 50;
	int count = 0;
	int index = 0;
	List **hashTable = createHashTable(hashSize);
	bool isRebuilding = false;
	while (!feof(firstFile))
	{
		String *string = createString(firstFile);
		index = hashFunction(string, hashSize);
		addInList(string, hashTable[index], count, isRebuilding);
		if (count / hashSize >= 10)
			hashTable = increaseHashTable(hashSize, hashTable, count);
	}
	fprintf(thirdFile, "Строки, которыe содержатся в обоих файлах:\n");
	while (!feof(secondFile))
	{
		String *string = createString(secondFile);
		index = hashFunction(string, hashSize);
		if (findAndDeleteElement(hashTable[index], string))
			fprintf(thirdFile, "%s\n", string->symbols);
	}
	deleteHashTable(hashSize, isRebuilding, hashTable);
	fclose(firstFile);
	fclose(secondFile);
	fclose(thirdFile);
}