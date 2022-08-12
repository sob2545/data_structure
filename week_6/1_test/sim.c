#include "simlinkedqueue.h"

void		insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	QueueNode	node;

	node.customer.status = ARRIVAL;
	node.customer.arrivalTime = arrivalTime;
	node.customer.serviceTime = processTime;
	node.customer.startTime = -1;
	node.customer.endTime = -1;
	node.pLink = NULL;
	enqueueLQ(pQueue, node);
}

void		processArrival(int currentTime, LinkedQueue *pArrivalQueue, \
		LinkedQueue *pWaitQueue)
{
	QueueNode	*node;

	node = peekLQ(pArrivalQueue);
	if (node && currentTime >= node->customer.arrivalTime)
	{
		node = dequeueLQ(pArrivalQueue);
		enqueueLQ(pWaitQueue, *node);
		free(node);
	}
}

QueueNode	*processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode	*node;

	node = dequeueLQ(pWaitQueue);
	if (node)
	{
		node->customer.status = START;
		node->customer.startTime = currentTime;
		node->customer.endTime = currentTime + node->customer.serviceTime;
	}
	return (node);
}

void	processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, \
		int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode == 0)
		return ;
	if (currentTime == pServiceNode->customer.endTime)
	{
		(*pServiceUserCount)++;
		*pTotalWaitTime += (pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime);
		pServiceNode->customer.status = END;
	}
}

void		printSimCustomer(int currentTime, SimCustomer customer)
{
	if (customer.arrivalTime > currentTime)
		printf("BEFORE ARRIVAL\n");
	else if (customer.startTime > currentTime)
		printf("ARRIVAL\n");
	else if (customer.endTime > currentTime)
		printf("START\n");
	else
		printf("END\n");
}

void		printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode	*curr;

	curr = pWaitQueue->pFrontNode;
	while (curr)
	{
		printSimCustomer(currentTime, curr->customer);
		curr = curr->pLink;
	}
}

void		printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printWaitQueueStatus(10000, pWaitQueue);
	printf("Total Service User: %d\n", serviceUserCount);
	printf("Total Wait Time: %d\n", totalWaitTime);
}
