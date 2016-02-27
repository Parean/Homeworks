#pragma once
#include "outputer.h"

class FileOutputer: public Outputer
{
public:
	FileOutputer(int **value, int sizeOfArray);
	void output() const;
};

