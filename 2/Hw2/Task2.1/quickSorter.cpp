#include "quickSorter.h"

QuickSorter::QuickSorter(int *value, int size) : Sorter(value, size) {}

int *QuickSorter::sort()
{
	qsort(0, sizeOfArray-1);
	return symbols;
}

void QuickSorter::qsort(int begin, int end)
{
	int supportElement = symbols[(begin + end) / 2];
	int i = begin;
	int j = end;
	while (i <= j)
	{
		while (symbols[i] < supportElement)
			i++;
		while (symbols[j] > supportElement)
			j--;
		if (i <= j)
		{
			std::swap(symbols[i], symbols[j]);
			i++;
			j--;
		}
	}
	if (i < end)
		qsort(i, end);
	if (j > begin)
		qsort(begin, j);
}


