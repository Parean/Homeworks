#pragma once

#include "listPointer.h"

/**
 * @brief The ListException class
 * The general class represents an exception in this list
 * From it there inherit other classes that implement specific types of exceptions
 */
class ListException {};

/**
 * @brief The AddExistingValue class
 * It implements the exception that is thrown when the user tries to add to the list already existing element
 */
class AddExistingValue : public ListException {};

/**
 * @brief The RemoveNotExistingValue class
 * It implements the exception that is thrown when the user tries to remove from the list a non-existing element
 */
class RemoveNotExistingValue : public ListException {};

/**
 * @class UniqueList
 * Template class representing a list that contains no duplicate values
 * Class inherit from ListPointer and has redefined functions of adding and removing element,
 * within which an exception is thrown, if necessary
 */
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

