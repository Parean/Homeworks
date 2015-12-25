#pragma once
#include <stdio.h>

union Symbol
{
	int number;
	char token;
};

struct TreeNode
{
	Symbol value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};


Tree *createTree();
void debugOutput(Tree *tree);
void deleteTree(Tree *tree);
void buildTree(Tree *tree, FILE *&file);
int calculate(Tree *tree);
