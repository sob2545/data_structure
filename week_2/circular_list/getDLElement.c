#include "doublylist.h"

DoublyListNode	*getDLElement(DoublyList *pList, int position)
{
	DoublyListNode	*curr;
	int				max = pList->currentElementCount;
	int				mid = max / 2;

	curr = &pList->headerNode;
	if (position <= 0 || position > max)
		return (FALSE);
	if (position <= mid)
	{
		for (int i = 0; i < position; ++i)
			curr = curr->pRLink;
		return (curr);
	}
	else
	{
		for (int i = max; i > position - 1; --i)
			curr = curr->pLLink;
		return (curr);
	}
}
