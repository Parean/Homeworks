#include "bubbleSorter.h"

BubbleSorter::BubbleSorter(int *value, int size) : Sorter(value, size) {}

int *BubbleSorter::sort()
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 0; j < sizeOfArray - i - 1; j++)
		{
			if (symbols[j] > symbols[j + 1])
				std::swap(symbols[j], symbols[j + 1]);
		}
	}
	return symbols;
}

