#pragma once

#include <iostream>

template <typename T>
struct TreeNode
{
	T value;
	int height;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(T value):
		value(value),
		left(nullptr),
		right(nullptr),
		height(1)
	{}
};

/**
 * @class SortedSet
 * Template class representing a sorted set is implemented on the AVL Tree
 */
template <typename T>
class SortedSet
{
public:
	SortedSet();
	SortedSet(SortedSet<T> *&sortedSet);

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new set containing all the
	 * elements from the intersection of the input sets
	 * @return new set
	 */
	static SortedSet<T> *intersectionOfSets(SortedSet<T> *&firstSet, SortedSet<T> *&secondSet);

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new set containing all the
	 * elements from the union of the input sets
	 * @return new set
	 */
	static SortedSet<T> *mergeOfSets(SortedSet<T> *&firstSet, SortedSet<T> *&secondSet);

	/**
	 * @brief copySet
	 * The function adds to the set all elements from the input set
	 */
	bool isPlaced(T &value);
	void addInSet(T &value);
	void copySet(SortedSet<T> *&sortedSet);
	void deleteElement(T &value);
	void debugOutput();
	~SortedSet();

private:
	TreeNode<T> *tree;

	static void intersectionOfSets(TreeNode<T> *&firstSetNode, SortedSet<T> *&secondSet, SortedSet<T> *&newSet);
	static void mergeOfSets(TreeNode<T> *&firstSetNode, SortedSet<T> *&newSet);
	void copySet(TreeNode<T> *&treeNode);
	bool isPlaced(TreeNode<T> *treeNode, T &value);
	TreeNode<T> *addInSet(TreeNode<T> *&treeNode, T &value);
	TreeNode<T> *deleteElement(TreeNode<T> *&treeNode, T &value);
	void debugOutput(TreeNode<T> *treeNode) const;
	void deleteTree(TreeNode<T> *&treeNode);
	TreeNode<T> *balanceTree(TreeNode<T> *treeNode);
	TreeNode<T> *rotateLeft(TreeNode<T> *&treeNode);
	TreeNode<T> *rotateRight(TreeNode<T> *&treeNode);
	int getHeight(TreeNode<T> *treeNode) const;
	int getBalanceFactor(TreeNode<T> *treeNode) const;
	void setTheHeight(TreeNode<T> *treeNode) const;

	/**
	 * The function is called in the most difficult kind of the delete element
	 * @return element of tree, which will take place of deleted
	 */
	TreeNode<T> *removeElement(TreeNode<T> *treeNode, TreeNode<T> *&temp);
};

template <typename T>
SortedSet<T>::SortedSet() : tree(nullptr) {}

template <typename T>
SortedSet<T>::SortedSet(SortedSet<T> *&sortedSet) :
	tree(nullptr)
{
	copySet(sortedSet);
}

template <typename T>
void SortedSet<T>::copySet(SortedSet<T> *&sortedSet)
{
	copySet(sortedSet->tree);
}

template <typename T>
void SortedSet<T>::copySet(TreeNode<T> *&treeNode)
{
	if (treeNode)
	{
		addInSet(treeNode->value);
		copySet(treeNode->left);
		copySet(treeNode->right);
	}
}

template <typename T>
SortedSet<T> *SortedSet<T>::intersectionOfSets(SortedSet<T> *&firstSet, SortedSet<T> *&secondSet)
{
	SortedSet<T> *newSet = new SortedSet<T>;
	intersectionOfSets(firstSet->tree, secondSet, newSet);
	return newSet;
}

template <typename T>
void SortedSet<T>::intersectionOfSets(TreeNode<T> *&firstSetNode, SortedSet<T> *&secondSet, SortedSet<T> *&newSet)
{
	if (firstSetNode)
	{
		if (secondSet->isPlaced(firstSetNode->value))
			newSet->addInSet(firstSetNode->value);
		intersectionOfSets(firstSetNode->left, secondSet, newSet);
		intersectionOfSets(firstSetNode->right, secondSet, newSet);
	}
}

template <typename T>
SortedSet<T> *SortedSet<T>::mergeOfSets(SortedSet<T> *&firstSet, SortedSet<T> *&secondSet)
{
	SortedSet<T> *newSet = new SortedSet<T>(secondSet);
	mergeOfSets(firstSet->tree, newSet);
	return newSet;

}

template <typename T>
void SortedSet<T>::mergeOfSets(TreeNode<T> *&firstSetNode, SortedSet<T> *&newSet)
{
	if (firstSetNode)
	{
		newSet->addInSet(firstSetNode->value);
		mergeOfSets(firstSetNode->left, newSet);
		mergeOfSets(firstSetNode->right, newSet);
	}
}

template <typename T>
bool SortedSet<T>::isPlaced(T &value)
{
	return isPlaced(tree, value);
}

