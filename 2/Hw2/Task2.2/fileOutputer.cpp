#include "fileOutputer.h"

FileOutputer::FileOutputer(int **value, int sizeOfArray) : Outputer(value, sizeOfArray)
{
    file = fopen("text.txt", "w");
}

void FileOutputer::print(char *string, int value) const
{
    fprintf(file, string, value);
}

void FileOutputer::print(char *string) const
{
    fprintf(file, string);
}

FileOutputer::~FileOutputer()
{
    fclose(file);
}
