#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

void heapsort(int *segment, int j, int size)
{
	int temp = segment[j];
	int child = 0;
	while (size >= 0 && j <= size / 2)
	{
		child = j * 2 + 1;
		if (((child < size) || (size == 1)) && (segment[child] < segment[child + 1]))
			child++;
		if (temp > segment[child]) break;
		segment[j] = segment[child];
		segment[child] = temp;
		j = child;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const maxSize = 9;
	int digits[maxSize];
	printf("Исходный массив:\n");
	srand(time(nullptr));
	for (int i = 0; i < maxSize; i++)
	{
		digits[i] = 10 + rand() % 91;
		printf("%d ", digits[i]);
	}
	for (int i = maxSize / 2 - 1; i >= 0; i--)
		heapsort(digits, i, maxSize - 1);
	int temp = 0;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		temp = digits[i];
		digits[i] = digits[0];
		digits[0] = temp;
		heapsort(digits, 0, i - 2);
	}
	printf("\nОтсортированный массив:\n");
	for (int i = 0; i < maxSize; i++)
		printf("%d ", digits[i]);
}