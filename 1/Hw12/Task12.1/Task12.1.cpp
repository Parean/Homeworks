#include <stdio.h>
#include <iostream>
#include "parser.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = fopen("text.txt", "r");
	if (E(file))
		printf("��������� ���������\n");
	else
		printf("��������� �����������\n");
	fclose(file);
}