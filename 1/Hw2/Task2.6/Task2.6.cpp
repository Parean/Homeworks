#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

int checkForSameDigits(int *digits, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (digits[i] == digits[j])
				return true;
	return false;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите количество цифр в вашем числе\n");
	int size = 0;
	scanf("%d", &size);
	int *guessNumber = new int[size];
	for (int i = 0; i < size; i++)
		guessNumber[i] = 0;
	srand(time(0));
	int temp = 0;
	while (checkForSameDigits(guessNumber, size))
	{
		temp = 10000 + rand() % 100000;
		for (int i = 0; i < size/2; i++)
		{
			guessNumber[i] = temp % 10;
			temp = temp / 10;
		}
		temp = 10000 + rand() % 100000;
		for (int i = size/2; i < size; i++)
		{
			guessNumber[i] = temp % 10;
			temp = temp / 10;
		}
	}
	int *myNumber = new int[size];
	int bulls = 0;
	int cows = 0;
	printf("Введите число\n");
	while (bulls != size)
	{
		cows = 0;
		bulls = 0;
		scanf("%d", &temp);
		for (int i = size - 1; i >= 0; i--)
		{
			myNumber[i] = temp % 10;
			temp = temp / 10;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (guessNumber[i] == myNumber[j])
				{
					cows++;
					if (i == j)
						bulls++;
				}
			}
		}
		cows = cows - bulls;
		if (bulls == size)
			printf("Поздравляю! Вы выиграли\n");
		else
			printf("Количество коров: %d Количество быков: %d Попробуйте еще раз\n", cows, bulls);
	}
	delete[] myNumber;
	delete[] guessNumber;
}