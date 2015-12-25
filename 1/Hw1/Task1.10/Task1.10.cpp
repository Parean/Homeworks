#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите строку\n");
	int const maxSize = 20;
	char symbols[maxSize] = "";
	gets(symbols);
	int i = 0;
	while (symbols[i] != '\0') 
	{
		i++;
	}
	int sizeSymbols = i;
	i--;
	bool indicatorOfTheTruth = false;
	int j = 0;
	while ((j <= (sizeSymbols / 2)) && (indicatorOfTheTruth == false))
	{
		if (symbols[j] != symbols[i])
			indicatorOfTheTruth = true;
		i--;
		j++;
	}
	if (indicatorOfTheTruth == false)
		printf("Строка является палиндромом\n");
	else
		printf("Строка не является палиндромом\n");
}