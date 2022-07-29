#include "doublylist.h"
#include <stdlib.h>

void	clearDoublyList(DoublyList *pList)
{
	DoublyListNode	*curr;
	DoublyListNode	*tmp;

	curr = &pList->headerNode;
	curr = curr->pRLink;
	for (int i = 0; i < pList->currentElementCount; ++i)
	{
		tmp = curr;
		curr = curr->pRLink;
		tmp->pRLink = 0;
		tmp->pLLink = 0;
		free(tmp);
	}
}
