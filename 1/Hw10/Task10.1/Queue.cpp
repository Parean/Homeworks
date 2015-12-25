#include "Queue.h"

QueueElement *createQueueElement(TreeNode *value, int priority, QueueElement *next)
{
	QueueElement *newQueueElement = new QueueElement;
	newQueueElement->priority = priority;
	newQueueElement->value = value;
	newQueueElement->next = next;
	return newQueueElement;
}

Queue *createQueue()
{
	Queue *newQueue = new Queue;
	newQueue->last = createQueueElement(nullptr, 0, nullptr);
	newQueue->first = createQueueElement(nullptr, 0, newQueue->last);
	return newQueue;
}

void addInQueue(TreeNode *value, int priority, Queue *queue)
{
	QueueElement *temp = queue->first;
	while (temp->next != queue->last && priority > temp->next->priority)
		temp = temp->next;
	QueueElement *newQueueElement = createQueueElement(value, priority, temp->next);
	temp->next = newQueueElement;
}

Tree *spliceOfNodes(Queue *queue)
{
	while (queue->first->next->next != queue->last)
	{
		TreeNode *firstNode = queue->first->next->value;
		TreeNode *secondNode = queue->first->next->next->value;
		TreeNode *newTreeNode = createTreeNode('0', firstNode, secondNode);
		int newPriority = queue->first->next->priority + queue->first->next->next->priority;
		QueueElement *firstQueueElement = queue->first->next;
		QueueElement *secondQueueElement = queue->first->next->next;
		queue->first->next = queue->first->next->next->next;
		delete firstQueueElement;
		delete secondQueueElement;
		addInQueue(newTreeNode, newPriority, queue);
	}
	Tree *tree = createTree(queue->first->next->value);
	return tree;
}

TreeNode *getOutOfQueue(Queue *queue)
{
	TreeNode *result = queue->first->next->value;
	QueueElement *queueElement = queue->first->next;
	queue->first->next = queue->first->next->next;
	delete queueElement;
	return result;
}

bool queueIsEmpty(Queue *queue)
{
	return queue->first->next == queue->last;
}

void deleteQueue(Queue *queue)
{
	while (!queueIsEmpty(queue))
		getOutOfQueue(queue);
	delete queue->first;
	delete queue->last;
	delete queue;
}


