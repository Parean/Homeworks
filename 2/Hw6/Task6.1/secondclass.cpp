#include "secondclass.h"

SecondClass::SecondClass(FirstClass &first, FirstClass &second) throw(Exception):
	firstObject(first),
	secondObject(second)
{
	Exception::throwException();
}

SecondClass::~SecondClass()
{
	cout << "Destructor was called" << endl;
}
