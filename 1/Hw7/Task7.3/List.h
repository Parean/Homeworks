#pragma once
#include "string.h"

struct ListElement
{
	String *value;
	ListElement *next;
	int countOfWords;
};

struct List
{
	ListElement *first;
};

ListElement *createListElement(String *value, ListElement *next);
List *createList(); 
void addInList(String *value, List *list, int &count, bool isRebuilding, int similiarWords);
String *getOutOfList(List *list);
void printList(List *list);
int lengthOfList(List *list);
void addInList(String *value, List *list, int &count, bool isRebuilding);
bool listIsEmpty(List *list);
void deleteList(bool isRebuilding, List *list);