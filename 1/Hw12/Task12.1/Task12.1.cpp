#include <stdio.h>
#include <iostream>
#include "parser.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = fopen("text.txt", "r");
	if (E(file))
		printf("Выражение корректно\n");
	else
		printf("Выражение некорректно\n");
	fclose(file);
}