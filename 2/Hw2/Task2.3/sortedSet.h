#pragma once
#include "listsComparator.h"
#include "listPointer.h"

struct TreeNode
{
	ListPointer *value;
	int height;
	int listSize;
	TreeNode *left;
	TreeNode *right;
	TreeNode(ListPointer *list, int size):
		listSize(size),
		value(list),
		left(nullptr),
		right(nullptr),
		height(1)
	{}
	~TreeNode()
	{
		delete value;
	}
};

/**
 * @class SortedSet
 * Class representing a sorted set is implemented on the AVL Tree
 * Print function prints not the list, but their sizes
 * Functions "findElement" and "deleteElement" also use as an input value list size
 */

class SortedSet : public ListsComparator
{
public:
	SortedSet();
	ListPointer *findElement(int value);
	void addInSet(ListPointer *value);
	void deleteElement(int value);
	void printInDescendingOrder();
	void printInAscendingOrder();
	void debugOutput();
	~SortedSet();

private:
	TreeNode *tree;

	ListPointer *findElement(TreeNode *treeNode, int value);
	TreeNode *addInSet(TreeNode *&treeNode, ListPointer *value);
	TreeNode *deleteElement(TreeNode *&treeNode, int value);
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

	/**
	 * The function is called in the most difficult kind of the delete element
	 * @return element of tree, which will take place of deleted
	 */
	TreeNode *removeElement(TreeNode *treeNode, TreeNode *&temp);
};
