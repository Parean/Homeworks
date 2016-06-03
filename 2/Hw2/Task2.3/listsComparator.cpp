#include "listsComparator.h"

int ListsComparator::compare(ListPointer *firstList, ListPointer *secondList)
{
	int firstLength = firstList->length();
	int secondLength = secondList->length();
	if (firstLength > secondLength)
		return 1;
	if (firstLength < secondLength)
		return -1;
	return 0;
}
