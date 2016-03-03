#include "stackPointer.h"

StackPointer::StackPointer():
    numberOfElements(0)
{
	stack = new StackElement(0, nullptr);
}

void StackPointer::push(float value)
{
	StackElement *temp = new StackElement(value, stack->next);
	stack->next = temp;
	numberOfElements++;
}

int StackPointer::findPositionOfValue(float value) const
{
	StackElement *temp = stack->next;
	int position = 1;
	while (temp != nullptr)
	{
		if (temp->value == value)
			return position;
		temp = temp->next;
		position++;
	}
	return -1;
}

float StackPointer::pop()
{
	if (isEmpty())
		return -1;
	StackElement *stackElement = stack->next;
	float result = stackElement->value;
	stack->next = stack->next->next;
	delete stackElement;
	numberOfElements--;
	return result;
}

float StackPointer::top()
{
	if (isEmpty())
		return -1;
	return stack->next->value;
}

bool StackPointer::isEmpty() const
{
	return numberOfElements == 0;
}

int StackPointer::length() const
{
	return numberOfElements;
}

StackPointer::~StackPointer()
{
	while (stack->next != nullptr)
		pop();
	delete stack;
}
