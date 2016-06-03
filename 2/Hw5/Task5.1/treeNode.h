#pragma once

#include <iostream>

using namespace std;

/**
 * @class TreeNode
 * Virtual class, from which there inherited two classes
 * that represent the realization of operators and operands
 */
class TreeNode
{
public:
	virtual void print() const = 0;

	/// Function for calculating arithmetic expressions in the parse tree
	virtual int calculate() const = 0;
	virtual ~TreeNode() {}

protected:
	TreeNode *left;
	TreeNode *right;


};

