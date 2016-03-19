#include <stdio.h>

#include "setTester.h"
#include "sortedSet.h"
#include "listTester.h"

enum
{
	stop,
	add,
	deleteValue,
	findValue,
	ascendingOrderOutput,
	descendingOrderOutput,
	debugPrint
};

void testOfComponents()
{
	SetTester setTester;
	QTest::qExec(&setTester);
	ListTester listTester;
	QTest::qExec(&listTester);
}

int main()
{
	testOfComponents();
	printf("\n\n\nThe list of operations:\n 0 - Exit\n 1 - Add value\n"
		   " 2 - Delete value\n 3 - Check out the set on  availability of element\n"
		   " 4 - Print sizes of lists in ascending order\n"
		   " 5 - Print sizes of lists in descending order\n"
		   " 6 - Print sizes in format (a b c), debug output\n");
	int digit = -1;
	int value = 0;
	SortedSet *set = new SortedSet;
	while (digit != stop)
	{
		printf("\n\nSelect an operation and enter a digit\n");
		scanf("%d", &digit);
		switch (digit)
		{
		case add:
		{
			printf("\nThis program is a test of functions class, so for "
				   "testing the function automatically creates a list of a predetermined"
				   " number of elements\n\nEnter the size of the list\n");
			scanf("%d", &value);
			ListPointer *list = new ListPointer;
			for (int i = 0; i < value; i++)
			{
				list->addValue(i);
			}
			set->addInSet(list);
			break;
		}
		case deleteValue:
		{
			printf("\nEnter the size of the list\n");
			scanf("%d", &value);
			set->deleteElement(value);
			break;
		}
		case findValue:
		{
			printf("\nEnter the size of the list\n");
			scanf("%d", &value);
			if (set->findElement(value))
				printf("\nThe element belongs to the set\n");
			else
				printf("\nThe element doesn`t belong to the set\n");
			break;
		}
		case ascendingOrderOutput:
		{
			printf("\nSizes of lists in ascending order:\n");
			set->printInAscendingOrder();
			break;
		}
		case descendingOrderOutput:
		{
			printf("\nSizes of lists in descending order:\n");
			set->printInDescendingOrder();
			break;
		}
		case debugPrint:
		{
			printf("\nDebug output:\n");
			set->debugOutput();
			break;
		}
		}
	}
	delete set;
}

