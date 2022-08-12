#include "linkedstack.h"
#include <stdlib.h>

void	print_stack(LinkedStack* pStack)
{
	int cnt; 
	StackNode* curr;

	printf("\n\n-----------------------------\n");
	printf("----- current size : %d------\n", pStack->currentElementCount);
	printf("-----------------------------\n");

	cnt = pStack->currentElementCount;
	curr = pStack->pTopElement;
	while (cnt)
	{
		if (cnt == pStack->currentElementCount)
			printf("|       %c      |   <========= TOP\n", curr->data);
		else
			printf("|       %c      |\n", curr->data);
		curr = curr->pLink;
		cnt--;
	}	
}

int main()
{
	LinkedStack* a = createLinkedStack();
	StackNode* tmp;
	StackNode* tmp2;

	pushLS(a, (StackNode){'f', 0});
	pushLS(a, (StackNode){'e', 0});
	pushLS(a, (StackNode){'d', 0});
	pushLS(a, (StackNode){'a', 0});

	tmp = popLS(a);
	tmp2 = peekLS(a);
	printf("|%c|\n", tmp->data);
	printf("|%c|\n", tmp2->data);
	
	free(tmp);
	print_stack(a);
	deleteLinkedStack(a);
	//print_stack(a);

	system("leaks a.out");
}