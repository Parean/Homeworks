#include "outputer.h"

Outputer::Outputer(int **value, int sizeOfArray):
	size(sizeOfArray),
	symbols(value)
{}

void Outputer::output() const
{
    int i = size / 2;
    int j = i;
    int count = 0;
    int upOrDown = -1;
    int leftOrRight = 1;
    bool outputString = false;
    print("\nOutput:\n\n");
    while (!(i == -1 && j == 0))
    {
        if (outputString)
        {
            for (int m = 0; m <= count; m++)
            {
                print("%d ", symbols[i][j]);
                j = j + leftOrRight;
            }
            leftOrRight = -leftOrRight;
            outputString = false;
        }
        else
        {
            for (int m = 0; m <= count; m++)
            {
                print("%d ", symbols[i][j]);
                i = i + upOrDown;
            }
            upOrDown = -upOrDown;
            outputString = true;
        }
        if (upOrDown != leftOrRight)
            count++;
    }
}

