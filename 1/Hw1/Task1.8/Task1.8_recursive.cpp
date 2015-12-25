#include <stdlib.h>
#include <iostream>

int recursiveCounting(int factorial, int result)
{
	
	if (factorial < 0)
	{
		return(0);
	}
	else if (factorial < 2)
	{
		return(result);
	}
	else
	{
		result = (recursiveCounting(factorial - 1, result) * factorial);
		return(result);
	}
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ����� ��� �������� ����������\n");
	int number = 0;
	scanf("%d", &number);
	if (recursiveCounting(number, 1) == 0)
	{
		printf("��������� ��������� ������ ��� ����� ��������������� �����\n");
	}
	else
	{
		printf("�������� ����� %d\n", recursiveCounting(number, 1));
	}
}