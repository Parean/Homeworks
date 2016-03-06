#pragma once
#include <stdio.h>

enum KindOfOutput
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
     * the new array in the class wouldn't start
     */
	Outputer(int **value, int sizeOfArray);
    void output() const;
    virtual ~Outputer(){}

protected:

    /**
     * An overloaded method, which is implemented in
     * classes heirs, and performs output to screen or to file
     */
    virtual void print(char *string) const = 0;
    virtual void print(char *string, int value) const = 0;
    int **symbols;
	int size;
};

