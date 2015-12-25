#include "tree.h"
#include <stdio.h>

TreeNode *createTreeNode(Tree *&tree, char value, int number, bool isNumber);
void debugOutput(TreeNode *treeNode);
void deleteTree(TreeNode *&treeNode);
TreeNode *buildTree(Tree *tree, TreeNode *treeNode, FILE *&file);
int calculate(TreeNode *treeNode);

TreeNode *createTreeNode(Tree *&tree, char value, int number, bool isNumber)
{
	TreeNode *newTreeNode = new TreeNode;
	if (isNumber)
		newTreeNode->value.number = number;
	else
		newTreeNode->value.token = value;
	newTreeNode->left = newTreeNode->right = nullptr;
	if (tree->root == nullptr)
		tree->root = newTreeNode;
	return newTreeNode;
};

Tree *createTree()
{
	Tree *newTree = new Tree;
	newTree->root = nullptr;
	return newTree;
}

void buildTree(Tree *tree, FILE *&file)
{
	buildTree(tree, tree->root, file);
}

TreeNode *buildTree(Tree *tree, TreeNode *treeNode, FILE *&file)
{
	char token = 0;	
	while (!feof(file))
	{
		int number = 0;
		bool isNumber = false;
		fscanf(file, "%c", &token);
		if (token >= '0' && token <= '9')
		{
			ungetc(token, file);
			fscanf(file, "%d", &number);
			isNumber = true;
		}
		if (isNumber)
			treeNode = createTreeNode(tree, 0, number, isNumber);
		else if (token != ' ' && token != '(' && token != ')')
			treeNode = createTreeNode(tree, token, 0, isNumber);
		if (token == '+' || token == '-' || token == '/' || token == '*')
		{
			treeNode->left = buildTree(tree, treeNode, file);
			treeNode->right = buildTree(tree, treeNode, file);
		}
		if (isNumber || token == ')')
			return treeNode;
	}
	return treeNode;
}


void debugOutput(Tree *tree)
{
	if (tree->root)
		debugOutput(tree->root);
}

void debugOutput(TreeNode *treeNode)
{
	printf("(");
	if (treeNode->value.token == '*' || treeNode->value.token == '/' ||
		treeNode->value.token == '+' || treeNode->value.token == '-')
		printf("%c ", treeNode->value);
	else
		printf("%d ", treeNode->value);
	if (treeNode->left != nullptr)
	{
		debugOutput(treeNode->left);
	}
	else
		printf("null ");
	if (treeNode->right != nullptr)
	{
		debugOutput(treeNode->right);
	}
	else
		printf("null");
	printf(")");
}

int calculate(Tree *tree)
{
	if (tree->root)
		return calculate(tree->root);
}

int calculate(TreeNode *treeNode)
{
		switch (treeNode->value.token)
	{
		case '+':
			return calculate(treeNode->left) + calculate(treeNode->right);
		case '-':
			return calculate(treeNode->left) - calculate(treeNode->right);
		case '*':
			return calculate(treeNode->left) * calculate(treeNode->right);
		case '/':
			return calculate(treeNode->left) / calculate(treeNode->right);
		default:
			return treeNode->value.number;
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