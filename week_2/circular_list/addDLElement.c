#include "doublylist.h"
#include <stdlib.h>

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int				max = pList->currentElementCount;
	int				mid = max / 2;
	DoublyListNode	*curr;
	DoublyListNode	*next;
	DoublyListNode	*new;

	if (position <= 0 || position > max + 1)
		return (FALSE);
	new = calloc(1, sizeof(DoublyListNode));
	*new = element;
	curr = &pList->headerNode;
	if (position <= mid)
	{
		for (int i = 0; i < position - 1; ++i)
			curr = curr->pRLink;
		next = curr->pRLink;
		curr->pRLink = new;
		next->pLLink->pRLink = new;
		next->pLLink = new;
		new->pRLink = next;
		new->pLLink = curr;
	}
	else
	{
		for (int i = max; i > position; --i)
			curr = curr->pLLink;
		next = curr->pLLink;
		curr->pLLink = new;
		next->pRLink->pLLink = new;
		next->pRLink = new;
		new->pLLink = next;
		new->pRLink = curr;
	}
	pList->currentElementCount++;
	return (TRUE);
}
