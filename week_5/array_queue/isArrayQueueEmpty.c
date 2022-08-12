#include "arrayqueue.h"

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if ((pQueue->currentElementCount == 0
	|| pQueue->front == pQueue->rear))
		return (TRUE);
	return (FALSE);
}