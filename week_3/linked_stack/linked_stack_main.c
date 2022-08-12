#include "linkedstack.h"
#include <stdio.h>

int	main(void)
{
	LinkedStack	*stack;
	StackNode	*curr;
	StackNode	elem;
	int			i = 0;

	stack = createLinkedStack();
	printf("--------push---------\n");
	for (; i < 5; ++i)
	{
		elem.data = 'A' + i;
		if (pushLS(stack, elem) == 0)
			deleteLinkedStack(stack);
	}
	curr = stack->pTopElement;
	while (curr)
	{
		printf("%c\n", curr->data);
		curr = curr->pLink;
	}
	printf("---------pop----------\n");
	curr = popLS(stack);
	printf("pop node is %c\n", curr->data);
	curr = stack->pTopElement;
	while (curr)
	{
		printf("%c\n", curr->data);
		curr = curr->pLink;
	}
	printf("---------peek----------\n");
	curr = peekLS(stack);
	printf("peek is %c\n", curr->data);
	curr = stack->pTopElement;
	while (curr)
	{
		printf("%c\n", curr->data);
		curr = curr->pLink;
	}
	printf("---------delete----------\n");
	deleteLinkedStack(stack);
	isLinkedStackEmpty(stack);
}