template <typename T>
bool SortedSet<T>::isPlaced(TreeNode<T> *treeNode, T &value)
{
	if (!treeNode)
		return false;
	if (treeNode->value == value)
		return true;
	if (treeNode->value > value)
		return isPlaced(treeNode->left, value);
	else
		return isPlaced(treeNode->right, value);
}

template <typename T>
void SortedSet<T>::addInSet(T &value)
{
	addInSet(tree, value);
}

template <typename T>
TreeNode<T> *SortedSet<T>::addInSet(TreeNode<T> *&treeNode, T &value)
{
	if (!treeNode)
	{
		if (!tree)
			return tree = new TreeNode<T>(value);
		return new TreeNode<T>(value);
	}
	if (treeNode->value > value)
		treeNode->left = addInSet(treeNode->left, value);
	else
		treeNode->right = addInSet(treeNode->right, value);
	return treeNode = balanceTree(treeNode);
}

template <typename T>
void SortedSet<T>::deleteElement(T &value)
{
	if (tree)
	{
		deleteElement(tree, value);
	}
}

template <typename T>
TreeNode<T> *SortedSet<T>::deleteElement(TreeNode<T> *&treeNode, T &value)
{
	if (!treeNode)
		return 0;

	else if (treeNode->value > value)
		return deleteElement(treeNode->left, value);

	else if (treeNode->value < value)
		return deleteElement(treeNode->right, value);

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
				TreeNode<T> *temp = treeNode->left;
				delete treeNode;
				treeNode = temp;
			}
			if (treeNode->right)
			{
				TreeNode<T> *temp = treeNode->right;
				delete treeNode;
				treeNode = temp;
			}
			return balanceTree(treeNode);
		}
		else if (treeNode->left != nullptr && treeNode->right != nullptr)
		{
			TreeNode<T> *temp = nullptr;
			treeNode->right = removeElement(treeNode->right, temp);
			TreeNode<T> *left = treeNode->left;
			TreeNode<T> *right = treeNode->right;
			delete treeNode;
			treeNode = temp;
			treeNode->left = left;
			treeNode->right = right;
			return balanceTree(treeNode);
		}
	}
}

template <typename T>
TreeNode<T> *SortedSet<T>::removeElement(TreeNode<T> *treeNode, TreeNode<T> *&temp)
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

template <typename T>
int SortedSet<T>::getHeight(TreeNode<T> *treeNode) const
{
	if (!treeNode)
		return 0;
	else
		return treeNode->height;
}

template <typename T>
int SortedSet<T>::getBalanceFactor(TreeNode<T> *treeNode) const
{
	return getHeight(treeNode->right) - getHeight(treeNode->left);
}

template <typename T>
void SortedSet<T>::setTheHeight(TreeNode<T> *treeNode) const
{
	int heightLeft = getHeight(treeNode->left);
	int heightRight = getHeight(treeNode->right);
	if (heightLeft > heightRight)
		treeNode->height = heightLeft + 1;
	else
		treeNode->height = heightRight + 1;
}

template <typename T>
TreeNode<T> *SortedSet<T>::rotateLeft(TreeNode<T> *&treeNode)
{
	TreeNode<T> *temp = treeNode->right;
	treeNode->right = temp->left;
	temp->left = treeNode;
	setTheHeight(treeNode);
	setTheHeight(temp);
	return temp;
}

template <typename T>
TreeNode<T> *SortedSet<T>::rotateRight(TreeNode<T> *&treeNode)
{
	TreeNode<T> *temp = treeNode->left;
	treeNode->left = temp->right;
	temp->right = treeNode;
	setTheHeight(treeNode);
	setTheHeight(temp);
	return temp;
}

template <typename T>
TreeNode<T> *SortedSet<T>::balanceTree(TreeNode<T> *treeNode)
{
	setTheHeight(treeNode);
	if (getBalanceFactor(treeNode) == 2)
	{
		if (getBalanceFactor(treeNode->right) < 0)
			treeNode->right = rotateRight(treeNode->right);
		return rotateLeft(treeNode);
	}
	if (getBalanceFactor(treeNode) == -2)
	{
		if (getBalanceFactor(treeNode->left) > 0)
			treeNode->left = rotateLeft(treeNode->left);
		return rotateRight(treeNode);
	}
	return treeNode;
}

template <typename T>
void SortedSet<T>::debugOutput()
{
	if (tree)
		debugOutput(tree);
}

template <typename T>
void SortedSet<T>::debugOutput(TreeNode<T> *treeNode) const
{
	std::cout << "(";
	std::cout << treeNode->value << " ";
	if (treeNode->left != nullptr)
	{
		debugOutput(treeNode->left);
	}
	else
		std::cout << "null ";
	if (treeNode->right != nullptr)
	{
		debugOutput(treeNode->right);
	}
	else
		std::cout << "null";
	std::cout << ")";
}

template <typename T>
SortedSet<T>::~SortedSet()
{
	deleteTree(tree);
}

template <typename T>
void SortedSet<T>::deleteTree(TreeNode<T> *&treeNode)
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
