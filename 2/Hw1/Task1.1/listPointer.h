#pragma once

#include "list.h"

class ListPointer : public List
{
public:
	ListPointer();
	void addValue(int value);
	bool removeValue(int value);
	int findPositionOfValue(int value) const;
	bool isEmpty() const;
	int length() const;
	~ListPointer();
private:
	struct ListElement
	{
		int value;
		ListElement *next;
		ListElement(int number, ListElement *nextElement):
			value(number),
			next(nextElement)
		{}
	};
	ListElement *list;
	int numberOfElements;
};

