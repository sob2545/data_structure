#include "arrayqueue.h"

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode*	node;

	if (pQueue->currentElementCount == 0)
		return (FALSE);
	node = &pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (node);
}