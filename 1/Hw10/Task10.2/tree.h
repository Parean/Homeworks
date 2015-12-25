#pragma once
#include <stdio.h>

struct TreeNode
{
	char value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

void decoding(Tree *tree, FILE *inputFile, FILE *outputFile);
Tree *createTree(FILE *file);
void deleteTree(Tree *tree);
