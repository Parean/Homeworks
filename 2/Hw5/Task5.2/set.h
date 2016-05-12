#pragma once

#include <iostream>

/**
 * @class SortedSet
 * Template class representing a sorted set is implemented on the AVL Tree
 * All user-defined functions are overloaded to be able to run them, not
 * only from the root of the tree, but also from any arbitrary node
 */
template <typename T>
class SortedSet
{
public:
	SortedSet();
	SortedSet(SortedSet<T> *sortedSet);
	~SortedSet();

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new set containing all the
	 * elements from the intersection of the input sets
	 * @return new set
	 */
	static SortedSet<T> *intersectionOfSets(SortedSet<T> *firstSet, SortedSet<T> *secondSet);

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new set containing all the
	 * elements from the union of the input sets
	 * @return new set
	 */
	static SortedSet<T> *mergeOfSets(SortedSet<T> *firstSet, SortedSet<T> *secondSet);

	/**
	 * @brief copySet
	 * The function adds to the set all elements from the input set
	 */
	void copySet(SortedSet<T> *sortedSet);
	void addInSet(const T &value);
	void deleteElement(const T &value);

	void debugOutput() const;
	bool isPlaced(const T &value) const;

private:
	struct TreeNode
	{
		const T value;
		int height = 1;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;

		TreeNode(const T value):
			value(value)
		{}
	};
	TreeNode *tree;

	static void intersectionOfSets(TreeNode *firstSetNode, SortedSet<T> *secondSet, SortedSet<T> *newSet);
	static void mergeOfSets(TreeNode *firstSetNode, SortedSet<T> *newSet);

	void copySet(TreeNode *treeNode);
	void addInSet(TreeNode *&treeNode, const T &value);
	void deleteElement(TreeNode *&treeNode, const T &value);

	/**
	 * @brief deleteTree
	 * The function which deletes the tree rooted at the current node
	 */
	void deleteTree(TreeNode *&treeNode);
	void setHeight(TreeNode *treeNode);
	void balanceTree(TreeNode *&treeNode);

	///rotate-functions return the new root of the subtree
	TreeNode *rotateLeft(TreeNode *treeNode);
	TreeNode *rotateRight(TreeNode *treeNode);

	int getBalanceFactor(TreeNode *treeNode) const;

	/**
	 * @return height of current node, if node == nullptr, return 0
	 */
	int getHeight(TreeNode *treeNode) const;
	void debugOutput(TreeNode *treeNode) const;
	bool isPlaced(TreeNode *treeNode, const T &value) const;

	/**
	 * @brief removeElement
	 * The function is called in the most difficult kind of the delete element
	 * It find element of tree, which will take place of deleted
	 */
	TreeNode *removeElement(TreeNode *&treeNode);
};

template <typename T>
SortedSet<T>::SortedSet() : tree(nullptr) {}

template <typename T>
SortedSet<T>::SortedSet(SortedSet<T> *sortedSet) :
	tree(nullptr)
{
	copySet(sortedSet);
}

template <typename T>
void SortedSet<T>::copySet(SortedSet<T> *sortedSet)
{
	copySet(sortedSet->tree);
}

template <typename T>
void SortedSet<T>::copySet(TreeNode *treeNode)
{
	if (treeNode)
	{
		addInSet(treeNode->value);
		copySet(treeNode->left);
		copySet(treeNode->right);
	}
}

template <typename T>
SortedSet<T> *SortedSet<T>::intersectionOfSets(SortedSet<T> *firstSet, SortedSet<T> *secondSet)
{
	SortedSet<T> *newSet = new SortedSet<T>;
	intersectionOfSets(firstSet->tree, secondSet, newSet);
	return newSet;
}

template <typename T>
void SortedSet<T>::intersectionOfSets(TreeNode *firstSetNode, SortedSet<T> *secondSet, SortedSet<T> *newSet)
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
SortedSet<T> *SortedSet<T>::mergeOfSets(SortedSet<T> *firstSet, SortedSet<T> *secondSet)
{
	SortedSet<T> *newSet = new SortedSet<T>(secondSet);
	mergeOfSets(firstSet->tree, newSet);
	return newSet;

}

template <typename T>
void SortedSet<T>::mergeOfSets(TreeNode *firstSetNode, SortedSet<T> *newSet)
{
	if (firstSetNode)
	{
		newSet->addInSet(firstSetNode->value);
		mergeOfSets(firstSetNode->left, newSet);
		mergeOfSets(firstSetNode->right, newSet);
	}
}

template <typename T>
bool SortedSet<T>::isPlaced(const T &value) const
{
	return isPlaced(tree, value);
}

