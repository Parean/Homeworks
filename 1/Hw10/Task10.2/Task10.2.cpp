#include <stdio.h>
#include "tree.h"

int main()
{
	FILE *inputFile = fopen("text.txt", "r");
	FILE *outputFile = fopen("output.txt", "w");
	Tree *tree = createTree(inputFile);
	decoding(tree, inputFile, outputFile);
	deleteTree(tree);
	fclose(inputFile);
	fñlose(outputFile);
}