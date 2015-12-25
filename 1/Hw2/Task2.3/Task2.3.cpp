#include <stdio.h>
#include <iostream>

void decomposition(int *summands, int numberForDecomposition, int currentMaxSummand, int i)
{
	if (numberForDecomposition < 0)
		return;
	if (numberForDecomposition == 0)
	{
		for (int j = 0; j < i; j++)
		{
			if (j != i - 1)
				printf("%d+", summands[j]);
			else
				printf("%d", summands[j]);
		}
			printf("\n");
	}
	else
	{
		if (numberForDecomposition - currentMaxSummand >= 0)
		{
			summands[i] = currentMaxSummand;
			decomposition(summands, numberForDecomposition - currentMaxSummand, currentMaxSummand, i + 1);
		}
		if (currentMaxSummand > 1)
			decomposition(summands, numberForDecomposition, currentMaxSummand - 1, i);
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите число n\n");
	int number = 0;
	scanf("%d", &number);
	int *components = new int[number];
	decomposition(components, number, number - 1, 0);
	delete[] components;
}