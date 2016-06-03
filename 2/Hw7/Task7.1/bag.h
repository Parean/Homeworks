#pragma once

#include <iostream>
#include <algorithm>

/**
 * @class BagException
 * The general class represents an exception in this bag
 * From it there inherit other classes that implement specific types of exceptions
 */
class BagException {};

/**
 * @class DeletingOfNonexistentElements
 * It implements the exception that is thrown when the user tries to remove from the list
 * non-existent elements
 */
class DeletingOfNonexistentElements : public BagException {};

/**
 * @class Bag
 * Template class representing a multibag is implemented on the AVL Tree
 * All user-defined functions are overloaded to be able to run them, not
 * only from the root of the tree, but also from any arbitrary node
 */
template <typename T>
class Bag
{
public:
	Bag() {}
	Bag(Bag<T> *bag);
	~Bag();

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new bag containing all the
	 * elements from the intersection of the input bags
	 * @return new bag
	 */
	static Bag<T> *intersectionOfSets(Bag<T> *firstSet, Bag<T> *secondSet);

	/**
	 * @brief intersectionOfSets
	 * Inside the function creates a new bag containing all the
	 * elements from the union of the input bags
	 * @return new bag
	 */
	static Bag<T> *mergeOfSets(Bag<T> *firstSet, Bag<T> *secondSet);

	/**
	 * @brief copySet
	 * The function adds to the bag all elements from the input bag
	 */
	void copySet(Bag<T> *bag);

	/**
	 * In functions addInSet and deleteElement the second parameter is
	 * the number of elements you want to add or delete
	 */
	void addInSet(const T &value, int numOfElements);

	/**
	 * If you try to delete more elements than there are in the bag, an exception
	 * will be thrown
	 */
	void deleteElement(const T &value, int numOfElements) throw (DeletingOfNonexistentElements);

	int getNumOfElements(const T &value) const;
	void debugOutput() const;
	bool isPlaced(const T &value) const;

private:
	struct TreeNode
	{
		const T value;
		int numDuplicateElements = 0;
		int height = 1;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;

		TreeNode(const T value, int numOfElements):
			value(value),
			numDuplicateElements(numOfElements)
		{}
	};
	TreeNode *tree = nullptr;

	static void intersectionOfSets(TreeNode *firstSetNode, Bag<T> *secondSet, Bag<T> *newSet);
	static void mergeOfSets(TreeNode *firstSetNode, Bag<T> *newSet);
	void copySet(TreeNode *treeNode);

	/**
	 * The following functions change the value of the pointer treeNode in the tree,
	 * so it is passed by reference
	 */
	void addInSet(TreeNode *&treeNode, const T &value, int numOfElements);
	void deleteElement(TreeNode *&treeNode, const T &value, int numOfElements) throw (DeletingOfNonexistentElements);
	void balanceTree(TreeNode *&treeNode);

	/**
	 * @brief deleteTree
	 * The function which deletes the tree rooted at the current node
	 */
	void deleteTree(TreeNode *&treeNode);
	void bagHeight(TreeNode *treeNode);

	///rotate-functions return the new root of the subtree
	TreeNode *rotateLeft(TreeNode *treeNode);
	TreeNode *rotateRight(TreeNode *treeNode);

	/**
	 * @return height of current node, if node == nullptr, return 0
	 */
	int getHeight(TreeNode *treeNode) const;
	int getNumOfElements(TreeNode *treeNode, const T &value) const;
	int getBalanceFactor(TreeNode *treeNode) const;
	void debugOutput(TreeNode *treeNode) const;
	bool isPlaced(TreeNode *treeNode, const T &value) const;

	/**
	 * @brief removeElement
	 * The function is called in the most difficult kind of the delete element
	 * It find element of tree, which will take place of deleted
	 * The function also shifts the descendants of this element, therefore,
	 * treeNode is passed by reference
	 */
	TreeNode *removeElement(TreeNode *&treeNode);
};

template <typename T>
Bag<T>::Bag(Bag<T> *bag)
{
	copySet(bag);
}

template <typename T>
void Bag<T>::copySet(Bag<T> *bag)
{
	copySet(bag->tree);
}

template <typename T>
void Bag<T>::copySet(TreeNode *treeNode)
{
	if (treeNode)
	{
		addInSet(treeNode->value, treeNode->numDuplicateElements);
		copySet(treeNode->left);
		copySet(treeNode->right);
	}
}

template <typename T>
int Bag<T>::getNumOfElements(const T &value) const
{
	return getNumOfElements(tree, value);
}

template <typename T>
int Bag<T>::getNumOfElements(TreeNode *treeNode, const T &value) const
{
	if (!treeNode)
		return 0;

	if (treeNode->value == value)
		return treeNode->numDuplicateElements;

	if (treeNode->value > value)
		return getNumOfElements(treeNode->left, value);
	else
		return getNumOfElements(treeNode->right, value);
}

