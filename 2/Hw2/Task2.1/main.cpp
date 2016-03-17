#include "bubbleSorter.h"
#include "insertionSorter.h"
#include "quickSorter.h"
#include "sorterTester.h"

#include <stdio.h>
#include <stdlib.h>

void testOfSorter()
{
	SorterTester sorterTester;
	QTest::qExec(&sorterTester);
}

int main()
{
	testOfSorter();
	int size = 10;
	int *array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
	printf("\n\n\nThe initial array:\n\n");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	int kind = 0;
	Sorter *sorter = nullptr;
	printf("\n\nEnter:\n\n 0 - to use BubbleSorter\n"
		   " 1 - to use InsertionSorter\n 2 - to use QuickSorter\n\n");
	scanf("%d", &kind);
	switch(kind)
	{
	case bubble:
		sorter = new BubbleSorter(array, size);
		break;
	case insertion:
		sorter = new InsertionSorter(array, size);
		break;
	case quick:
		sorter = new QuickSorter(array,size);
	}
	array = sorter->sort();
	printf("\n\nThe sorted array:\n\n");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	delete[] array;
}
