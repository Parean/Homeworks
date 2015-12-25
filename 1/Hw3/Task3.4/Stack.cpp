#include "Stack.h"

StackElement *createStackElement(char value, StackElement *next)
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

void addInStack(char value, Stack *stack)
{
	StackElement *newStackElement = createStackElement(value, stack->head->next);
	stack->head->next = newStackElement;
}

char pop(Stack *stack)
{
	char result = stack->head->next->value;
	StackElement *stackElement = stack->head->next;
	stack->head->next = stack->head->next->next;
	delete stackElement;
	return result;
}

char lookInStack(Stack *stack)
{
	return stack->head->next->value;
}

bool stackIsEmpty(Stack *stack)
{
	return stack->head->next == nullptr;
}

void deleteStack(Stack *stack)
{
	while (!stackIsEmpty(stack))
		pop(stack);
	delete stack->head;
	delete stack;
}