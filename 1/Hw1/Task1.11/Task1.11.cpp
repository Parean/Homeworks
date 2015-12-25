#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void sort(int *segment, int begin, int end)
{
	int supportElement = segment[(begin + end) / 2];
	int i = begin;
	int j = end;
	int temp = 0;
	while (i <= j)
	{
		while (segment[i] < supportElement)
			i++;
		while (segment[j] > supportElement)
			j--;
		if (i <= j)
		{
			temp = segment[i];
			segment[i] = segment[j];
			segment[j] = temp;
			i++;
			j--;
		}
	}
	if (i < end)
		sort(segment, i, end);
	if (j > begin)
		sort(segment, begin, j);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const maxSize = 100;
	int digits[maxSize];
	printf("Введите размер массива\n");
	int size = 0;
	scanf("%d", &size);
	printf("Исходный массив:\n");
	for (int i = 0; i < size; i++)
	{
		digits[i] = rand();
		printf("%d ", digits[i]);
	}
	sort(digits, 0, size - 1);
	printf("\n");
	printf("Отсортированный массив:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", digits[i]);

	}
}