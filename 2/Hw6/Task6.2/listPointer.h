#pragma once

template <typename T>
class ListPointer
{
public:
	ListPointer();
	void addValue(const T &value);
	void removeValue(const T &value);

	int findPositionOfValue(const T &value) const;
	bool isPlaced(const T &value) const;
	bool isEmpty() const;
	int length() const;

	~ListPointer();

protected:
	struct ListElement
	{
		const T value;
		ListElement *next;

		ListElement(const T &value, ListElement *nextElement):
			value(value),
			next(nextElement)
		{}
	};

	ListElement *list;
	int numberOfElements = 0;
};

template <typename T>
ListPointer<T>::ListPointer()
{
	list = new ListElement(0, nullptr);
}

template <typename T>
void ListPointer<T>::addValue(const T &value)
{
	ListElement *temp = new ListElement(value, list->next);
	list->next = temp;

	numberOfElements++;
}

template <typename T>
int ListPointer<T>::findPositionOfValue(const T &value) const
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

template <typename T>
void ListPointer<T>::removeValue(const T &value)
{
	ListElement *temp = list;
	while (temp->next != nullptr && temp->next->value != value)
		temp = temp->next;

	if (temp->next == nullptr)
		return;

	ListElement *listElement = temp->next;
	temp->next = temp->next->next;
	delete listElement;

	numberOfElements--;
}

template <typename T>
bool ListPointer<T>::isEmpty() const
{
	return numberOfElements == 0;
}

template <typename T>
bool ListPointer<T>::isPlaced(const T &value) const
{
	ListElement *temp = list->next;
	while (temp != nullptr)
	{
		if (temp->value == value)
			return true;
		temp = temp->next;
	}
	return false;
}

template <typename T>
int ListPointer<T>::length() const
{
	return numberOfElements;
}

template <typename T>
ListPointer<T>::~ListPointer()
{
	while (list->next != nullptr)
	{
		ListElement *listElement = list->next;
		list->next = list->next->next;
		delete listElement;
	}
	delete list;
}
