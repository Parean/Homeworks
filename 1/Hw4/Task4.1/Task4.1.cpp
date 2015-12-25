#include <stdio.h>
#include <iostream>
#include <cstring>

void heapsort(char *segment, int j, int size, int maxSize)
{
	char temp = segment[j];
	int child = 0;
	while (size >= 0 && j <= size / 2)
	{
		child = j * 2 + 1;
		if (((child < size) || ((size == 1 && size != maxSize))) && (segment[child] > segment[child + 1]))
			child++;
		if (temp < segment[child]) break;
		segment[j] = segment[child];
		segment[child] = temp;
		j = child;
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите первую строку\n");
	int const maxSize = 30;
	char firstString[maxSize] = "";
	gets(firstString);
	int firstSize = strlen(firstString);
	printf("\nВведите вторую строку\n");
	char secondString[maxSize] = "";
	gets(secondString);
	int secondSize = strlen(secondString);
  	for (int i = firstSize / 2 - 1; i >= 0; i--)
		heapsort(firstString, i, firstSize - 1, firstSize-1);
	char temp = 0;
	for (int i = firstSize - 1; i >= 0; i--)
	{
		temp = firstString[i];
		firstString[i] = firstString[0];
		firstString[0] = temp;
		heapsort(firstString, 0, i - 2, firstSize-2);
	}
	for (int i = secondSize / 2 - 1; i >= 0; i--)
		heapsort(secondString, i, secondSize - 1, secondSize-1);
	for (int i = secondSize - 1; i >= 0; i--)
	{
		temp = secondString[i];
		secondString[i] = secondString[0];
		secondString[0] = temp;
		heapsort(secondString, 0, i - 2, secondSize-2);
	}
	if (strcmp(firstString, secondString) == 0)
		printf("\nДа, можно\n\n");
	else
		printf("\nНет, нельзя\n\n");
}