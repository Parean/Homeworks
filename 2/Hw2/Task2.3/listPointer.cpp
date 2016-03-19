#include "listPointer.h"

ListPointer::ListPointer()
{
	numberOfElements = 0;
	list = new ListElement(0, nullptr);
}

void ListPointer::addValue(int value)
{
	ListElement *temp = new ListElement(value, list->next);
	list->next = temp;
	numberOfElements++;
}

int ListPointer::findPositionOfValue(int value) const
{
	ListElement *temp = list->next;
	int position = 1;
	while (temp != nullptr)
	{
		if (temp->value == value)
			return position;
		temp = temp->next;
		position++;
	}
	return -1;
}

bool ListPointer::removeValue(int value)
{
	ListElement *temp = list;
	while (temp->next != nullptr && temp->next->value != value)
		temp = temp->next;
	if (temp->next != nullptr)
	{
		ListElement *listElement = temp->next;
		temp->next = temp->next->next;
		delete listElement;
		numberOfElements--;
		return true;
	}
	else
		return false;
}

bool ListPointer::isEmpty() const
{
	return numberOfElements == 0;
}

int ListPointer::length() const
{
	return numberOfElements;
}

ListPointer::~ListPointer()
{
	while (list->next != nullptr)
	{
		ListElement *listElement = list->next;
		list->next = list->next->next;
		delete listElement;
	}
	delete list;
}
