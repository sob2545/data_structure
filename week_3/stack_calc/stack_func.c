#include "linkedstack.h"
#include <stdlib.h>

LinkedStack	*createLinkedStack()
{
	LinkedStack	*stack;

	stack = calloc(1, sizeof(LinkedStack));
	return (stack);
}

int pushLS(LinkedStack* pStack, ExprToken element)
{
	ExprToken* tmp = malloc(sizeof(ExprToken));

	*tmp = element;
	tmp->next = pStack->head;
	pStack->head = tmp;
	pStack->currentTokenCount++;
	return (1);
}

ExprToken	*popLS(LinkedStack *pStack)
{
	ExprToken	*pop;

	if (!pStack)
		return (0);
	pop = pStack->head;
	if (pop == 0)
		return (0);
	pStack->head = pop->next;
	pop->next = 0;
	return (pop);
}

ExprToken	*peekLS(LinkedStack *pStack)
{
	ExprToken	*peek;

	peek = pStack->head;
	return (peek);
}

void	deleteLinkedStack(LinkedStack *pStack)
{
	ExprToken	*curr;
	ExprToken	*tmp;

	curr = pStack->head;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		tmp->value = 0;
		tmp->next = 0;
		free (tmp);
	}
	pStack->currentTokenCount = 0;
	pStack->head = 0;
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
	if (pStack->head == 0)
		return (TRUE);
	else
		return (FALSE);
}
