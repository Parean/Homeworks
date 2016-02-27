#pragma once
#include <stdio.h>


enum kindOfOutput
{
    consol = 1,
    file = 2
};

/**
 * @class Outputer
 * Virtual class from which inherit other
 * classes that perform output of array
 */
class Outputer
{
public:

    /**
     * Constructor is passed an existing array,
     * the new array in the class wouldn't start,
     * so he has no destructor
     */
	Outputer(int **value, int sizeOfArray);
	virtual void output() const = 0;
protected:
	int **symbols;
	int size;
};

