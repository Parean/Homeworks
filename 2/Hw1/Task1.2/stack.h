#pragma once

enum KindOfStack
{
	array,
	pointer
};

/**
 * @class Stack
 * Virtual class from which inherit other classes
 * with different implementations of stack
 */
class Stack
{
public:
	virtual void push(float value) = 0;
	virtual int findPositionOfValue(float value) const = 0;
	virtual float pop() = 0;
	virtual float top() = 0;
	virtual bool isEmpty() const = 0;
	virtual int length() const = 0;
	virtual ~Stack() {}
};
