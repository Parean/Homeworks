#pragma once

#include "sorter.h"

class QuickSorter: public Sorter
{
public:
	QuickSorter(int *value, int size);
	int *sort();

private:

	/**
	 * Since the algorithm is recursive,
	 * for writing of class required additional function qsort,
	 * in which it is implemented
	 */
	void qsort(int begin, int end);
};

