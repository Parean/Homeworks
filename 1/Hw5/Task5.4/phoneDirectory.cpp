#include "phoneDirectory.h"
#include <stdio.h>
#include <string.h>

PhoneDirectoryElement *createPhoneDirectoryElement(char name[lengthOfWord], char number[lengthOfWord], PhoneDirectoryElement *next)
{
	PhoneDirectoryElement *newPhoneDirectoryElement = new PhoneDirectoryElement;
	strcpy(newPhoneDirectoryElement->name, name);
	strcpy(newPhoneDirectoryElement->number, number);
	newPhoneDirectoryElement->next = next;
	return newPhoneDirectoryElement;
}

PhoneDirectory *createPhoneDirectory()
{
	PhoneDirectory *newPhoneDirectory = new PhoneDirectory;
	newPhoneDirectory->first = createPhoneDirectoryElement("0", "0", nullptr);
	return newPhoneDirectory;
}

void addInPhoneDirectory(char name[lengthOfWord], char number[lengthOfWord], PhoneDirectory *phoneDirectory)
{
	PhoneDirectoryElement *temp = phoneDirectory->first;
	while (temp->next != nullptr && strcmp(temp->next->name, name) < 0)
		temp = temp->next;
	PhoneDirectoryElement *newPhoneDirectoryElement = createPhoneDirectoryElement(name, number, temp->next);
	temp->next = newPhoneDirectoryElement;
}

char *findNumber(PhoneDirectory *phoneDirectory, char name[lengthOfWord])
{
	if (!phoneDirectoryIsEmpty(phoneDirectory))
	{
		PhoneDirectoryElement *temp = phoneDirectory->first;
		while (temp->next != nullptr && strcmp(temp->name, name) != 0)
			temp = temp->next;
		if (strcmp(temp->name, name) == 0)
			return temp->number;
	}
	return nullptr;
}

char *findName(PhoneDirectory *phoneDirectory, char number[lengthOfWord])
{
	if (!phoneDirectoryIsEmpty(phoneDirectory))
	{
		PhoneDirectoryElement *temp = phoneDirectory->first;
		while (temp->next != nullptr && strcmp(temp->number, number) != 0)
			temp = temp->next;
		if (strcmp(temp->number, number) == 0)
			return temp->name;
	}
	return nullptr;
}

bool phoneDirectoryIsEmpty(PhoneDirectory *phoneDirectory)
{
	return phoneDirectory->first->next == nullptr;
}

void getOutOfPhoneDirectory(PhoneDirectory *phoneDirectory)
{
	PhoneDirectoryElement *phoneDirectoryElement = phoneDirectory->first->next;
	phoneDirectory->first->next = phoneDirectory->first->next->next;
	delete phoneDirectoryElement;
}

void deletePhoneDirectory(PhoneDirectory *phoneDirectory)
{
	while (!phoneDirectoryIsEmpty(phoneDirectory))
		getOutOfPhoneDirectory(phoneDirectory);
	delete phoneDirectory->first;
	delete phoneDirectory;
}

void printPhoneDirectory(PhoneDirectory *phoneDirectory, FILE *file)
{
	PhoneDirectoryElement *temp = phoneDirectory->first->next;
	while (temp != nullptr)
	{
		fprintf(file, "\n%s %s", temp->name, temp->number);
		temp = temp->next;
	}
}