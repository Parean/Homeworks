#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("¬ведите число\n");
	int number = 0;
	scanf("%d", &number);
	int digits[10];
	for (int i = 0; i < 10; i++)
		digits[i] = 0;
	while (number != 0)
	{
		digits[number % 10]++;
		number = number / 10;
	}
	printf("Ќаименьшее число, которое можно составить из цифр вашего Ц это ");
	if (digits[0] != 0)
	{
		for (int i = 1; i < 10; i++)
			if (digits[i] != 0)
			{
				printf("%d", i);
				digits[i]--;
				break;
			}
	}
	for (int i = 0; i < 10; i++)
		while (digits[i] > 0)
		{
			printf("%d", i);
			digits[i]--;
		}
	printf("\n");
}