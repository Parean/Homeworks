#pragma once
#include "stack.h"

class StackPointer:	public Stack
{
public:
	StackPointer();
	void push(float value);
	float pop();
	float top();
	int findPositionOfValue(float value) const;
	bool isEmpty() const;
	int length() const;
	~StackPointer();
private:
	struct StackElement
	{
		float value;
		StackElement *next;
		StackElement(float number, StackElement *nextElement) :
			value(number),
			next(nextElement)
		{}
	};
	StackElement *stack;
	int numberOfElements;
};

