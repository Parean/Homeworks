#include "List.h"
#include <stdio.h>

String *createEmptyString(int size);

ListElement *createListElement(String *value, ListElement *next)
{
	ListElement *newListElement = new ListElement;
	newListElement->value = value;
	newListElement->next = next;
	newListElement->countOfWords = 1;
	return newListElement;
}

List *createList()
{
	List *newList = new List;
	String *string = createEmptyString(1);
	newList->first = createListElement(string, nullptr);
	return newList;
}

void addInList(String *value, List *list, int &count, bool isRebuilding, int similiarWords)
{
	ListElement *temp = list->first;
	while (true)
	{
		if (comparisonOfStrings(value, temp->value) == equivalent)
		{
			temp->countOfWords++;
			return;
		}
		if (temp->next == nullptr)
			break;
		temp = temp->next;
	}
	ListElement *newListElement = createListElement(value, temp->next);
	temp->next = newListElement;
	if (!isRebuilding)
		count++;
	else
		temp->next->countOfWords = similiarWords;
}

void printList(List *list)
{
	if (listIsEmpty(list))
		return;
	ListElement *temp = list->first->next;
	while (temp != nullptr)
	{
		printf("%s—%d ", temp->value->symbols, temp->countOfWords);
		temp = temp->next;
	}
	printf("\n");
}

int lengthOfList(List *list)
{
	ListElement *temp = list->first->next;
	int result = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		result++;
	}
	return result;
}

String *getOutOfList(List *list)
{
	String *result = list->first->next->value;
	ListElement *listElement = list->first->next;
	list->first->next = list->first->next->next;
	delete listElement;
	return result;
}

bool listIsEmpty(List *list)
{
	return list->first->next == nullptr;
}

void deleteList(bool isRebuilding, List *list)
{
	while (!listIsEmpty(list))
	{
		if (isRebuilding)
			getOutOfList(list);
		else
			deleteString(getOutOfList(list));
	}
	delete list->first;
	delete list;
}