template <typename T>
bool SortedSet<T>::isPlaced(TreeNode *treeNode, const T &value) const
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
void SortedSet<T>::addInSet(const T &value)
{
	addInSet(tree, value);
}

template <typename T>
void SortedSet<T>::addInSet(TreeNode *&treeNode, const T &value)
{
	if (!treeNode)
	{
		treeNode = new TreeNode(value);
		return;
	}

	if (treeNode->value > value)
		addInSet(treeNode->left, value);
	else if (treeNode->value < value)
		addInSet(treeNode->right, value);
	else
		return;

	balanceTree(treeNode);
}

template <typename T>
void SortedSet<T>::deleteElement(const T &value)
{
	if (tree)
		deleteElement(tree, value);
}

template <typename T>
void SortedSet<T>::deleteElement(TreeNode *&treeNode, const T &value)
{
	if (!treeNode)
		return;

	else if (treeNode->value > value)
		deleteElement(treeNode->left, value);

	else if (treeNode->value < value)
		deleteElement(treeNode->right, value);

	else if (treeNode->value == value)
	{
		if ((treeNode->left == nullptr) && (treeNode->right == nullptr))
		{
			delete treeNode;
			treeNode = nullptr;
		}
		else if (((treeNode->left == nullptr) && (treeNode->right != nullptr)) ||
				 ((treeNode->left != nullptr) && (treeNode->right == nullptr)))
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
		else if ((treeNode->left != nullptr) && (treeNode->right != nullptr))
		{
			TreeNode *element = removeElement(treeNode->right);
			TreeNode *left = treeNode->left;
			TreeNode *right = treeNode->right;

			delete treeNode;
			treeNode = element;
			treeNode->left = left;
			treeNode->right = right;
		}

		balanceTree(treeNode);
	}
}

template <typename T>
typename SortedSet<T>::TreeNode *SortedSet<T>::removeElement(TreeNode *&treeNode)
{
	if (!treeNode->left)
		return removeElement(treeNode->left);
	else
	{
		TreeNode *element = treeNode;
		treeNode = treeNode->right;
		return element;
	}

	balanceTree(treeNode);
}

template <typename T>
int SortedSet<T>::getHeight(TreeNode *treeNode) const
{
	if (!treeNode)
		return 0;
	else
		return treeNode->height;
}

template <typename T>
int SortedSet<T>::getBalanceFactor(TreeNode *treeNode) const
{
	return getHeight(treeNode->right) - getHeight(treeNode->left);
}

template <typename T>
void SortedSet<T>::setHeight(TreeNode *treeNode)
{
	int heightLeft = getHeight(treeNode->left);
	int heightRight = getHeight(treeNode->right);

	if (heightLeft > heightRight)
		treeNode->height = heightLeft + 1;
	else
		treeNode->height = heightRight + 1;
}

template <typename T>
typename SortedSet<T>::TreeNode *SortedSet<T>::rotateLeft(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->right;
	treeNode->right = temp->left;
	temp->left = treeNode;

	setHeight(treeNode);
	setHeight(temp);

	return temp;
}

template <typename T>
typename SortedSet<T>::TreeNode *SortedSet<T>::rotateRight(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->left;
	treeNode->left = temp->right;
	temp->right = treeNode;

	setHeight(treeNode);
	setHeight(temp);

	return temp;
}

template <typename T>
void SortedSet<T>::balanceTree(TreeNode *&treeNode)
{
	if(!treeNode)
		return;

	setHeight(treeNode);

	if (getBalanceFactor(treeNode) == 2)
	{
		if (getBalanceFactor(treeNode->right) < 0)
			treeNode->right = rotateRight(treeNode->right);
		treeNode = rotateLeft(treeNode);
	}

	if (getBalanceFactor(treeNode) == -2)
	{
		if (getBalanceFactor(treeNode->left) > 0)
			treeNode->left = rotateLeft(treeNode->left);
		treeNode = rotateRight(treeNode);
	}
}

template <typename T>
void SortedSet<T>::debugOutput() const
{
	if (tree)
		debugOutput(tree);
}

template <typename T>
void SortedSet<T>::debugOutput(TreeNode *treeNode) const
{
	std::cout << "(";
	std::cout << treeNode->value << " ";

	if (!treeNode->left)
		debugOutput(treeNode->left);
	else
		std::cout << "null ";

	if (!treeNode->right)
		debugOutput(treeNode->right);
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
void SortedSet<T>::deleteTree(TreeNode *&treeNode)
{
	if (!treeNode)
		return;

	if (treeNode->left != nullptr)
		deleteTree(treeNode->left);

	if (treeNode->right != nullptr)
		deleteTree(treeNode->right);

	if ((treeNode->left == nullptr) && (treeNode->right == nullptr))
	{
		delete treeNode;
		treeNode = nullptr;
	}
}
