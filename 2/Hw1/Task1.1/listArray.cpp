#include "listArray.h"

ListArray::ListArray()
{
	sizeOfList = 50;
	numberOfElements = 0;
	listArray = new int[sizeOfList];
}

void ListArray::addValue(int value)
{
	listArray[numberOfElements] = value;
	if (++numberOfElements == sizeOfList)
		increaseList();
}

int ListArray::findPositionOfValue(int value) const
{
	for (int index = 0; index < numberOfElements; index++)
	{
		if (listArray[index] == value)
			return index;
	}
	return -1;
}

bool ListArray::removeValue(int value)
{
	int indexOfElement = findPositionOfValue(value);
	if (indexOfElement == -1)
		return false;
	numberOfElements--;
	for (int i = indexOfElement; i < numberOfElements; i++)
		listArray[i] = listArray[i + 1];
	return true;
}

int ListArray::length() const
{
	return numberOfElements;
}

bool ListArray::isEmpty() const
{
	return numberOfElements == 0;
}

void ListArray::increaseList()
{
	sizeOfList = sizeOfList * 2;
	int *newListArray = new int[sizeOfList];
	for (int i = 0; i < numberOfElements; i++)
		newListArray[i] = listArray[i];
	delete[] listArray;
	listArray = newListArray;
}

ListArray::~ListArray()
{
	delete[] listArray;
}
