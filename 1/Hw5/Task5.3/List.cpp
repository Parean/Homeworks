#include "List.h"
#include <stdio.h>

ListElement *createListElement(char value, ListElement *next)
{
	ListElement *newListElement = new ListElement;
	newListElement->value = value;
	newListElement->next = next;
	return newListElement;
}

List *createList()
{
	List *newList = new List;
	newList->first = createListElement(0, nullptr);
	return newList;
}

void addInList(char value, List *list)
{
	ListElement *temp = list->first;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	ListElement *newListElement = createListElement(value, temp->next);
	temp->next = newListElement;
}

void printList(List *list)
{
	ListElement *temp = list->first->next;
	while (temp != nullptr)
	{
		printf("%c", temp->value);
		temp = temp->next;
	}
	printf("\n");
}


char getOutOfList(List *list)
{
	char result = list->first->next->value;
	ListElement *listElement = list->first->next;
	list->first->next = list->first->next->next;
	delete listElement;
	return result;
}


bool listIsEmpty(List *list)
{
	return list->first->next == nullptr;
}

void deleteList(List *list)
{
	while (!listIsEmpty(list))
		getOutOfList(list);
	delete list->first;
	delete list;
}


