#include "linkedlist.h"

ListNode	*getLLElement(LinkedList *pList, int position)
{
	int			curr_elem = pList->currentElementCount;
	ListNode	*curr_node = &pList->headerNode;

	if (curr_elem < position || position <= 0)
		return (0);
	else
	{
		for (int i = 0; i < position; ++i)
			curr_node = curr_node->pLink;
		return (curr_node);
	}
}
