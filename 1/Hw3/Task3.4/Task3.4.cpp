#include <stdio.h>
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "library.h"

int main()
{
	Stack *storage = createStack();
	Queue *outputQueue = createQueue();
	if (transformation(storage, outputQueue))
		calculation(storage, outputQueue);
	deleteQueue(outputQueue);
	deleteStack(storage);
}