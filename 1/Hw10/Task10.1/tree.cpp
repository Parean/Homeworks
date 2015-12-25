#include "tree.h"
#include <stdio.h>
#include "Queue.h"

void codingOfSymbols(TreeNode *treeNode, char *digits, char **symbols, int index);
void debugOutput(TreeNode *treeNode, FILE *file);
void deleteTree(TreeNode *&treeNode);


TreeNode *createTreeNode(char value, TreeNode *left, TreeNode *right)
{
	TreeNode *newTreeNode = new TreeNode;
	newTreeNode->value = value;
	newTreeNode->left = left;
	newTreeNode->right = right;
	return newTreeNode;
};

Tree *createTree(TreeNode *root)
{
	Tree *newTree = new Tree;
	newTree->root = root;
	return newTree;
}

void debugOutput(Tree *tree, FILE *file)
{
	if (tree->root)
		debugOutput(tree->root, file);
}

void debugOutput(TreeNode *treeNode, FILE *file)
{
	fprintf(file, "(");
	fprintf(file, "%c ", treeNode->value);
	if (treeNode->left != nullptr)
	{
		debugOutput(treeNode->left, file);
	}
	else
		fprintf(file, "null ");
	if (treeNode->right != nullptr)
	{
		debugOutput(treeNode->right, file);
	}
	else
		fprintf(file, "null");
	fprintf(file, ")");
}

void codingOfSymbols(Tree *tree, char *digits, char **symbols)
{
	
	if (tree->root)
		codingOfSymbols(tree->root, digits, symbols, 0);
}

void codingOfSymbols(TreeNode *treeNode, char *digits, char **symbols, int index)
{
	if (treeNode->left != nullptr)
	{
		digits[index] = '0';
		codingOfSymbols(treeNode->left, digits, symbols, index + 1);
	}
	if (treeNode->right != nullptr)
	{
		digits[index] = '1';
		codingOfSymbols(treeNode->right, digits, symbols, index + 1);
	}
	else
	{
		digits[index] = '\0';
		for (int i = 0; i <= index; i++)
		{
			symbols[treeNode->value][i] = digits[i];
		}
	}
}

void deleteTree(Tree *tree)
{
	deleteTree(tree->root);
}

void deleteTree(TreeNode *&treeNode)
{
	if (treeNode->left != nullptr)
		deleteTree(treeNode->left);
	if (treeNode->right != nullptr)
		deleteTree(treeNode->right);
	if (treeNode->left == nullptr && treeNode->right == nullptr)
	{
		delete treeNode;
		treeNode = nullptr;
	}
}