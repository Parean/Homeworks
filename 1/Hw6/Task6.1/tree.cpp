#include "tree.h"
#include <stdio.h>

TreeNode *removeElement(TreeNode *treeNode, TreeNode *&temp);
TreeNode **findNode(TreeNode *&treeNode, int value);
TreeNode *addInTree(Tree *tree, TreeNode *treeNode, int value);
void deleteNode(TreeNode *&treeNode);
void printInDescendingOrder(TreeNode *treeNode);
void printInAscendingOrder(TreeNode *treeNode);
void debugOutput(TreeNode *treeNode);
void deleteTree(TreeNode *&treeNode);


TreeNode *createTreeNode(Tree *&tree, int value)
{
	TreeNode *newTreeNode = new TreeNode;
	newTreeNode->value = value;
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

TreeNode **findNode(Tree *tree, int value)
{
	return findNode(tree->root, value);
}

TreeNode **findNode(TreeNode *&treeNode, int value)
{
	if (!treeNode)
		return nullptr;
	if (treeNode->value == value)
		return &treeNode;
	if (treeNode->value > value)
		return findNode(treeNode->left, value);
	else
		return findNode(treeNode->right, value);
}

void addInTree(Tree *tree, int value)
{
	addInTree(tree, tree->root, value);
}

TreeNode *addInTree(Tree *tree, TreeNode *treeNode, int value)
{

	if (!treeNode)
		return createTreeNode(tree, value);
	if (treeNode->value > value)
		treeNode->left = addInTree(tree, treeNode->left, value);
	else
		treeNode->right = addInTree(tree, treeNode->right, value);
	return treeNode;
}

void deleteNode(Tree *tree, int value)
{
	if (tree->root)
	{
		TreeNode **treeNode = findNode(tree->root, value);
		if (treeNode)
			deleteNode(*treeNode);
	}
}

void deleteNode(TreeNode *&treeNode)
{
	if (treeNode->left == nullptr && treeNode->right == nullptr)
	{
		delete treeNode;
		treeNode = nullptr;
	}
	else if (treeNode->left == nullptr && treeNode->right != nullptr ||
		treeNode->left != nullptr && treeNode->right == nullptr)
	{
		if (treeNode->left)
		{
			TreeNode *temp = treeNode->left;
			delete treeNode;
			treeNode = temp;
		}
		if (treeNode->right)
		{
			TreeNode *temp = treeNode->right;
			delete treeNode;
			treeNode = temp;
		}
	}
	else if (treeNode->left != nullptr && treeNode->right != nullptr)
	{
		TreeNode *temp = nullptr;
		treeNode->right = removeElement(treeNode->right, temp);
		TreeNode *left = treeNode->left;
		TreeNode *right = treeNode->right;
		delete treeNode;
		treeNode = temp;
		treeNode->left = left;
		treeNode->right = right;
	}
}

TreeNode *removeElement(TreeNode *treeNode, TreeNode *&temp)
{
	if (treeNode->left != nullptr)
	{
		treeNode->left = removeElement(treeNode->left, temp);
	}
	else
	{
		temp = treeNode;
		return treeNode->right;
	}
	return treeNode;
}

void printInDescendingOrder(Tree *tree)
{
	if (tree->root)
		printInDescendingOrder(tree->root);
}

void printInDescendingOrder(TreeNode *treeNode)
{
	if (treeNode->right != nullptr)
		printInDescendingOrder(treeNode->right);
	printf("%d ", treeNode->value);
	if (treeNode->left != nullptr)
		printInDescendingOrder(treeNode->left);
}

void printInAscendingOrder(Tree *tree)
{
	if (tree->root)
		printInAscendingOrder(tree->root);
}

void printInAscendingOrder(TreeNode *treeNode)
{
	if (treeNode->left != nullptr)
		printInAscendingOrder(treeNode->left);
	printf("%d ", treeNode->value);
	if (treeNode->right != nullptr)
		printInAscendingOrder(treeNode->right);
}

void debugOutput(Tree *tree)
{
	if (tree->root)
		debugOutput(tree->root);
}

void debugOutput(TreeNode *treeNode)
{
	printf("(");
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