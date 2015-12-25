#include <stdio.h>
#include <iostream>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите строку s\n");
	int const maxSize = 20;
	char symbols[maxSize] = "";
	gets(symbols);
	printf("Введите подстроку s1\n");
	char subString[maxSize] = "";
	gets(subString);
	int i = 0;
	int result = 0;
	while (symbols[i] != '\0')
	{
		int j = 0;
		while (subString[j] == symbols[i])
		{
			i++;
			j++;
		}
		if (subString[j] == '\0')
			result++;
		if (subString[0] == symbols[i])
			i--;
		i++;
	}
	printf("Число вхождений равно %d\n", result);
}