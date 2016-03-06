#pragma once

#include "outputer.h"

class FileOutputer: public Outputer
{
public:
	FileOutputer(int **value, int sizeOfArray);
    ~FileOutputer();

private:
    FILE *file;

    void print(char *string) const;
    void print(char *string, int value) const;
};

