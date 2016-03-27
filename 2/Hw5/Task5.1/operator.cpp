#include "operator.h"
#include "operand.h"

Operator::Operator(char *&string)
{
	string++;
	while(*string == ' ')
		string++;
	value = *string++;
	left = getNewTreeNode(string);
	right = getNewTreeNode(string);
	string++;
}

TreeNode *Operator::getNewTreeNode(char *&string)
{
	while(*string == ' ')
		string++;
	if (*string == '(')
		return new Operator(string);
	if (isdigit(*string))
		return new Operand(string);
}

void Operator::print() const
{
	cout << '(' << value << ' ';
	left->print();
	cout << ' ';
	right->print();
	std::cout << ')';
}

int Operator::calculate() const
{
	switch(value)
	{
	case '*':
		return left->calculate() * right->calculate();
	case '/':
		return left->calculate() / right->calculate();
	case '+':
		return left->calculate() + right->calculate();
	case '-':
		return left->calculate() - right->calculate();
	}
}

Operator::~Operator()
{
	delete left;
	delete right;
}
