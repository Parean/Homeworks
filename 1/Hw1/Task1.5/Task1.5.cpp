#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ������\n");
	int const maxSize = 20;
	char symbols[maxSize] = "";
	gets(symbols);
	int i = 0;
	int counter = 0;
	while ((symbols[i] != '\0') && (counter >= 0))
	{
		if (symbols[i] == '(')
			counter++;
		if (symbols[i] == ')')
			counter--;
		i++;
	}
	if (counter == 0)
		printf("������ ������ �����������\n");
	else
		printf("������ ������ �� �����������\n");
}