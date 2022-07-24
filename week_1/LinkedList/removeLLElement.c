#include "linkedlist.h"
#include <stdlib.h>

int	removeLLElement(LinkedList *pList, int position)
{
	int			curr_elem = pList->currentElementCount;
	ListNode	*remv_node;
	ListNode	*curr_node;

	remv_node = &pList->headerNode;
	if (position <= 0 || curr_elem < position)
		return (FALSE);
	else
	{
		for (int i = 0; i < position; ++i)
		{
			curr_node = remv_node;
			remv_node = remv_node->pLink;
		}
		curr_node->pLink = remv_node->pLink;
		free(remv_node);
		pList->currentElementCount--;
		return (TRUE);
	}
}
