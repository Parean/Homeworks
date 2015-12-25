#include <stdio.h>
#include <iostream>

int gcd(int numberOne, int numberTwo)
{
	while (numberOne != 0 && numberTwo != 0)
	if (numberOne >= numberTwo)
		numberOne = numberOne % numberTwo;
	else
		numberTwo = numberTwo % numberOne;
	return numberOne + numberTwo;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите число n\n");
	int number = 0;
	scanf("%d", &number);
	int denominator = 1;
	for (int i = 1; i < number; i++)
	{
		denominator = (denominator * (i + 1)) / gcd(denominator, i + 1);
	}
	int result;
	for (int i = 1; i < denominator; i++)
	{
		result = gcd(i, denominator);
		if (denominator / result <= number)
			printf("%d/%d ", i / result, denominator / result);
	}

}