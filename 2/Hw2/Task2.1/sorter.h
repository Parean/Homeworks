#pragma once

#include <iostream>

enum KindOfSorter
{
	bubble,
	insertion,
	quick
};

/**
 * @class Sorter
 * Virtual class from which inherit other
 * classes that perform sorting of array
 */
class Sorter
{
public:

	/**
	 * Constructor is passed an existing array,
	 * the new array in the class wouldn't start,
	 * so he has no destructor
	 */
	Sorter(int *value, int size);

	/**
	 * @return Sorted array
	 */
	int virtual *sort() = 0;

protected:
	int *symbols;
	int sizeOfArray;
};

