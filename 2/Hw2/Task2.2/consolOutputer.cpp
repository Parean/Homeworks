#include "consolOutputer.h"

ConsolOutputer::ConsolOutputer(int **value, int sizeOfArray) : Outputer(value, sizeOfArray){}

void ConsolOutputer::print(char *string, int value) const
{
    printf(string, value);
}

void ConsolOutputer::print(char *string) const
{
    printf(string);
}

