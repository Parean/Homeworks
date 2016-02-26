#include "stackArray.h"

StackArray::StackArray()
{
	sizeOfStack = 50;
	numberOfElements = 0;
	stackArray = new float[sizeOfStack];
}

void StackArray::push(float value)
{
	stackArray[numberOfElements] = value;
	if (++numberOfElements == sizeOfStack)
		increaseStack();
	return;
}

int StackArray::findPositionOfValue(float value) const
{
	for (int index = 0; index < numberOfElements; index++)
	{
		if (stackArray[index] == value)
			return index;
	}
	return -1;
}

float StackArray::pop()
{
	if (!isEmpty())
		return stackArray[--numberOfElements];
	return -1;
}

float StackArray::top()
{
	if (!isEmpty())
		return stackArray[numberOfElements - 1];
	return -1;
}

int StackArray::length() const
{
	return numberOfElements;
}

bool StackArray::isEmpty() const
{
	return numberOfElements == 0;
}

void StackArray::increaseStack()
{
	sizeOfStack = sizeOfStack * 2;
	float *newStackArray = new float[sizeOfStack];
	for (int i = 0; i < numberOfElements; i++)
		newStackArray[i] = stackArray[i];
	delete[] stackArray;
	stackArray = newStackArray;
	return;
}

StackArray::~StackArray()
{
	delete[] stackArray;
}
