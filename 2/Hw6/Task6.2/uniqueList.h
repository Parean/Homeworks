#pragma once

#include "listPointer.h"

class ListException {};

class AddExistingValue : public ListException {};

class RemoveNotExistingValue : public ListException {};

template <typename T>
class UniqueList : public ListPointer<T>
{
public:
	void addValue(const T &value) throw (AddExistingValue);
	void removeValue(const T &value) throw (RemoveNotExistingValue);
};

template <typename T>
void UniqueList<T>::addValue(const T &value) throw (AddExistingValue)
{
	if(this->isPlaced(value))
	{
		throw AddExistingValue();
	}
	ListPointer<T>::addValue(value);
}

template <typename T>
void UniqueList<T>::removeValue(const T &value) throw (RemoveNotExistingValue)
{
	if(!this->isPlaced(value))
	{
		throw RemoveNotExistingValue();
	}
	ListPointer<T>::removeValue(value);
}

