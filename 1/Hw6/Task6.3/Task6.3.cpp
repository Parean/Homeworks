#include <stdio.h>
#include <iostream>
#include "tree.h"

enum { stop, add, deleteValue, findElement, ascendingOrderOutput, descendingOrderOutput, debugPrint };

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Tree *tree = createTree();
	printf("\n������ ��������:\n 0 � �����\n 1 � �������� ��������\n");
	printf(" 2 � ������� ��������\n 3 � ��������� ��������� �� ������� ��������\n");
	printf(" 4 � ������ ��������� � ������������ �������\n 5 � ������ ��������� � ��������� �������\n");
	printf(" 6 � ������ � ������� (a b c), ���  \"a\" � �������� � ����, � \"b\" ");
	printf(" � \"c\" � ����������� ������������� ����������� ������� � ������ �������\n");
	int digit = -1;
	int value = 0;
	while (digit != stop)
	{
		printf("\n\n�������� �������� � ������� �����\n");
		scanf("%d", &digit);
		switch (digit)
		{
		case add:
		{
			printf("\n������� ��������\n");
			scanf("%d", &value);
			addInTree(tree, value);
			break;
		}
		case deleteValue:
		{
			printf("\n������� ��������\n");
			scanf("%d", &value);
			deleteNode(tree, value);
			break;
		}
		case findElement:
		{
			printf("\n������� ��������\n");
			scanf("%d", &value);
			if (findNode(tree, value) != 0)
				printf("\n������� ����������� ���������\n");
			else
				printf("\n������� �� ����������� ���������\n");
			break;
		}
		case ascendingOrderOutput:
		{
			printf("\n�������� � ������������ �������:\n");
			printInAscendingOrder(tree);
			break;
		}
		case descendingOrderOutput:
		{
			printf("\n�������� � ��������� �������:\n");
			printInDescendingOrder(tree);
			break;
		}
		case debugPrint:
		{
			printf("\n���������� �����:\n");
			debugOutput(tree);
			break;
		}
		}
	}
	deleteTree(tree);
}