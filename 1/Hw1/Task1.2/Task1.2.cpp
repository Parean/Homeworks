#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ����� '�'\n");
	int numberOne = 0;
	scanf("%d", &numberOne);
	printf("������� ����� 'b'\n");
	int numberTwo = 0;
	scanf("%d", &numberTwo);
	int result = 0;
	while (numberOne > numberTwo)
	{
		numberOne = numberOne - numberTwo;
		result++;
	}
	printf("�������� ������� ����� %d\n", result);
}