#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const size = 28;
	int sumOfDigits[size];
	for (int i = 0; i < size; i++)
		sumOfDigits[i] = 0;
	int maxValueCounts = 10;
	for (int i = 0; i < maxValueCounts; i++)
		for (int j = 0; j < maxValueCounts; j++)
			for (int k = 0; k < maxValueCounts; k++)
				sumOfDigits[i + j + k]++;
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		sumOfDigits[i] = sumOfDigits[i] * sumOfDigits[i];
		result = result + sumOfDigits[i];
	}
	printf("„исло счастливых билетов Ц %d\n", result);
}