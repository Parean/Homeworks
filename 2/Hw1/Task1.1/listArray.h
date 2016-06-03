#pragma once

#include "list.h"

class ListArray : public List
{
public:
	ListArray();
	void addValue(int value);
	bool removeValue(int value);
	int findPositionOfValue(int value) const;
	bool isEmpty() const;
	int length() const;
	~ListArray();
private:
	int *listArray;
	int sizeOfList;
	int numberOfElements;

	/**
	 * The function is called when the array is full
	 * and increases its size by half
	 */
	void increaseList();
};

