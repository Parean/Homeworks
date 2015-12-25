#include <iostream>
#include <stdio.h>

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
				if (graph[i][j] == 0)
					graph[i][j] = INT_MAX;
				j++;
			}
			i++;
		}
		int size = j;
		bool *used = new bool[size];
		for (int i = 0; i < size; i++)
		{
			used[i] = false;
		}
		int *previousNode = new int[size];
		for (int i = 0; i < size; i++)
		{
			previousNode[i] = INT_MAX;
		}
		int *minWeight = new int[size];
		for (int i = 1; i < size; i++)
		{
			minWeight[i] = INT_MAX;
		}
		minWeight[0] = 0;
		printf("Минимальное остовное дерево:\n\n");
		for (int i = 0; i < size; i++)
		{
			int currentNode = -1;
			for (j = 0; j < size; j++)
			{
				if (!used[j] && (currentNode == -1 || minWeight[j] < minWeight[currentNode]))
					currentNode = j;
			}
			used[currentNode] = true;
			if (previousNode[currentNode] != INT_MAX)
				printf("Узлы %d и %d связываются ребром длины %d\n", previousNode[currentNode], currentNode, minWeight[currentNode]);
			for (j = 0; j < size; j++)
			{
				if (graph[currentNode][j] < minWeight[j])
				{
					minWeight[j] = graph[currentNode][j];
					previousNode[j] = currentNode;
				}
			}
		}
		fclose(file);
		delete[] used;
		delete[] minWeight;
		delete[] previousNode;	
	}
}