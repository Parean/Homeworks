#include <stdio.h>
#include <iostream>

int iterativeCounting(int index)
{
	int previousNumber = 0;
	int result = 1;
	int temp = 0;
	for (int i = 1; i < index; i++)
	{
		temp = result;
		result = previousNumber + result;
		previousNumber = temp;
	}
	if (index == 0)
		return 0;
	else
		return result;

}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("������� ������ ����� ���������\n");
	int number = 0;
	scanf("%d", &number);
	printf("����� � ����� ��������  � ��� %d\n", iterativeCounting(number));
}