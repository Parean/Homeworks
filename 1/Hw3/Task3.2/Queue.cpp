#include "Queue.h"

QueueElement *createQueueElement(char value, QueueElement *next)
{
	QueueElement *newQueueElement = new QueueElement;
	newQueueElement->value = value;
	newQueueElement->next = next;
	return newQueueElement;
}

Queue *createQueue()
{
	Queue *newQueue = new Queue;
	newQueue->last = createQueueElement(0, nullptr);
	newQueue->first = createQueueElement(0, newQueue->last);
	return newQueue;
}

void addInQueue(char value, Queue *queue)
{
	QueueElement *temp = queue->first;
	while (temp->next != queue->last)
	{
		temp = temp->next;
	}
	QueueElement *newQueueElement = createQueueElement(value, queue->last);
	temp->next = newQueueElement;
}

char getOutOfQueue(Queue *queue)
{
	char result = queue->first->next->value;
	QueueElement *queueElement = queue->first->next;
	queue->first->next = queue->first->next->next;
	delete queueElement;
	return result;
}

char lookInQueue(Queue *queue)
{
	return queue->first->next->value;
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


