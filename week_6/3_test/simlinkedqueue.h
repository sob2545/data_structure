#ifndef _SIM_LINKED_QUEUE_
#define _SIM_LINKED_QUEUE_

#include <stdlib.h>
#include <stdio.h>

typedef enum status
{
	ARRIVAL = 0,
	START,
	END
}	status;

typedef struct SimCustomer
{
	status	status;
	int		idx;
	int		arrivalTime;
	int		serviceTime;
	int		startTime;
	int		endTime;
}	SimCustomer;

typedef struct QueueNodeType
{
	struct QueueNodeType*	pLink;
	SimCustomer				customer;
}	QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;
	QueueNode* pFrontNode;
	QueueNode* pRearNode;
}	LinkedQueue;

void		insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);
void		processArrival(int currentTime, LinkedQueue *pArrivalQueue, \
			LinkedQueue *pWaitQueue);
QueueNode	*processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
void	processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, \
			int *pServiceUserCount, int *pTotalWaitTime);
void		printSimCustomer(int currentTime, SimCustomer customer);
void		printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void		printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

LinkedQueue*	createLinkedQueue();

int				enqueueLQ(LinkedQueue* pQueue, QueueNode element);
QueueNode		*dequeueLQ(LinkedQueue* pQueue);
QueueNode		*peekLQ(LinkedQueue* pQueue);

void			deleteLinkedQueue(LinkedQueue* pQueue);
void			clearLinkedQueue(LinkedQueue* pQueue);

int				isLinkedQueueEmpty(LinkedQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
