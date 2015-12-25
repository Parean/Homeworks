#include "tree.h"
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Tree *tree = createTree();
	FILE *file = nullptr;
	if ((file = fopen("text.txt", "r")) == NULL)
		printf("Ошибка открытия файла\n");
	else
	{
		buildTree(tree, file);
		printf("Дерево разбора арифметического выражения:\n");
		debugOutput(tree);
		printf("\n\nЗначение выражения: %d", calculate(tree));
		deleteTree(tree);
		fclose(file);
	}
}