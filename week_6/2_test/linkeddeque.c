/*#include "linkeddeque.h"
#include "stdlib.h"
#include "stdio.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *new;

	new = malloc(sizeof(LinkedDeque));
	return (new);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	new = (DequeNode *)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	//아무것도 없을땐 덱의 프런트노드와 리어노드 모두 추가된 노드를 가리키도록 해야한다.
	if (pDeque->currentElementCount == 0)
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		new->pRLink = pDeque->pFrontNode;
		new->pRLink->pLLink = new;
		pDeque->pFrontNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;

	new = (DequeNode *)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	if (pDeque->currentElementCount == 0)
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}	
	else
	{
		new->pLLink = pDeque->pRearNode;  
		new->pLLink->pRLink = new;
		pDeque->pRearNode= new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

static DequeNode* deleteLastNode(LinkedDeque *pDeque) {
	DequeNode *last = pDeque->pRearNode;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	pDeque->currentElementCount = 0;
	last->pLLink = NULL;
	last->pRLink = NULL;
	return last;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) 
{
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	if (pDeque->currentElementCount == 1) {
		return deleteLastNode(pDeque);
	}
	DequeNode* pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	pReturn->pRLink = NULL;
	return pReturn;
}


DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque->currentElementCount == 0)
		return (FALSE);
	tmp = pDeque->pFrontNode;
	pDeque->pFrontNode = tmp->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	free(tmp);
	pDeque->currentElementCount--;
	return (pDeque->pFrontNode);
}



DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	if (pDeque->currentElementCount == 0)
		return (NULL);
	tmp = pDeque->pRearNode;
	pDeque->pRearNode = tmp->pLLink;
	pDeque->pRearNode->pRLink = NULL;
	free(tmp);
	pDeque->currentElementCount--;
	return (pDeque->pRearNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *tmp;

	tmp = pDeque->pFrontNode;
	while (pDeque->currentElementCount--)
	{
		free(tmp);
		tmp = tmp->pRLink;
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	return (pDeque->currentElementCount == 0);
}

void	displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*tmp;
	int			i = 0;

	tmp = pDeque->pFrontNode;
	printf("--------------------------------\n");
	printf("CurrentElementCount : %d\n", pDeque->currentElementCount);
	while (i < pDeque->currentElementCount)
	{
		printf("-----[%c]-----  idx:%d\n", tmp->data, i);
		tmp = tmp->pRLink;
		i++;
	}
}
*/
#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

LinkedDeque* createLinkedDeque() {
	return (calloc(1, sizeof(LinkedDeque)));
}

static int emptyDequeInsertion(LinkedDeque* pDeque, DequeNode element) {
	DequeNode* new = calloc(1, sizeof(DequeNode));
	if (new == NULL) {
		return FALSE;
	}
	new->data = element.data;
	pDeque->pFrontNode = new;
	pDeque->pRearNode = new;
	pDeque->currentElementCount = 1;
	return TRUE;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element) {
	if (isLinkedDequeEmpty(pDeque)) {
		return emptyDequeInsertion(pDeque, element);
	}
	DequeNode *new = calloc(1, sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pRLink = pDeque->pFrontNode;
	pDeque->pFrontNode->pLLink = new;
	pDeque->pFrontNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element) {
	if (isLinkedDequeEmpty(pDeque)) {
		return emptyDequeInsertion(pDeque, element);
	}
	DequeNode *new = calloc(1, sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	new->pLLink = pDeque->pRearNode;
	pDeque->pRearNode->pRLink = new;
	pDeque->pRearNode = new;
	pDeque->currentElementCount++;
	return (TRUE);
}

static DequeNode* deleteLastNode(LinkedDeque *pDeque) {
	DequeNode *last = pDeque->pRearNode;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	pDeque->currentElementCount = 0;
	last->pLLink = NULL;
	last->pRLink = NULL;
	return last;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	if (pDeque->currentElementCount == 1) {
		return deleteLastNode(pDeque);
	}
	DequeNode* pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	pReturn->pRLink = NULL;
	return pReturn;
}

DequeNode* deleteRearLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	if (pDeque->currentElementCount == 1) {
		return deleteLastNode(pDeque);
	}
	DequeNode* pReturn = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	pReturn->pLLink = NULL;
	return pReturn;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	return pDeque->pFrontNode;
}

DequeNode* peekRearLD(LinkedDeque* pDeque) {
	if (isLinkedDequeEmpty(pDeque)) {
		return NULL;
	}
	return pDeque->pRearNode;
}

void deleteLinkedDeque(LinkedDeque* pDeque) {
	while (isLinkedDequeEmpty(pDeque) == FALSE) {
		DequeNode *node = deleteFrontLD(pDeque);
		free(node);
		node = NULL;
	}
	free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque) {
	return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque) {
	if (pDeque->currentElementCount == 0) {
		return TRUE;
	}
	return FALSE;
}


void	displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*tmp;
	int			i = 0;

	tmp = pDeque->pFrontNode;
	printf("--------------------------------\n");
	printf("CurrentElementCount : %d\n", pDeque->currentElementCount);
	while (i < pDeque->currentElementCount)
	{
		printf("-----[%d][%d][%d][%d]]<%d>-----  idx:%d\n", tmp->data.arrivalTime, tmp->data.serviceTime, tmp->data.startTime, tmp->data.endTime, tmp->data.idx, i);
		tmp = tmp->pRLink;
		i++;
	}
}
