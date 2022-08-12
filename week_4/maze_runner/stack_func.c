#include "mapdef.h"
#include <stdlib.h>

LinkedStack	*createLinkedStack()
{
	LinkedStack	*stack;

	stack = calloc(1, sizeof(LinkedStack));
	return (stack);
}

int	pushLS(LinkedStack *pStack, MapPosition element)
{
	MapPosition	*curr;
	MapPosition	*new;

	if (pStack == 0)
		return (0);
	new = malloc(sizeof(MapPosition));
	if (new == 0)
		return (0);
	*new = element;
	new->next = 0;
	curr = pStack->head;
	if (curr == 0)
		pStack->head = new;
	else
	{
		new->next = curr;
		pStack->head = new;
	}
	pStack->cur_len++;
	return (1);
}

MapPosition	*popLS(LinkedStack *pStack)
{
	MapPosition	*pop;

	if (!pStack)
		return (0);
	pop = pStack->head;
	if (pop == 0)
		return (0);
	pStack->head = pop->next;
	pop->next = 0;
	return (pop);
}

MapPosition	*peekLS(LinkedStack *pStack)
{
	MapPosition	*peek;

	peek = pStack->head;
	return (peek);
}

// void	deleteLinkedStack(LinkedStack *pStack)
// {
// 	MapPosition	*curr;
// 	MapPosition	*tmp;

// 	curr = pStack->head;
// 	while (curr)
// 	{
// 		tmp = curr;
// 		curr = curr->next;
// 		tmp->data = 0;
// 		tmp->next = 0;
// 		free (tmp);
// 	}
// 	pStack->cur_len = 0;
// 	pStack->head = 0;
// 	free(pStack);
// }

//int isLinkedStackEmpty(LinkedStack *pStack)
//{
//	if (pStack->head == 0)
//		return (1);
//	else
//		return (0);
//}
