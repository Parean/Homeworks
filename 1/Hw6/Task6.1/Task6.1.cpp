#include <stdio.h>
#include <iostream>
#include "tree.h"

enum { stop, add, deleteValue, findElement, ascendingOrderOutput, descendingOrderOutput, debugPrint };

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Tree *tree = createTree();
	printf("\n—писок операций:\n 0 Ч ¬ыход\n 1 Ч ƒобавить значение\n");
	printf(" 2 Ч ”далить значение\n 3 Ч ѕроверить множество на наличие элемента\n");
	printf(" 4 Ч ѕечать элементов в возрастающем пор€дке\n 5 Ч ѕечать элементов в убывающем пор€дке\n");
	printf(" 6 Ч ѕечать в формате (a b c), где  \"a\" Ч значение в узле, а \"b\" ");
	printf(" и \"c\" Ч аналогичные представлени€ поддеревьев правого и левого потомка\n");
	int digit = -1;
	int value = 0;
	while (digit != stop)
	{
		printf("\n\n¬ыберите операцию и введите цифру\n");
		scanf("%d", &digit);
		switch (digit)
		{
		case add:
		{
			printf("\n¬ведите значение\n");
			scanf("%d", &value);
			addInTree(tree, value);
			break;
		}
		case deleteValue:
		{
			printf("\n¬ведите значение\n");
			scanf("%d", &value);
			deleteNode(tree, value);
			break;
		}
		case findElement:
		{
			printf("\n¬ведите значение\n");
			scanf("%d", &value);
			if (findNode(tree, value) != 0)
				printf("\nЁлемент принадлежит множеству\n");
			else
				printf("\nЁлемент не принадлежит множеству\n");
			break;
		}
		case ascendingOrderOutput:
		{
			printf("\nЁлементы в возрастающем пор€дке:\n");
			printInAscendingOrder(tree);
			break;
		}
		case descendingOrderOutput:
		{
			printf("\nЁлементы в убывающем пор€дке:\n");
			printInDescendingOrder(tree);
			break;
		}
		case debugPrint:
		{
			printf("\nќтладочный вывод:\n");
			debugOutput(tree);
			break;
		}
		}
	}
	deleteTree(tree);
}