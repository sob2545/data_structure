#include "linkedlist.h"
#include <stdlib.h>

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*curr_node = &pList->headerNode;
	ListNode	*tmp = 0;

	if (pList->currentElementCount <= 0)
		return ;
	else
	{
		curr_node = curr_node->pLink;
		while (curr_node)
		{
			tmp = curr_node;
			curr_node = curr_node->pLink;
			free (tmp);
		}
		pList->currentElementCount = 0;
	}
}
