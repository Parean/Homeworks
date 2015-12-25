#pragma once
#include <stdio.h>

int const lengthOfWord = 30;

struct PhoneDirectoryElement
{
	char name[lengthOfWord];
	char number[lengthOfWord];
	PhoneDirectoryElement *next;
};

struct PhoneDirectory
{
	PhoneDirectoryElement *first;
};


PhoneDirectory *createPhoneDirectory();
char *findName(PhoneDirectory *phoneDirectory, char number[lengthOfWord]);
char *findNumber(PhoneDirectory *phoneDirectory, char name[lengthOfWord]);
void addInPhoneDirectory(char name[lengthOfWord], char number[lengthOfWord], PhoneDirectory *phoneDirectory);
void getOutOfPhoneDirectory(PhoneDirectory *phoneDirectory);
bool phoneDirectoryIsEmpty(PhoneDirectory *phoneDirectory);
void deletePhoneDirectory(PhoneDirectory *phoneDirectory);
void printPhoneDirectory(PhoneDirectory *phoneDirectory, FILE *file);