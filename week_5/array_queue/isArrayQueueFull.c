#include "arrayqueue.h"

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue->currentElementCount == pQueue->maxElementCount 
	|| ((pQueue->rear + 1) % pQueue->maxElementCount) == pQueue->front)
		return (TRUE);
	return (FALSE);
}