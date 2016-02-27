#include "fileOutputer.h"

FileOutputer::FileOutputer(int **value, int sizeOfArray) : Outputer(value, sizeOfArray){}

void FileOutputer::output() const
{
    FILE *file = fopen("text.txt", "w");
    int i = size / 2;
    int j = i;
    int count = 0;
    int upOrDown = -1;
    int leftOrRight = 1;
    bool outputString = false;
    fprintf(file, "\nOutput:\n\n");
    while (!(i == -1 && j == 0))
    {
        if (outputString)
        {
            for (int m = 0; m <= count; m++)
            {
                fprintf(file, "%d ", symbols[i][j]);
                j = j + leftOrRight;
            }
            leftOrRight = -leftOrRight;
            outputString = false;
        }
        else
        {
            for (int m = 0; m <= count; m++)
            {
                fprintf(file,"%d ", symbols[i][j]);
                i = i + upOrDown;
            }
            upOrDown = -upOrDown;
            outputString = true;
        }
        if (upOrDown != leftOrRight)
            count++;
    }
}

