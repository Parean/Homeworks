#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const maxSize = 100;
	bool numbers[maxSize];
	printf("¬ведите число\n");
	int size = 0;
	scanf("%d", &size);
	for (int i = 2; i <= size; i++)
		numbers[i] = true;
	numbers[0] = false;
	numbers[1] = false;
	for (int i = 2; i <= size; i++)
	{
		if (numbers[i] == true)
			for (int j = i * i; j <= size; j += i)
				numbers[j] = false;
	}
	printf("ѕростые числа, не превосход€щие введенного Ч это\n");
	for (int i = 2; i <= size; i++)
		if (numbers[i] == true)
			printf("%d ", i);
	printf("\n");
}