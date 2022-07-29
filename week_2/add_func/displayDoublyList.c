#include "doublylist.h"
#include <stdio.h>

void	displayDoublyList(DoublyList *pList)
{
	DoublyListNode	*curr;
	int				i = 0;

	curr = &pList->headerNode;
	while (curr->pRLink != &pList->headerNode)
	{
		curr = curr->pRLink;
		printf("node%d data : %d\n", ++i, curr->data);
	}
}
