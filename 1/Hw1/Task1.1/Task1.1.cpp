#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� �������� 'x'\n");
	int argument = 0;
	scanf("%d", &argument);
	int squareOfArgument = argument * argument;
	printf("�������� ��������� x^4+x^3+x^2+x+1 ����� %d\n", (squareOfArgument + argument) * (squareOfArgument + 1) + 1);
}