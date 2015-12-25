#include "tree.h"
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Tree *tree = createTree();
	FILE *file = nullptr;
	if ((file = fopen("text.txt", "r")) == NULL)
		printf("������ �������� �����\n");
	else
	{
		buildTree(tree, file);
		printf("������ ������� ��������������� ���������:\n");
		debugOutput(tree);
		printf("\n\n�������� ���������: %d", calculate(tree));
		deleteTree(tree);
		fclose(file);
	}
}