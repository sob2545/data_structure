#include "linkedstack.h"
#include <stdlib.h>

LinkedStack	*createLinkedStack()
{
	LinkedStack	*stack;

	stack = calloc(1, sizeof(LinkedStack));
	return (stack);
}

int	pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*new;

	if (pStack == 0)
		return (FALSE);
	new = malloc(sizeof(StackNode));
	if (new == 0)
		return (FALSE);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode	*popLS(LinkedStack *pStack)
{
	StackNode	*pop;

	pop = pStack->pTopElement;
	if (pop == 0)
		return (0);
	pStack->pTopElement = pop->pLink;
	pop->pLink = 0;
	return (pop);
}

StackNode	*peekLS(LinkedStack *pStack)
{
	StackNode	*peek;

	peek = pStack->pTopElement;
	return (peek);
}

void	deleteLinkedStack(LinkedStack *pStack)
{
	StackNode	*curr;
	StackNode	*tmp;

	curr = pStack->pTopElement;
	while (curr)
	{
		tmp = curr;
		curr = curr->pLink;
		tmp->data = 0;
		free (tmp);
	}
	pStack->currentElementCount = 0;
	pStack->pTopElement = 0;
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
	if (pStack->pTopElement == 0)
		return (TRUE);
	else
		return (FALSE);
}
