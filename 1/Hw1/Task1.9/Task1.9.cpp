#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите число 'а'\n");
	int base = 0;
	scanf("%d", &base);
	printf("¬ведите показатель степени 'n'\n");
	int exponent = 0;
	scanf("%d", &exponent);
	int result = 1;
	if (exponent != 0)
	{
		for (int i = 0; i < exponent; i++)
			result = result * base;
	}
	else
		result = 1;
	printf("÷ела€ степень числа равна %d\n", result);
}