#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const maxSize = 5;
	int numbers[maxSize][maxSize];
	srand(time(nullptr));
	printf("»сходный массив:\n\n");
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			numbers[i][j] = 0 + rand() % 9;
			printf("%d ", numbers[i][j]);
		}
		printf("\n");
	}
	int i = maxSize / 2;
	int j = i;
	int count = 0;
	int upOrDown = -1;
	int leftOrRight = 1;
	bool outputString = false;
	printf("\nЁлементы, выведенные по спирали:\n");
	while (!(i == -1 && j == 0))
	{
		if (outputString)
		{
			for (int m = 0; m <= count; m++)
			{
				printf("%d ", numbers[i][j]);
				j = j + leftOrRight;
			}
			leftOrRight = -leftOrRight;
			outputString = false;
		}
		else
		{
			for (int m = 0; m <= count; m++)
			{
				printf("%d ", numbers[i][j]);
				i = i + upOrDown;
			}
			upOrDown = -upOrDown;
			outputString = true;
		}
		if (upOrDown != leftOrRight)
			count++;
	}
	printf("\n\n");
}