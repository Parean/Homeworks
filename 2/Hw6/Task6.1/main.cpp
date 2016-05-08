#include "secondclass.h"

/**
 * This program creates two objects of the first class and one object of a
 * second class that copies the values of the first two
 * The constructor of the last object throws an exception and the destructor
 * is called for all four objects of the first class
 * The destructor for the object of the second class is not called,
 * because it was not created
 * Then exception is processed
 */

int main()
{
	try
	{
	FirstClass firstObject;
	FirstClass secondObject;
	SecondClass thirdObject(firstObject, secondObject);
	}
	catch(Exception &)
	{
		cout << "Exception was thrown" << endl;
	}

	return 0;
}
