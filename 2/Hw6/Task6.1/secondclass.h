#pragma once

#include "firstclass.h"

class SecondClass
{
public:
	SecondClass(FirstClass &first, FirstClass &second) throw(Exception);
	~SecondClass();

private:
	FirstClass firstObject;
	FirstClass secondObject;
};
