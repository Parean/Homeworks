#pragma once

#include "treeNode.h"

class Operator : public TreeNode
{
public:
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

