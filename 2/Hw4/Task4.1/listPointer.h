#pragma once

#include <QString>

class ListPointer
{
public:
	ListPointer();
	void addInList(QString &value);
	bool removeValue(QString &value);
	QString pop();
	int findPositionOfValue(QString &value) const;
	bool isEmpty() const;
	int length() const;
	~ListPointer();
private:
	struct ListElement
	{
		QString value;
		ListElement *next;

		ListElement(QString &string, ListElement *nextElement):
			value(string),
			next(nextElement)
		{}
	};
	ListElement *list;
	int sizeOfList;
};

