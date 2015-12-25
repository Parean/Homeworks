#pragma once

struct StackElement
{
	int value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};



StackElement *createStackElement(int value, StackElement *next);
Stack *createStack();
void addInStack(int value, Stack *stack);
int pop(Stack *stack);
int lookInStack(Stack *stack);
bool stackIsEmpty(Stack *stack);
void deleteStack(Stack *stack);
