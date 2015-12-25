#include "tree.h"
#include <stdio.h>

void deleteTree(TreeNode *&treeNode);
TreeNode *buildTree(FILE *file);

TreeNode *createTreeNode(char value, TreeNode *left, TreeNode *right)
{
	TreeNode *newTreeNode = new TreeNode;
	newTreeNode->value = value;
	newTreeNode->left = left;
	newTreeNode->right = right;
	return newTreeNode;
};

Tree *createTree(FILE *file)
{
	Tree *newTree = new Tree;
	newTree->root = buildTree(file);
	return newTree;
}

TreeNode *buildTree(FILE *file)
{
	char token = 0;	
	char space = 0;
	TreeNode  *treeNode = nullptr;
	while (!feof(file))
	{
		fscanf(file, "%c", &token);
		if (token == '(')
		{
			fscanf(file, "%c", &token);
			fscanf(file, "%c", &space);
			TreeNode *left = buildTree(file);
			TreeNode *right = buildTree(file);
			treeNode = createTreeNode(token, left, right);
			return treeNode;
		}
		else if (token != ')')
		{
			for (int i = 0; i < 4; i++)
				fscanf(file, "%c", &token);
			return nullptr;
		}
	}
}

void decoding(Tree *tree, FILE *inputFile, FILE *outputFile)
{
	char digit = 0;
	while (!feof(inputFile))
	{
		TreeNode *temp = tree->root;
		while (temp->left && temp->right)
		{
			fscanf(inputFile, "%c", &digit);
			if (feof(inputFile))
				return;
			if (digit == '0')
				temp = temp->left;
			if (digit == '1')
				temp = temp->right;
		}
		fprintf(outputFile, "%c", temp->value);
	}
}

void deleteTree(Tree *tree)
{
	deleteTree(tree->root);
}

void deleteTree(TreeNode *&treeNode)
{
	if (treeNode)
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
}
