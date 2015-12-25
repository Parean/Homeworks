#include "stack.h"
#include <stdio.h>

StackElement *createStackElement(int value, StackElement *next)
{
	StackElement *newStackElement = new StackElement;
	newStackElement->value = value;
	newStackElement->next = next;
	return newStackElement;
}

Stack *createStack()
{
	Stack *newStack = new Stack;
	newStack->head = createStackElement(0, nullptr);
	return newStack;
}

void addInStack(int value, Stack *stack)
{
	StackElement *newStackElement = createStackElement(value, stack->head->next);
	stack->head->next = newStackElement;
}

int pop(Stack *stack)
{
	int result = stack->head->next->value;
	StackElement *stackElement = stack->head->next;
	stack->head->next = stack->head->next->next;
	delete stackElement;
	return result;
}

int lookInStack(Stack *stack)
{
	return stack->head->next->value;
}

bool isEmpty(Stack *stack)
{
	return stack->head->next == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!isEmpty(stack))
		pop(stack);
	delete stack->head;
	delete stack;
}
