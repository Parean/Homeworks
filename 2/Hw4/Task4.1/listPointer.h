#pragma once

#include <QString>

/**
 * @class ListPointer
 * Contains the implementation of the list of QString objects on pointers
 *
 */
class ListPointer
{
public:
	ListPointer();
	void addInList(const QString &value);

	/**
	 * @return true if the item is in the list, and removes it
	 * @return false if the item is not in the list
	 */
	bool removeValue(const QString &value);

	///@brief pop() remove from the list the first element
	QString pop();
	int findPositionOfValue(const QString &value) const;
	bool isEmpty() const;
	int length() const;
	~ListPointer();
private:

	/**
	 * @brief The ListElement struct
	 * Represents a single list element
	 */
	struct ListElement
	{
		QString value;
		ListElement *next;

		ListElement(const QString &string, ListElement *nextElement):
			value(string),
			next(nextElement)
		{}
	};

	ListElement *list;
	int sizeOfList;
};

