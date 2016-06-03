#pragma once

#include "treeNode.h"

/**
 * @class Operator
 * Class represent the realization of a node of the tree
 * which contains an operator
 */
class Operator : public TreeNode
{
public:
	/**
	 * The constructor takes a string as an input and removes the value from it
	 * The string is passed by reference, because the algorithm of parse expression
	 * is recursive, and to enable in the next stage to read a new value, you must
	 * move the pointer inside the string at each stage and pass it to the next call
	 * already changed
	 */
	Operator(char *&string);
	void print() const;

	/**
	 * @return the value of an expression of the parse tree
	 * with root at the current node
	 */
	int calculate() const;
	TreeNode *getNewTreeNode(char *&string);
	~Operator();

private:
	char value;

};

