#include <stdio.h>
#include <iostream>

int recursiveCounting(int index)
{
	int result = 0;
	if (index == 0)
		return 0;
	if ((index == 1) || (index == 2))
		return 1;
	else
		result = recursiveCounting(index - 1) + recursiveCounting(index - 2);
	return result;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ������ ����� ���������\n");
	int number = 0;
	scanf("%d", &number);
	printf("����� � ����� �������� � ��� %d\n", recursiveCounting(number));
}