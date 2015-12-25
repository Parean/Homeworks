#include <stdio.h>
#include <iostream>
#include <string.h>

long long hashFunctionForTheFirstCalculation(char *string, long long &baseInMaxDegree, 
	long long result, int countOfSymbols, int base, int modul)
{
	baseInMaxDegree = 1;
	for (int i = countOfSymbols-1; i >= 0; i--)
	{
		result = (result * base + string[i]) % modul;
		if (i != countOfSymbols-1)
			baseInMaxDegree = baseInMaxDegree * base % modul;
	}	
	return result;
}

long long hashFunctionForTheFurtherCalculation(int index, char *string, long long &baseInMaxDegree,
	long long result, int countOfLetter, int base, int modul, int inverseElement)
{
	result = ((result - string[index]) * inverseElement + baseInMaxDegree * string[index + countOfLetter]) % modul;
	return result;
}

void searchSubstring(char *string, char *subString)
{
	int lengthOfSubstring = strlen(subString);
	int lengthOfString = strlen(string);
	long long baseInMaxDegree = 1;
	int const base = 101;
	int const modul = 65521;
	int const inverseElement = 53844;
	long long stringResult = 0;
	bool isFind = false;
	stringResult = hashFunctionForTheFirstCalculation(string, baseInMaxDegree, stringResult, lengthOfSubstring, base, modul);
	long long subStringResult = 0;
	subStringResult = hashFunctionForTheFirstCalculation(subString, baseInMaxDegree, subStringResult, lengthOfSubstring, base, modul);
	for (int i = 0; i < lengthOfString - lengthOfSubstring + 1; i++)
	{
		if (stringResult == subStringResult)
		{
			int j = 0;
			while (j < lengthOfSubstring && subString[j] == string[i + j])
				j++;
			if (j == lengthOfSubstring)
			{
				printf("\nНомер индекса, с которого начинается подстрока — %d\n", i);
				isFind = true;
			}
		}
		stringResult = hashFunctionForTheFurtherCalculation(i, string, baseInMaxDegree, stringResult, lengthOfSubstring, base, modul, inverseElement);
	}
	if (!isFind)
		printf("\nДанной подстроки в строке нет\n");
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите строку\n");
	int const size = 50;
	char string[size];
	gets(string);
	printf("\nВведите подстроку\n");
	char subString[size];
	gets(subString);
	searchSubstring(string, subString);
}