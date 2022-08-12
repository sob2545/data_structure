#include "linkeddeque.h"

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode*	node;

	node = malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	*node = element;
	if (pDeque->pFrontNode == 0 || pDeque->pRearNode == 0)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
		node->pRLink = 0;
		node->pLLink = 0;
	}
	else
	{
		node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = node;
		pDeque->pRearNode = node;
		node->pRLink = 0;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}