template <typename T>
Bag<T> *Bag<T>::intersectionOfSets(Bag<T> *firstSet, Bag<T> *secondSet)
{
	Bag<T> *newSet = new Bag<T>;
	intersectionOfSets(firstSet->tree, secondSet, newSet);
	return newSet;
}

template <typename T>
void Bag<T>::intersectionOfSets(TreeNode *firstSetNode, Bag<T> *secondSet, Bag<T> *newSet)
{
	if (firstSetNode)
	{
		int numInSecondSet = secondSet->getNumOfElements(firstSetNode->value);
		if (numInSecondSet)
			newSet->addInSet(firstSetNode->value, std::min(firstSetNode->numDuplicateElements, numInSecondSet));
		intersectionOfSets(firstSetNode->left, secondSet, newSet);
		intersectionOfSets(firstSetNode->right, secondSet, newSet);
	}
}

template <typename T>
Bag<T> *Bag<T>::mergeOfSets(Bag<T> *firstSet, Bag<T> *secondSet)
{
	Bag<T> *newSet = new Bag<T>(secondSet);
	mergeOfSets(firstSet->tree, newSet);
	return newSet;

}

template <typename T>
void Bag<T>::mergeOfSets(TreeNode *firstSetNode, Bag<T> *newSet)
{
	if (firstSetNode)
	{
		newSet->addInSet(firstSetNode->value, firstSetNode->numDuplicateElements);
		mergeOfSets(firstSetNode->left, newSet);
		mergeOfSets(firstSetNode->right, newSet);
	}
}

template <typename T>
bool Bag<T>::isPlaced(const T &value) const
{
	return isPlaced(tree, value);
}

template <typename T>
bool Bag<T>::isPlaced(TreeNode *treeNode, const T &value) const
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
void Bag<T>::addInSet(const T &value, int numOfElements)
{
	addInSet(tree, value, numOfElements);
}

template <typename T>
void Bag<T>::addInSet(TreeNode *&treeNode, const T &value, int numOfElements)
{
	if (!treeNode)
	{
		treeNode = new TreeNode(value, numOfElements);
		return;
	}

	if (treeNode->value > value)
		addInSet(treeNode->left, value, numOfElements);
	else if (treeNode->value < value)
		addInSet(treeNode->right, value, numOfElements);
	else
		treeNode->numDuplicateElements += numOfElements;

	balanceTree(treeNode);
}

template <typename T>
void Bag<T>::deleteElement(const T &value, int numOfElements) throw (DeletingOfNonexistentElements)
{
	if (tree)
	{
		deleteElement(tree, value, numOfElements);
	}
}

template <typename T>
void Bag<T>::deleteElement(TreeNode *&treeNode, const T &value, int numOfElements) throw (DeletingOfNonexistentElements)
{
	if (!treeNode)
		return;

	else if (treeNode->value > value)
		deleteElement(treeNode->left, value, numOfElements);

	else if (treeNode->value < value)
		deleteElement(treeNode->right, value, numOfElements);

	else if (treeNode->value == value)
	{

		if (treeNode->numDuplicateElements < numOfElements)
			throw DeletingOfNonexistentElements();

		if (treeNode->numDuplicateElements > numOfElements)
		{
			treeNode->numDuplicateElements -= numOfElements;
			return;
		}

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
typename Bag<T>::TreeNode *Bag<T>::removeElement(TreeNode *&treeNode)
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
int Bag<T>::getHeight(TreeNode *treeNode) const
{
	if (!treeNode)
		return 0;
	else
		return treeNode->height;
}

template <typename T>
int Bag<T>::getBalanceFactor(TreeNode *treeNode) const
{
	return getHeight(treeNode->right) - getHeight(treeNode->left);
}

template <typename T>
void Bag<T>::bagHeight(TreeNode *treeNode)
{
	int heightLeft = getHeight(treeNode->left);
	int heightRight = getHeight(treeNode->right);

	if (heightLeft > heightRight)
		treeNode->height = heightLeft + 1;
	else
		treeNode->height = heightRight + 1;
}

template <typename T>
typename Bag<T>::TreeNode *Bag<T>::rotateLeft(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->right;
	treeNode->right = temp->left;
	temp->left = treeNode;

	bagHeight(treeNode);
	bagHeight(temp);

	return temp;
}

template <typename T>
typename Bag<T>::TreeNode *Bag<T>::rotateRight(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->left;
	treeNode->left = temp->right;
	temp->right = treeNode;

	bagHeight(treeNode);
	bagHeight(temp);

	return temp;
}

template <typename T>
void Bag<T>::balanceTree(TreeNode *&treeNode)
{
	if(!treeNode)
		return;

	bagHeight(treeNode);

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
void Bag<T>::debugOutput() const
{
	if (tree)
		debugOutput(tree);
}

template <typename T>
void Bag<T>::debugOutput(TreeNode *treeNode) const
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
Bag<T>::~Bag()
{
	deleteTree(tree);
}

template <typename T>
void Bag<T>::deleteTree(TreeNode *&treeNode)
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
