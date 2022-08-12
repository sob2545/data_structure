#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkedStack	*reverse_string(LinkedStack *stack)
{
	LinkedStack	*rev;
	StackNode	*curr;
	StackNode	*pop;

	rev = createLinkedStack();
	curr = stack->pTopElement;
	while (curr)
	{
		curr = curr->pLink;
		pop = popLS(stack);
		if (pushLS(rev, *pop) != TRUE)
		{
			deleteLinkedStack(rev);
			break;
		}
		free(pop);
	}
	return (rev);
}

int	main(void)
{
	LinkedStack	*stack;
	LinkedStack	*rev;
	StackNode	*curr;
	StackNode	elem;
	int			i = 0;

	stack = createLinkedStack();
	for (; i < 5; ++i)
	{
		elem.data = 'A' + i;
		pushLS(stack, elem);
	}
	curr = stack->pTopElement;
	i = 0;
	while (curr)
	{
		printf("%didx : %c\n", i++, curr->data);
		curr = curr->pLink;
	}
	printf("----------rev----------\n");
	i = 0;
	rev = reverse_string(stack);
	curr = rev->pTopElement;
	while (curr)
	{
		printf("%didx : %c\n", i++, curr->data);
		curr = curr->pLink;
	}
	deleteLinkedStack(stack);
	deleteLinkedStack(rev);
	system("leaks a.out");
}
