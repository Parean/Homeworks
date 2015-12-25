#pragma once

struct ListElement
{
	char value[20];
	ListElement *next;
};

struct List
{
	ListElement *first;
};

ListElement *createListElement(int value, ListElement *next);
List *createList();
void addInList(char value[20], List *list);
void getOutOfList(List *list);
void printList(List *list); 
void removeAValue(List *list, char value[20]);
bool listIsEmpty(List *list);
void deleteList(List *list);