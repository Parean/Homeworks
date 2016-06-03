#pragma once
<<<<<<< HEAD

=======
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
#include "sorter.h"

class QuickSorter: public Sorter
{
public:
	QuickSorter(int *value, int size);
	int *sort();
<<<<<<< HEAD

private:

	/**
	 * Since the algorithm is recursive,
	 * for writing of class required additional function qsort,
	 * in which it is implemented
	 */
	void qsort(int begin, int end);
=======
private:

    /**
     * Since the algorithm is recursive,
     * for writing of class required additional function qsort,
     * in which it is implemented
     */
    void qsort(int begin, int end);
>>>>>>> ab9fd23beebbb101d40b5e5aef414f296a03f3d8
};

