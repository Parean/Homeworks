#pragma once
#include "outputer.h"

class ConsolOutputer: public Outputer
{
public:
	ConsolOutputer(int **value, int sizeOfArray);
	void output() const;
};

