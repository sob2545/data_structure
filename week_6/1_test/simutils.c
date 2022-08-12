#include "simlinkedqueue.h"

LinkedQueue*	createLinkedQueue();

int				enqueueLQ(LinkedQueue* pQueue, QueueNode element);
QueueNode		*dequeueLQ(LinkedQueue* pQueue);
QueueNode		*peekLQ(LinkedQueue* pQueue);

void			deleteLinkedQueue(LinkedQueue* pQueue);
void			clearLinkedQueue(LinkedQueue* pQueue);

int				isLinkedQueueEmpty(LinkedQueue* pQueue);
