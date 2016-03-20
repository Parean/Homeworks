#pragma once

#include "outputer.h"

class ConsolOutputer: public Outputer
{
public:
	ConsolOutputer(int **value, int sizeOfArray);

private:
    void print(char *string) const;
    void print(char *string, int value) const;
};

