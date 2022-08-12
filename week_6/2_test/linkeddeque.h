#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int idx;
	int arrivalTime; // 도착 시각.
	int serviceTime; // 서비스 시간.
	int startTime; // 시작 시각.
	int endTime; // 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

typedef struct DequeNodeType
{
	SimCustomer data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;		
} LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);
void	displayLinkedDeque(LinkedDeque* pDeque);


#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
