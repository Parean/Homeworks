#pragma once

#include <QList>

/**
 *@class BubbleSorter
 * A template class representing the implementation of the sorter with
 * the single method sort()
 */
template <typename T>
class BubbleSorter
{
public:
	BubbleSorter() {}
	~BubbleSorter() {}

	/**
	 * @return new sorted list
	 */
	static QList<T> sort(const QList<T> &initialList);

};

template <typename T>
QList<T> BubbleSorter<T>::sort(const QList<T> &initialList)
{
	QList<T> list(initialList);
	for (int i = 0; i < list.length(); i++)
	{
		for (int j = 0; j < list.length() - i - 1; j++)
		{
			if (list.at(j) > list.at(j+1))
				list.swap(j, j + 1);
		}
	}

	return list;
}


