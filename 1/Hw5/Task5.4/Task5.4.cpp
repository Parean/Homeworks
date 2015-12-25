#include <stdio.h>
#include <string.h>
#include <iostream>
#include "phoneDirectory.h"

enum
{
	stop,
	addInDirectory,
	searchByName,
	searchByNumber,
	saveData,
	start
};

void main()
{
	setlocale(LC_CTYPE, "Russian");
	PhoneDirectory *phoneDirectory = createPhoneDirectory();
	char *foundName = nullptr;
	char *foundNumber = nullptr;
	char name[lengthOfWord] = "\0";
	char surname[lengthOfWord] = "\0";
	char number[lengthOfWord] = "\0";
	FILE *file = fopen("text.txt", "r");
	while (!feof(file))
	{
		fscanf(file, "%s", name);
		fscanf(file, "%s", surname);
		strcat(name, " ");
		strcat(name, surname);
		fscanf(file, "%s", number);
		addInPhoneDirectory(name, number, phoneDirectory);
	}
	printf("Список операций:\n 0 — Выход\n 1 — Добавить запись (Имя и телефон)\n 2 — Найти телефон по имени\n");
	printf(" 3 — Найти имя по телефону\n 4 — Сохранить данные в файл");
	int digit = start;
	while (digit != stop)
	{
		printf("\n\nВыберите операцию и введите цифру\n");
		scanf("%d", &digit);
		if (digit == addInDirectory)
		{
			printf("\nВведите имя и номер абонента\n");
			scanf("%s", name);
			scanf("%s", surname);
			strcat(name, " ");
			strcat(name, surname);
			scanf("%s", number);
			addInPhoneDirectory(name, number, phoneDirectory);
		}
		if (digit == searchByName)
		{
			printf("\nВведите имя абонента\n");
			scanf("%s", name);
			scanf("%s", surname);
			strcat(name, " ");
			strcat(name, surname);
			foundNumber = findNumber(phoneDirectory, name);
			if (foundNumber != nullptr)
				printf("\nНомер абонента — %s\n", foundNumber);
			else
				printf("\nТакого абонента нет в базе\n");
		}
		if (digit == searchByNumber)
		{
			printf("\nВведите номер абонента\n");
			scanf("%s", number);
			foundName = findName(phoneDirectory, number);
			if (foundName != nullptr)
				printf("\nИмя абонента — %s\n", foundName);
			else
				printf("\nТакого абонента нет в базе\n");
		}
		if (digit == saveData)
		{
			file = fopen("text.txt", "w");
			printPhoneDirectory(phoneDirectory, file);
			printf("\nТекущие данные сохранены в файл\n");
		}
	}
	deletePhoneDirectory(phoneDirectory);
}