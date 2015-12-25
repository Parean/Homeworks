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
		int currentIndex = 0;
		printf("Введите начальную вершину\n");
		scanf("%d", &currentIndex);
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
		char *numbering = new char[size];
		for (int j = 0; j < size; j++)
			used[j] = false;
		int visited = 0;
		Stack *stack = createStack();
		addInStack(currentIndex, stack);
		used[currentIndex] = true;
		while (!stackIsEmpty(stack))
		{
			currentIndex = pop(stack);
			numbering[currentIndex] = 'a' + visited;
			visited++;
			for (int i = 0; i < size; i++)
			{
				if (graph[currentIndex][i] != 0 && !used[i])
				{
					addInStack(i, stack);
					used[i] = true;
				}
			}
		}
		printf("\nНумерация вершин графа:\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("%d - %c ", i, numbering[i]);
		}
		delete[] used;
		delete[] numbering;
		deleteStack(stack);
		fclose(file);
	}
}