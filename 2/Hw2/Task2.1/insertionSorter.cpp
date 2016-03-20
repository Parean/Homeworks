#include "insertionSorter.h"

InsertionSorter::InsertionSorter(int *value, int size) : Sorter(value, size) {}

int *InsertionSorter::sort()
{
	int temp = 0;
	for (int i = 1; i < sizeOfArray; i++)
	{
		temp = symbols[i];
		int j = i - 1;
		while (j >= 0 && symbols[j] > temp)
			symbols[j + 1] = symbols[j--];
		symbols[j + 1] = temp;
	}
	return symbols;
}


