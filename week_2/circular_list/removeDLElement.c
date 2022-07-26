#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

int	removeDLElement(DoublyList *pList, int position)
{
	int				max = pList->currentElementCount;
	int				mid = max / 2;
	DoublyListNode	*curr;

	if (position <= 0 || position > max)
		return (FALSE);
	curr = &pList->headerNode;
	if (position <= mid)
	{
		for (int i = 0; i < position; ++i)
			curr = curr->pRLink;
		curr->pRLink->pLLink = curr->pLLink;
		curr->pLLink->pRLink = curr->pRLink;
		free(curr);
	}
	else
	{
		for (int i = max; i > position - 1; --i)
			curr = curr->pLLink;
		curr->pLLink->pRLink = curr->pRLink;
		curr->pRLink->pLLink = curr->pLLink;
		free(curr);
	}
	pList->currentElementCount--;
	return (TRUE);
}
