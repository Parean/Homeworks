#pragma once
#include "string.h"

struct ListElement
{
	String *value;
	ListElement *next;
};

struct List
{
	ListElement *first;
};


List *createList(); 
void addInList(String *value, List *list, int &count, bool isRebuilding);
String *getOutOfList(List *list);
void printList(List *list);
int lengthOfList(List *list);
void addInList(String *value, List *list, int &count, bool isRebuilding);
bool listIsEmpty(List *list); 
bool findAndDeleteElement(List *list, String *string);
void deleteList(bool isRebuilding, List *list);