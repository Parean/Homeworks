#pragma once

#include "treeNode.h"

class Operand : public TreeNode
{
public:
	Operand(char *&string);
	void print() const;

	/// @return value of current node
	int calculate() const;

private:
	int value;
};

