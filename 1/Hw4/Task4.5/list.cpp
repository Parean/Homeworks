#include "list.h"
#include <stdio.h>

ListElement *createListElement(int value, ListElement *next)
{
	ListElement *newListElement = new ListElement;
	newListElement->value = value;
	newListElement->next = next;
	return newListElement;
}

List *createList()
{
	List *newList = new List;
	newList->first = createListElement(1, nullptr);
	newList->first->next = newList->first;
	return newList;
}

void addInList(int value, List *list)
{
	ListElement *temp = list->first;
	ListElement *newListElement = createListElement(value, temp->next);
	temp->next = newListElement;
}



void getOutOfList(List *list)
{
	ListElement *listElement = list->first->next;
	list->first->next = list->first->next->next;
	delete listElement;
}


void shift(List *&list)
{
	list->first = list->first->next;
}


void deleteList(List *list)
{
	while (list->first->next != list->first)
		getOutOfList(list);
	delete list->first;
	delete list;
}


int lookInList(List *list)
{
	return list->first->value;
}


