#include "simlinkedqueue.h"

LinkedQueue* createLinkedQueue()
{
	LinkedQueue*	deque;

	deque = malloc(sizeof(LinkedQueue));
	if (!deque)
		return (0);
	return (deque);
}

void clearLinkedQueue(LinkedQueue* pDeque)
{
	deleteLinkedQueue(pDeque);
    free(pDeque);
}

QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	QueueNode*	node;

	if (pQueue->currentElementCount == 0)
		return (FALSE);
	node = pQueue->pFrontNode;
	if (pQueue->currentElementCount == 1)
	{
		pQueue->pFrontNode = 0;
		pQueue->pRearNode = 0;
		pQueue->currentElementCount = 0;
		node->pLink = 0;
		return (node);
	}
	pQueue->pFrontNode = pQueue->pFrontNode->pLink;
	node->pLink = 0;
	pQueue->currentElementCount--;
	return (node);
}

void deleteLinkedQueue(LinkedQueue* pDeque)
{
	while (!isLinkedQueueEmpty(pDeque))
		free(dequeueLQ(pDeque));
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode*	node;

	node = malloc(sizeof(QueueNode));
	if (!node)
		return (FALSE);
	*node = element;
	if (pQueue->pFrontNode == 0 || pQueue->pRearNode == 0)
	{
		pQueue->pFrontNode = node;
		pQueue->pRearNode = node;
		node->pLink = 0;
	}
	else
	{
		pQueue->pRearNode->pLink = node;
		pQueue->pRearNode = node;
		node->pLink = 0;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	if (!pQueue)
		return (TRUE);
	if (!pQueue->pFrontNode || !pQueue->pRearNode)
		return (TRUE);
	return (FALSE);
}

QueueNode		*peekLQ(LinkedQueue* pQueue)
{
	return (pQueue->pFrontNode);
}
