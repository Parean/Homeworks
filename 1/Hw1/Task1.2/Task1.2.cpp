#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите число 'а'\n");
	int numberOne = 0;
	scanf("%d", &numberOne);
	printf("Введите число 'b'\n");
	int numberTwo = 0;
	scanf("%d", &numberTwo);
	int result = 0;
	while (numberOne > numberTwo)
	{
		numberOne = numberOne - numberTwo;
		result++;
	}
	printf("Неполное частное равно %d\n", result);
}