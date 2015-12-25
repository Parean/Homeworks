#pragma once

struct ListElement
{
	char value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};

ListElement *createListElement(char value, ListElement *next);
List *createList();
void addInList(char value, List *list);
char getOutOfList(List *list);
void printList(List *list);
bool listIsEmpty(List *list);
void deleteList(List *list);