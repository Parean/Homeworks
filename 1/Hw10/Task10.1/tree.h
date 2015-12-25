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

TreeNode *createTreeNode(char value, TreeNode *left, TreeNode *right);
Tree *createTree(TreeNode *root);
void codingOfSymbols(Tree *tree, char *digits, char **symbols);
void debugOutput(Tree *tree, FILE *file);
void deleteTree(Tree *tree);

