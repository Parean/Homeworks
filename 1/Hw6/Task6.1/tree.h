#pragma once

struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

Tree *createTree();
TreeNode **findNode(Tree *tree, int value);
void addInTree(Tree *tree, int value);
void deleteNode(Tree *tree, int value);
void printInDescendingOrder(Tree *tree);
void printInAscendingOrder(Tree *tree);
void debugOutput(Tree *tree);
void deleteTree(Tree *tree);
