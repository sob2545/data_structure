#include "linkedlist.h"
#include <stdlib.h>

int	addLLElement(LinkedList *pList, int position, ListNode element)
{
	int			curr_elem = pList->currentElementCount;
	ListNode	*curr_node;
	ListNode	*next_node;
	ListNode	*new_node;

	curr_node = &(pList->headerNode);
	if (curr_elem + 1 < position || position <= 0)
		return (FALSE);
	else
	{
		new_node = calloc(1, sizeof(ListNode));
		if (new_node == 0)
			return (FALSE);
		new_node->data = element.data;
		for (int i = 0; i < position - 1; ++i)
			curr_node = curr_node->pLink;
		if (curr_elem == position - 1)
		{
			curr_node->pLink = new_node;
			curr_node->pLink->pLink = 0;
		}
		else
		{
			next_node = curr_node->pLink;
			curr_node->pLink = new_node;
			curr_node->pLink->pLink = next_node;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
}
