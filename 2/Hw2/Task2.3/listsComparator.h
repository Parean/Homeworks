#pragma once
#include "listPointer.h"

/**
 * @class ListsComparator
 * Class to compare two lists by size
 */
class ListsComparator
{
public:

	/**
	 * @return 1 if first list bigger than second
	 * -1 if second list bigger than first
	 * 0 if lists are equal
	 */
	static int compare(ListPointer *firstList, ListPointer *secondList);
};
