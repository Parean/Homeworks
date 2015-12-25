#include <stdio.h>
#include <iostream>

void reverse(int *segment, int beginOfSegment, int endOfSegment)
{
	int temp = 0;
	for (int j = beginOfSegment; j < (beginOfSegment + endOfSegment) / 2; j++)
	{
		temp = segment[j];
		segment[j] = segment[beginOfSegment + endOfSegment - j - 1];
		segment[beginOfSegment + endOfSegment - j - 1] = temp;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int const maxSize = 100;
	int randomDigits[maxSize];
	printf("������� ����� ������� �������\n");
	int firstSegment = 0;
	scanf("%d", &firstSegment);
	printf("������� ����� ������� �������\n");
	int secondSegment = 0;
	scanf("%d", &secondSegment);
	printf("������ �� ��������������:\n");
	for (int i = 0; i < firstSegment + secondSegment; i++)
	{
		randomDigits[i] = rand();
		printf("%d ", randomDigits[i]);
	}
	printf("\n\n");
	reverse(randomDigits, 0, firstSegment);
	reverse(randomDigits, firstSegment, firstSegment + secondSegment);
	reverse(randomDigits, 0, firstSegment + secondSegment);
	printf("������ ����� ��������������:\n");
	for (int i = 0; i < firstSegment + secondSegment; i++)
		printf("%d ", randomDigits[i]);
	printf("\n");
}