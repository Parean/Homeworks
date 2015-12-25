#pragma once

struct QueueElement
{
	char value;
	QueueElement *next;
};

struct Queue
{
	QueueElement *first;
	QueueElement *last;
};

QueueElement *createQueueElement(char value, QueueElement *next);
Queue *createQueue();
void addInQueue(char value, Queue *queue);
char getOutOfQueue(Queue *queue);
char lookInQueue(Queue *queue);
bool queueIsEmpty(Queue *queue);
void deleteQueue(Queue *queue);