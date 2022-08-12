#include "linkedstack.h"
#include <stdlib.h>

// LinkedList로 먼저 만들기
LinkedStack* createLinkedStack()
{
	return (malloc(sizeof(LinkedStack*)));
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode* tmp = malloc(sizeof(StackNode));

	tmp->data = element.data;
	tmp->pLink = pStack->pTopElement;
	pStack->pTopElement = tmp;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* tmp = malloc(sizeof(StackNode));
	StackNode* curr;

	if (pStack->pTopElement == NULL)
	{
		printf("\n==== STACK IS EMPTY!!====\n\n");
		return (FALSE);
	}
	tmp->data = pStack->pTopElement->data;
	curr = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	free(curr);
	pStack->currentElementCount--;
	return (tmp);
}

StackNode* peekLS(LinkedStack* pStack)
{
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{	
	StackNode *tmp = pStack->pTopElement;

	while (tmp->pLink != NULL)
	{	
		tmp = tmp->pLink;
		free(tmp);
	}
	free(pStack->pTopElement);
	free(pStack);
}

//int isLinkedStackFull(LinkedStack* pStack)
//{

//}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}
