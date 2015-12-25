#include "List.h"
#include <stdio.h>
#include <string.h>

ListElement *createListElement(char value[20], ListElement *next)
{
	ListElement *newListElement = new ListElement;
	strcpy(newListElement->value, value);
	newListElement->next = next;
	return newListElement;
}

List *createList()
{
	List *newList = new List;
	newList->first = createListElement("0", nullptr);
	return newList;
}

void addInList(char value[20], List *list)
{
	ListElement *temp = list->first;
	while (temp->next != nullptr && strcmp(temp->next->value, value)<0)
	{
		temp = temp->next;
	}
	ListElement *newListElement = createListElement(value, temp->next);
	temp->next = newListElement;
}

void removeAValue(List *list, char value[20])
{
	if (!listIsEmpty(list))
	{
		ListElement *temp = list->first;
		while (temp->next != nullptr && strcmp(temp->next->value, value) != 0)
		{
			temp = temp->next;
		}
		if (temp->next != nullptr)
		{
			ListElement *ListElement = temp->next;
			temp->next = temp->next->next;
			delete ListElement;
		}
	}
}

void printList(List *list)
{
	ListElement *temp = list->first->next;
	while (temp != nullptr)
	{
		printf("%s ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}


void getOutOfList(List *list)
{
	ListElement *listElement = list->first->next;
	list->first->next = list->first->next->next;
	delete listElement;
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


