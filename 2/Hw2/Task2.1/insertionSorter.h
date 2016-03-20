#pragma once
#include "sorter.h"

class InsertionSorter :	public Sorter
{
public:
	InsertionSorter(int *value, int size);
	int *sort();
};

