#pragma once

#include <QStack>
#include <iostream>



/**
 * @class Tree
 * Template class representing a sorted set is implemented on the AVL Tree
 * All user-defined functions are overloaded to be able to run them, not
 * only from the root of the tree, but also from any arbitrary node
 */
template <typename T>
class Tree
{
public:

	Tree();
	Tree(Tree<T> *tree);
	~Tree();

	class TreeNode
	{
	public:
		const T value;
		int height = 1;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;

		TreeNode(const T value):
			value(value)
		{}

		T getValue() const
		{
			return value;
		}
	};

	/**
	 * @class The Iterator class
	 * The class represents an implementation of the object,
	 * which knows how to traverse a tree
	 */
	class Iterator
	{
	public:
		/**
		 * @brief Iterator
		 * The constructor takes a tree and create a new tree, where you can make round
		 */
		Iterator(Tree<T> *initTree);

		/**
		 * @brief next
		 * The function returns a tree item and moves to the next
		 */
		typename Tree<T>::TreeNode next();

		/**
		 * @brief getTree
		 * The function returns the tree that stores the Iterator
		 */
		Tree<T> *getTree() const;

		/**
		 * @brief isEmpty
		 * @return true if all the elements viewed
		 */
		bool isEmpty() const;

		/**
		 * @brief reset
		 * Returns to the initial element
		 */
		void reset();

		/**
		 * @brief remove
		 * Delete the current element and moves to the next
		 */
		void remove();

	private:
		bool isFinished = false;
		Tree<T> *tree = nullptr;
		Tree<T>::TreeNode *treeNode = nullptr;
		QStack<Tree<T>::TreeNode *> stack;
	};

	/**
	 * @brief copyTree
	 * The function adds to the set all elements from the input set
	 */
	void copyTree(Tree<T> *tree);
	void addInTree(const T &value);
	void deleteElement(const T &value);

	void debugOutput() const;
	bool isPlaced(const T &value) const;

private:
	TreeNode *root;
	void copyTree(TreeNode *treeNode);

	/**
	 * The following functions change the value of the pointer treeNode in the tree,
	 * so it is passed by reference
	 */
	void addInTree(TreeNode *&treeNode, const T &value);
	void deleteElement(TreeNode *&treeNode, const T &value);
	void balanceTree(TreeNode *&treeNode);

	/**
	 * @brief deleteTree
	 * The function which deletes the tree rooted at the current node
	 */
	void deleteTree(TreeNode *&treeNode);
	void setHeight(TreeNode *treeNode);

	///rotate-functions return the new root of the subtree
	TreeNode *rotateLeft(TreeNode *treeNode);
	TreeNode *rotateRight(TreeNode *treeNode);

	/**
	 * @return height of current node, if node == nullptr, return 0
	 */
	int getHeight(TreeNode *treeNode) const;
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
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::Tree(Tree<T> *tree) :
	root(nullptr)
{
	copyTree(tree);
}

template <typename T>
void Tree<T>::copyTree(Tree<T> *tree)
{
	copyTree(tree->root);
}

template <typename T>
void Tree<T>::copyTree(TreeNode *treeNode)
{
	if (treeNode)
	{
		addInTree(treeNode->value);
		copyTree(treeNode->left);
		copyTree(treeNode->right);
	}
}

template <typename T>
bool Tree<T>::isPlaced(const T &value) const
{
	return isPlaced(root, value);
}

template <typename T>
bool Tree<T>::isPlaced(TreeNode *treeNode, const T &value) const
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
void Tree<T>::addInTree(const T &value)
{
	addInTree(root, value);
}

template <typename T>
void Tree<T>::addInTree(TreeNode *&treeNode, const T &value)
{
	if (!treeNode)
	{
		treeNode = new TreeNode(value);
		return;
	}

	if (treeNode->value > value)
		addInTree(treeNode->left, value);
	else if (treeNode->value < value)
		addInTree(treeNode->right, value);
	else
		return;

	balanceTree(treeNode);
}

template <typename T>
void Tree<T>::deleteElement(const T &value)
{
	if (root)
		deleteElement(root, value);
}

template <typename T>
void Tree<T>::deleteElement(TreeNode *&treeNode, const T &value)
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
typename Tree<T>::TreeNode *Tree<T>::removeElement(TreeNode *&treeNode)
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
int Tree<T>::getHeight(TreeNode *treeNode) const
{
	if (!treeNode)
		return 0;
	else
		return treeNode->height;
}

template <typename T>
int Tree<T>::getBalanceFactor(TreeNode *treeNode) const
{
	return getHeight(treeNode->right) - getHeight(treeNode->left);
}

template <typename T>
void Tree<T>::setHeight(TreeNode *treeNode)
{
	int heightLeft = getHeight(treeNode->left);
	int heightRight = getHeight(treeNode->right);

	if (heightLeft > heightRight)
		treeNode->height = heightLeft + 1;
	else
		treeNode->height = heightRight + 1;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::rotateLeft(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->right;
	treeNode->right = temp->left;
	temp->left = treeNode;

	setHeight(treeNode);
	setHeight(temp);

	return temp;
}

template <typename T>
typename Tree<T>::TreeNode *Tree<T>::rotateRight(TreeNode *treeNode)
{
	TreeNode *temp = treeNode->left;
	treeNode->left = temp->right;
	temp->right = treeNode;

	setHeight(treeNode);
	setHeight(temp);

	return temp;
}

template <typename T>
void Tree<T>::balanceTree(TreeNode *&treeNode)
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
void Tree<T>::debugOutput() const
{
	if (root)
		debugOutput(root);
}

template <typename T>
void Tree<T>::debugOutput(TreeNode *treeNode) const
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
Tree<T>::~Tree()
{
	deleteTree(root);
}

template <typename T>
void Tree<T>::deleteTree(TreeNode *&treeNode)
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


///Class Iterator
///---------------------------------------------------------------------
template <typename T>
Tree<T>::Iterator::Iterator(Tree<T> *initTree)
{
	tree = new Tree<T>(initTree);
	treeNode = tree->root;
}

template <typename T>
typename Tree<T>::TreeNode Tree<T>::Iterator::next()
{
	if(!treeNode)
		return 0;

	auto result = *treeNode;

	if(treeNode->right)
	{
		stack.push(treeNode->right);
	}

	if(treeNode->left)
	{
		treeNode = treeNode->left;
	}
	else
	{
		if (stack.isEmpty())
		{
			isFinished = true;
		}
		else
		{
			treeNode = stack.top();
			stack.pop();
		}

	}

	return result;
}

template <typename T>
void Tree<T>::Iterator::reset()
{
	isFinished = false;
	stack.clear();
	treeNode = tree->root;
}

template <typename T>
void Tree<T>::Iterator::remove()
{
	auto temp = treeNode;
	next();
	if(isFinished)
	{
		treeNode = nullptr;
	}

	tree->deleteElement(temp->getValue());
}

template <typename T>
Tree<T> *Tree<T>::Iterator::getTree() const
{
	return tree;
}

template <typename T>
bool Tree<T>::Iterator::isEmpty() const
{
	return isFinished;
}

