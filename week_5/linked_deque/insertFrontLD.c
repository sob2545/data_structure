#include "linkeddeque.h"


int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
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
		node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = node;
		pDeque->pFrontNode = node;
		node->pLLink = 0;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}