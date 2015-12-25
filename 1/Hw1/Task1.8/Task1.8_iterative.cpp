#include <stdlib.h>
#include <iostream>

int iterativeCounting(int factorial)
{
	if (factorial < 0)
	{
		return(0);
	}
	else
	{
		int result = 1;
		for (int i = 1; i <= factorial; i++)
			result = result * i;
		return(result);
	}	
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ����� ��� �������� ����������\n");
	int number = 0;
	scanf("%d", &number);
	if (iterativeCounting(number) == 0)
	{
		printf("��������� ��������� ������ ��� ����� ��������������� �����\n");
	}
	else
	{
		printf("�������� ����� %d\n", iterativeCounting(number));
	}
}