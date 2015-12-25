#pragma once

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

ListElement *createListElement(int value, ListElement *next);
List *createList();
void addInList(int value, List *list);
void getOutOfList(List *list);
void shift(List *&list);
void deleteList(List *list);
int lookInList(List *list);