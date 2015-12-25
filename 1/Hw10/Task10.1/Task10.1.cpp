#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "tree.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	FILE *firstFile = nullptr;
	FILE *secondFile = nullptr;
	firstFile = fopen("text.txt", "r");
	secondFile = fopen("output.txt", "w");
	Queue *queue = createQueue();
	int const size = 256;
	int frequencyOfSymbols[size];
	for (int i = 0; i < size; i++)
		frequencyOfSymbols[i] = 0;
	char token = 0;
	while (!feof(firstFile))
	{
		fscanf(firstFile, "%c", &token);
		if (!feof(firstFile))
			frequencyOfSymbols[token]++;
	}
	for (int i = 0; i < size; i++)
	{
		if (frequencyOfSymbols[i] != 0)
		{
			TreeNode *treeNode = createTreeNode(i, nullptr, nullptr);
			addInQueue(treeNode, frequencyOfSymbols[i], queue);
		}
	}
	Tree *tree = spliceOfNodes(queue);
	debugOutput(tree, secondFile);
	fprintf(secondFile, "\n\n");
	int const countOfDigits = 9;
	char digits[countOfDigits];
	char **symbols = new char *[size];
	for (int i = 0; i < size; i++)
	{
		symbols[i] = new char[countOfDigits];
	}
	codingOfSymbols(tree, digits, symbols);
	rewind(firstFile);
	fscanf(firstFile, "%c", &token);
	while (!feof(firstFile))
	{
		fprintf(secondFile, "%s", symbols[token]);
		fscanf(firstFile, "%c", &token);
	} 
	fclose(firstFile);
	fclose(secondFile);
	deleteQueue(queue);
	deleteTree(tree);
	for (int i = 0; i < size; i++)
	{
		delete[] symbols[i];
	}
	delete[] symbols;
}