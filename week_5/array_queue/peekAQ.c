#include "arrayqueue.h"

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode*	node;

	if (pQueue->currentElementCount == 0)
		return (FALSE);
	node = &pQueue->pElement[pQueue->front];
	return (node);
}