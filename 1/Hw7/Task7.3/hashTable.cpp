#include "hashTable.h"

int hashFunction(String *value, int hashSize)
{
	int result = 0;
	for (int i = 0; value->symbols[i] != '\0'; i++)
		result = (result + value->symbols[i]) % hashSize;
	return result;
}

List **createHashTable(int hashSize)
{
	List **hashTable = new List*[hashSize];
	for (int i = 0; i < hashSize; i++)
	{
		hashTable[i] = createList();
	}
	return hashTable;
}

void rebuilging(List *list, List **newHashTable, int hashSize, int count, bool isRebuilding)
{
	ListElement *temp = list->first->next;
	int index = 0;
	while (temp != nullptr)
	{
		index = hashFunction(temp->value, hashSize);
		addInList(temp->value, newHashTable[index], count, isRebuilding, temp->countOfWords);
		temp = temp->next;
	}
}

void deleteHashTable(int hashSize, bool isRebuilding, List **hashTable)
{
	for (int i = 0; i < hashSize; i++)
		deleteList(isRebuilding, hashTable[i]);
	delete[] hashTable;
}

List **increaseHashTable(int &hashSize, List **hashTable, int count)
{
	bool isRebuilding = true;
	hashSize = hashSize * 2;
	List **newHashTable = createHashTable(hashSize);
	for (int i = 0; i < hashSize / 2; i++)
	{
		rebuilging(hashTable[i], newHashTable, hashSize, count, isRebuilding);
		deleteList(isRebuilding, hashTable[i]);
	}
	return newHashTable;
}