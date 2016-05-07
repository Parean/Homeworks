#pragma once

#include <QString>

class ListPointer
{
public:
	ListPointer();
	void addInList(const QString &value);
	bool removeValue(const QString &value);
	QString pop();
	int findPositionOfValue(const QString &value) const;
	bool isEmpty() const;
	int length() const;
	~ListPointer();
private:
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

