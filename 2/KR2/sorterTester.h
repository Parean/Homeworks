#pragma once

#include <stdlib.h>
#include <ctime>
#include <QtCore/QObject>
#include <QtTest/QTest>

#include "bubbleSorter.h"

class SorterTester : public QObject
{
	Q_OBJECT
public:
	explicit SorterTester(QObject *parent = 0) : QObject(parent) {}

private:
	QList<int> list;
	QList<int> sortedList;
	int sizeOfList = 20;

private slots:

	void sortListWithEqualValues()
	{
		for (int i = 0; i < sizeOfList; i++)
			list.append(0);

		sortedList = BubbleSorter<int>::sort(list);
		QVERIFY2(list == sortedList, "Sort changes already sorted list");
	}

	void sortAreadySortedList()
	{
		for (int i = 0; i < sizeOfList; i++)
			list.append(i);

		sortedList = BubbleSorter<int>::sort(list);
		QVERIFY2(list == sortedList, "Sort changes already sorted list");
	}

	/**
	 * @brief simpleTestSort
	 * This test verifies the operation of the sort on
	 * list with only two values
	 */
	void simpleTestingSort()
	{
		for (int i = 0; i < sizeOfList; i++)
			list.append(rand() % 2);

		sortedList = BubbleSorter<int>::sort(list);
		for (int i = 1; i < sizeOfList; i++)
			if (sortedList.at(i) < sortedList.at(i - 1))
				QVERIFY2(false, "Sort works incorrectly");
	}

	/**
	 * @brief hardTestSort
	 * This test verifies the operation of the sort on 500 different
	 * lists with different length
	 */
	void hardTestingSort()
	{
		srand(time(nullptr));

		for (int k = 0; k < 500; k++)
		{
			sizeOfList = rand() % 1000 + 1;

			for (int i = 0; i < sizeOfList; i++)
				list.append(rand() % 1000);

			sortedList = BubbleSorter<int>::sort(list);
			for (int i = 1; i < sizeOfList; i++)
				if (sortedList.at(i) < sortedList.at(i - 1))
					QVERIFY2(false, "Sort works incorrectly");

			list.clear();
			sortedList.clear();
		}
	}
};
