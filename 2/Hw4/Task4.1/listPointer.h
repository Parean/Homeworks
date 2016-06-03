#pragma once

#include <QString>

<<<<<<< HEAD
=======
/**
 * @class ListPointer
 * Contains the implementation of the list of QString objects on pointers
 *
 */
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
class ListPointer
{
public:
	ListPointer();
<<<<<<< HEAD
	void addInList(QString &value);
	bool removeValue(QString &value);
	QString pop();
	int findPositionOfValue(QString &value) const;
=======
	void addInList(const QString &value);

	/**
	 * @return true if the item is in the list, and removes it
	 * @return false if the item is not in the list
	 */
	bool removeValue(const QString &value);

	///@brief pop() remove from the list the first element
	QString pop();
	int findPositionOfValue(const QString &value) const;
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
	bool isEmpty() const;
	int length() const;
	~ListPointer();
private:
<<<<<<< HEAD
=======

	/**
	 * @brief The ListElement struct
	 * Represents a single list element
	 */
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
	struct ListElement
	{
		QString value;
		ListElement *next;

<<<<<<< HEAD
		ListElement(QString &string, ListElement *nextElement):
=======
		ListElement(const QString &string, ListElement *nextElement):
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
			value(string),
			next(nextElement)
		{}
	};
<<<<<<< HEAD
=======

>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
	ListElement *list;
	int sizeOfList;
};

