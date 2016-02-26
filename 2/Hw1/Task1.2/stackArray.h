#pragma once
#include "stack.h"

class StackArray : public Stack
{
public:
	StackArray();
	void push(float value);
	float pop();
	float top();
	int findPositionOfValue(float value) const;
	bool isEmpty() const;
	int length() const;
	~StackArray();
private:
	float *stackArray;
	int sizeOfStack;
	void increaseStack();
	int numberOfElements;
};

