#include <iostream>
#include <stdio.h>
#include "stack.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = nullptr;
	if ((file = fopen("text.txt", "r")) == NULL)
		printf("Ошибка открытия файла\n");
	else
	{
		int graph[100][100];
		char spaceOrNewline = 0;
		int i = 0;
		int j = 0;
		while (!feof(file))
		{
			spaceOrNewline = 0;
			j = 0;
			while (spaceOrNewline != '\n' && !feof(file))
			{
				fscanf(file, "%d%c", &graph[i][j], &spaceOrNewline);
				j++;
			}
			i++;
		}
		int size = i - 1;
		bool *used = new bool[size];
		for (int j = 0; j < size; j++)
			used[j] = false;
		bool allVisited = false;
		Stack *stack = createStack();
		printf("Компоненты связности графа:\n\n");
		while (!allVisited)
		{
			int currentIndex = 0;
			while (used[currentIndex] && currentIndex < size)
				currentIndex++;
			if (currentIndex == size)
			{
				allVisited = true;
				break;
			}
			addInStack(currentIndex, stack);
			used[currentIndex] = true;
			while (!stackIsEmpty(stack))
			{
				currentIndex = pop(stack);
				printf("%d ", currentIndex);
				for (int i = 0; i < size; i++)
				{
					if (graph[currentIndex][i] != 0 && !used[i])
					{
						addInStack(i, stack);
						used[i] = true;
					}
				}
			}
			printf("\n");
		}
		delete[] used;
		deleteStack(stack);
		fclose(file);
	}
}