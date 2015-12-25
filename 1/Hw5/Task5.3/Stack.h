#pragma once

struct StackElement
{
	char value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

StackElement *createStackElement(char value, StackElement *next);
Stack *createStack();
void addInStack(char value, Stack *stack);
char pop(Stack *stack);
char lookInStack(Stack *stack);
bool stackIsEmpty(Stack *stack);
void deleteStack(Stack *stack);
