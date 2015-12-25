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
	printf("������ ��������:\n 0 � �����\n 1 � �������� ������ (��� � �������)\n 2 � ����� ������� �� �����\n");
	printf(" 3 � ����� ��� �� ��������\n 4 � ��������� ������ � ����");
	int digit = start;
	while (digit != stop)
	{
		printf("\n\n�������� �������� � ������� �����\n");
		scanf("%d", &digit);
		if (digit == addInDirectory)
		{
			printf("\n������� ��� � ����� ��������\n");
			scanf("%s", name);
			scanf("%s", surname);
			strcat(name, " ");
			strcat(name, surname);
			scanf("%s", number);
			addInPhoneDirectory(name, number, phoneDirectory);
		}
		if (digit == searchByName)
		{
			printf("\n������� ��� ��������\n");
			scanf("%s", name);
			scanf("%s", surname);
			strcat(name, " ");
			strcat(name, surname);
			foundNumber = findNumber(phoneDirectory, name);
			if (foundNumber != nullptr)
				printf("\n����� �������� � %s\n", foundNumber);
			else
				printf("\n������ �������� ��� � ����\n");
		}
		if (digit == searchByNumber)
		{
			printf("\n������� ����� ��������\n");
			scanf("%s", number);
			foundName = findName(phoneDirectory, number);
			if (foundName != nullptr)
				printf("\n��� �������� � %s\n", foundName);
			else
				printf("\n������ �������� ��� � ����\n");
		}
		if (digit == saveData)
		{
			file = fopen("text.txt", "w");
			printPhoneDirectory(phoneDirectory, file);
			printf("\n������� ������ ��������� � ����\n");
		}
	}
	deletePhoneDirectory(phoneDirectory);
}