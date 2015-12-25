#pragma once
#include "tree.h"

struct QueueElement
{
	TreeNode *value;
	int priority;
	QueueElement *next;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
};

void addInQueue(TreeNode *value, int priority, Queue *queue);
Queue *createQueue();
char lookInQueue(Queue *queue);
bool queueIsEmpty(Queue *queue);
void deleteQueue(Queue *queue);
TreeNode *getOutOfQueue(Queue *queue);
Tree *spliceOfNodes(Queue *queue);