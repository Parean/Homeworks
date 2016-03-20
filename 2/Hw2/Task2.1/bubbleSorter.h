#pragma once
#include "sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter(int *value, int size);
	int *sort();
};

