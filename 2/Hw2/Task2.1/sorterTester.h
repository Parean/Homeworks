#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bubbleSorter.h"
#include "quickSorter.h"
#include "insertionSorter.h"

class SorterTester : public QObject
{
	Q_OBJECT
public:
	explicit SorterTester(QObject *parent = 0) : QObject(parent) {}

private:
	int size;
	int *array;
	Sorter *bubbleSorter;
	Sorter *quickSorter;
	Sorter *insertionSorter;

private slots:
	void init()
	{
		size = 10;
		array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = rand() % 100;
		bubbleSorter = new BubbleSorter(array, size);
		quickSorter = new QuickSorter(array, size);
		insertionSorter = new InsertionSorter(array, size);
	}

	void cleanup()
	{
		delete array;
	}

	void testBubbleSort()
	{
		array = bubbleSorter->sort();
		bool isSorted = true;
		for (int i = 1; i < size; i++)
			if(array[i] < array[i - 1])
				isSorted = false;
		QVERIFY2(isSorted, "The array sorted incorrectly");
	}

	void testInsertionSort()
	{
		array = insertionSorter->sort();
		bool isSorted = true;
		for (int i = 1; i < size; i++)
			if(array[i] < array[i - 1])
				isSorted = false;
		QVERIFY2(isSorted, "The array sorted incorrectly");
	}

	void testQuickSort()
	{
		array = quickSorter->sort();
		bool isSorted = true;
		for (int i = 1; i < size; i++)
			if(array[i] < array[i - 1])
				isSorted = false;
		QVERIFY2(isSorted, "The array sorted incorrectly");
	}
};
