#include "linkedlist.h"
#include <stdlib.h>

void	deleteLinkedList(LinkedList *pList)
{
	if (pList->currentElementCount <= 0)
		return ;
	else
	{
		clearLinkedList(pList);
		free (pList);
		pList = 0;
	}
}
