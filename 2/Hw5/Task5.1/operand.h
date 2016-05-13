#pragma once

#include "treeNode.h"

/**
 * @class Operand
 * Class represent the realization of a node of the tree
 * which contains an operand
 */
class Operand : public TreeNode
{
public:
	/**
	 * The constructor takes a string as an input and removes the value from it
	 * The string is passed by reference, because the algorithm of parse expression
	 * is recursive, and to enable in the next stage to read a new value, you must
	 * move the pointer inside the string at each stage and pass it to the next call
	 * already changed
	 */
	Operand(char *&string);
	void print() const;

	/// @return value of current node
	int calculate() const;

private:
	int value = 0;
};

