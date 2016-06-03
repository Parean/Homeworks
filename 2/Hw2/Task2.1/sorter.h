#pragma once
<<<<<<< HEAD

=======
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
#include <iostream>

enum KindOfSorter
{
<<<<<<< HEAD
	bubble,
	insertion,
	quick
=======
    bubble,
    insertion,
    quick
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
};

/**
 * @class Sorter
 * Virtual class from which inherit other
 * classes that perform sorting of array
 */
class Sorter
{
public:

<<<<<<< HEAD
	/**
	 * Constructor is passed an existing array,
	 * the new array in the class wouldn't start,
	 * so he has no destructor
	 */
	Sorter(int *value, int size);

	/**
	 * @return Sorted array
	 */
	int virtual *sort() = 0;

=======
    /**
     * Constructor is passed an existing array,
     * the new array in the class wouldn't start,
     * so he has no destructor
     */
	Sorter(int *value, int size);

    /**
     * @return Sorted array
     */
    int virtual *sort() = 0;
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
protected:
	int *symbols;
	int sizeOfArray;
};

