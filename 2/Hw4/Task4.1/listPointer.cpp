#include "listPointer.h"

ListPointer::ListPointer()
{
	sizeOfList = 0;
	QString string = 0;
	list = new ListElement(string, nullptr);
}

void ListPointer::addInList(QString &value)
{
	ListElement *temp = list;
	while (temp->next)
	{
		if (QString::compare(value, temp->value, Qt::CaseSensitive) == 0)
			return;
		temp = temp->next;
	}
	ListElement *newListElement = new ListElement(value, nullptr);
	temp->next = newListElement;
	sizeOfList++;
}

int ListPointer::findPositionOfValue(QString &value) const
{
	ListElement *temp = list->next;
	int position = 1;
	while (temp != nullptr)
	{
		if (QString::compare(value, temp->value, Qt::CaseSensitive) == 0)
			return position;
		temp = temp->next;
		position++;
	}
	return -1;
}

QString ListPointer::pop()
{
	if (isEmpty())
		return QString::number(-1);
	ListElement *listElement = list->next;
	QString value = listElement->value;
	list->next = list->next->next;
	delete listElement;
	sizeOfList--;
	return value;
}

bool ListPointer::removeValue(QString &value)
{
	ListElement *temp = list;
	while (temp->next != nullptr && QString::compare(value, temp->next->value, Qt::CaseSensitive) != 0)
		temp = temp->next;
	if (temp->next != nullptr)
	{
		ListElement *listElement = temp->next;
		temp->next = temp->next->next;
		delete listElement;
		sizeOfList--;
		return true;
	}
	else
		return false;
}

bool ListPointer::isEmpty() const
{
	return sizeOfList == 0;
}

int ListPointer::length() const
{
	return sizeOfList;
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
