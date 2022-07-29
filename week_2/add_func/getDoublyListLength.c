#include "doublylist.h"

int	getDoublyListLength(DoublyList *pList)
{
	DoublyListNode	*curr;
	int				i = 0;

	curr = &pList->headerNode;
	while (curr->pRLink != &pList->headerNode)
	{
		curr = curr->pRLink;
		i++;
	}
	return (i);
}
