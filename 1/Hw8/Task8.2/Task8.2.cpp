#include <iostream>
#include <stdio.h>

void printPath(int *path, int i)
{
	printf("%d", path[i]);
	if (path[i] != 1)
	{
		printf(", ");
		printPath(path, path[i]);
	}
	else
		return;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *file = nullptr;
	if ((file = fopen("text.txt", "r")) == NULL)
		printf("Ошибка открытия файла\n");
	else
	{
		int roads = 0;
		int cities = 0;
		fscanf(file, "%d%d", &cities, &roads);
		cities++;
		int **graph = new int *[cities];
		for (int i = 1; i < cities; i++)
			graph[i] = new int[roads];
		for (int i = 1; i < cities; i++)
		{
			for (int j = 0; j < roads; j++)
				graph[i][j] = 0;
		}
		int length = 0;
		int firstCity = 0;
		int secondCity = 0;
		int k = 0;
		while (!feof(file))
		{
			fscanf(file, "%d%d%d", &firstCity, &secondCity, &length);
			graph[firstCity][k] = length;
			graph[secondCity][k] = length;
			k++;
		}
		int *shortcut = new int[cities];
		shortcut[1] = 0;
		int *path = new int[cities];
		path[1] = 1;
		for (int i = 2; i < cities; i++)
			shortcut[i] = INT_MAX;
		bool *used = new bool[cities];
		for (int j = 1; j < cities; j++)
			used[j] = false;
		int jmin = 0;
		int p = 1;
		int pmin = 1;
		while (p < cities)
		{
			int min = INT_MAX;
			for (int j = 0; j < roads; j++)
			{
				if (graph[p][j] != 0 && graph[p][j] < min)
				{
					pmin = 1;
					while (!(pmin == cities || pmin != p && graph[pmin][j] != 0))
						pmin++;
					if (!used[pmin])
					{
						min = graph[p][j];
						jmin = j;
					}
				}
			}
			if (min == INT_MAX)
			{
				used[p] = true;
				p++;
			}	
			else
			{
				if (shortcut[pmin] > shortcut[p] + graph[p][jmin])
				{
					shortcut[pmin] = shortcut[p] + graph[p][jmin];
					path[pmin] = p;
				}
				graph[p][jmin] = 0;
			}
		}
		printf("Города в порядке захвата:\n\n");
		for (int i = 1; i < cities; i++)
		{
			jmin = i;
			for (int j = 1; j < cities; j++)
			{
				if (shortcut[j] < shortcut[jmin])
					jmin = j;
			}
			printf("Город номер %d, расстояние от города 1 — %d, путь через города: ", jmin, shortcut[jmin]);
			printPath(path, jmin);
			shortcut[jmin] = INT_MAX;
			printf("\n");
		}
		delete[] shortcut;
		delete[] path;
		delete[] used;
		for (int i = 1; i < cities; i++)
			delete[] graph[i];
		delete[] graph;
		fclose(file);
	}
}