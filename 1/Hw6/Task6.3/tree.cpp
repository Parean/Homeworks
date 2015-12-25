#include "tree.h"
#include <stdio.h>

TreeNode *createTreeNode(Tree *&tree, int value);
TreeNode *findNode(TreeNode *treeNode, int value);
TreeNode *addInTree(Tree *tree, TreeNode *&treeNode, int value);
TreeNode *deleteNode(TreeNode *&treeNode, int value);
void printInDescendingOrder(TreeNode *treeNode);
void printInAscendingOrder(TreeNode *treeNode);
void debugOutput(TreeNode *treeNode);
void deleteTree(TreeNode *&treeNode);
TreeNode *balanceTree(TreeNode *treeNode);
TreeNode *rotateLeft(TreeNode *&treeNode);
TreeNode *rotateRight(TreeNode *&treeNode);
int height(TreeNode *treeNode);
int getBalanceFactor(TreeNode *treeNode);
void setTheHeight(TreeNode *treeNode);
TreeNode *removeElement(TreeNode *treeNode, TreeNode *&temp);

TreeNode *createTreeNode(Tree *&tree, int value)
{
	TreeNode *newTreeNode = new TreeNode;
	newTreeNode->value = value;
	newTreeNode->height = 1;
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

TreeNode *findNode(Tree *tree, int value)
{
	return findNode(tree->root, value);
}

TreeNode *findNode(TreeNode *treeNode, int value)
{
	if (!treeNode)
		return nullptr;
	if (treeNode->value == value)
		return treeNode;
	if (treeNode->value > value)
		return findNode(treeNode->left, value);
	else
		return findNode(treeNode->right, value);
}

void addInTree(Tree *tree, int value)
{
	addInTree(tree, tree->root, value);
}

TreeNode *addInTree(Tree *tree, TreeNode *&treeNode, int value)
{
	if (!treeNode)
		return createTreeNode(tree, value);
	if (treeNode->value > value)
		treeNode->left = addInTree(tree, treeNode->left, value);
	else
		treeNode->right = addInTree(tree, treeNode->right, value);
	return treeNode = balanceTree(treeNode);
}

void deleteNode(Tree *tree, int value)
{
	if (tree->root)
	{
		deleteNode(tree->root, value);
	}
}

TreeNode* deleteNode(TreeNode *&treeNode, int value)
{
	if (!treeNode)
		return 0;
	else if (treeNode->value > value)
		return deleteNode(treeNode->left, value);
	else if (treeNode->value < value)
		return deleteNode(treeNode->right, value);
	else if (treeNode->value == value)
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
			return balanceTree(treeNode);
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
			return balanceTree(treeNode);
		}
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
	return balanceTree(treeNode);
}

int height(TreeNode *treeNode)
{
	if (!treeNode)
		return 0;
	else
		return treeNode->height;
}

int getBalanceFactor(TreeNode *treeNode)
{
	return height(treeNode->right) - height(treeNode->left);
}

void setTheHeight(TreeNode *treeNode)
{
	int heightLeft = height(treeNode->left);
	int heightRight = height(treeNode->right);
	if (heightLeft > heightRight)
		treeNode->height = heightLeft + 1;
	else
		treeNode->height = heightRight + 1;
}

TreeNode *rotateLeft(TreeNode *&treeNode)
{
	TreeNode *temp = treeNode->right;
	treeNode->right = temp->left;
	temp->left = treeNode;
	setTheHeight(treeNode);
	setTheHeight(temp);
	return temp;
}

TreeNode *rotateRight(TreeNode *&treeNode)
{
	TreeNode *temp = treeNode->left;
	treeNode->left = temp->right;
	temp->right = treeNode;
	setTheHeight(treeNode);
	setTheHeight(temp);
	return temp;
}

TreeNode *balanceTree(TreeNode *treeNode)
{
	setTheHeight(treeNode);
	if (getBalanceFactor(treeNode) == 2)
	{
		if (getBalanceFactor(treeNode->right) < 0)
			treeNode->left = balanceTree(treeNode->left);
		return rotateLeft(treeNode);
	}
	if (getBalanceFactor(treeNode) == -2)
	{
		if (getBalanceFactor(treeNode->left) > 0)
			treeNode->right = balanceTree(treeNode->right);
		return rotateRight(treeNode);
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