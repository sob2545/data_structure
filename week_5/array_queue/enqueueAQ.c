#include "arrayqueue.h"

int	enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (FALSE);
	pQueue->pElement[pQueue->rear] = element;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount++;
	return (TRUE);
}