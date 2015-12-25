#include <stdio.h>
#include <iostream>

int searchVariant(int *students, int numberOfWrittenOffWork)

{
	if (numberOfWrittenOffWork > 3)
		return searchVariant(students, students[numberOfWrittenOffWork]);
	else
		return numberOfWrittenOffWork;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите количество студентов\n");
	int size = 0;
	scanf("%d", &size);
	int *students = new int[size+1];
	int numberOfWrittenOffWork = 0;
	int number = 0;
	printf("\n¬ведите пары чисел, где первое число Ч номер студента, второе Ч номер того, с кого было списано решение\n");
	printf("\nѕервых трех студентов вводить не нужно \n\n");
	printf("\n≈сли студент не сдал решение, введите 0 \n\n");
	for (int i = 3; i < size; i++)
	{
		scanf("%d%d", &number, &numberOfWrittenOffWork);
		students[number] = numberOfWrittenOffWork;
	}
	students[1] = 1;
	students[2] = 2;
	students[3] = 3;
	printf("\n¬ывод пар чисел, где первое число Ч номер студента, второе Ч 1, 2 или 3 Ч сданный вариант\n");
	printf("\n≈сли второе число 0, студент должен быть отчислен\n\n");
	for (int i = 1; i <= size; i++)
	{
		printf("%d %d\n", i, searchVariant(students, i));
	}
	delete[] students;
}