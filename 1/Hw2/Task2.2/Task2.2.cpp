#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� �����\n");
	int base = 0;
	scanf("%d", &base);
	printf("������� ���������� �������\n");
	int exponent = 0;
	scanf("%d", &exponent);
	int result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 0)
		{
			base = base * base;
			exponent = exponent / 2;
		}
		else
		{
			result = base * result;
			exponent--;
		}
	}
	printf("�����: %d\n", result);
}