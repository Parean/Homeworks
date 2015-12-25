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
	printf("¬ведите индекс числа ‘ибоначчи\n");
	int number = 0;
	scanf("%d", &number);
	printf("„исло с вашим индексом Ч это %d\n", iterativeCounting(number));
	printf("„исло с вашим индексом Ц это %d\n", recursiveCounting(number));
}