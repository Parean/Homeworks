#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ����� '�'\n");
	int base = 0;
	scanf("%d", &base);
	printf("������� ���������� ������� 'n'\n");
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
	printf("����� ������� ����� ����� %d\n", result);
}