#include "linkeddeque.h"

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode*	node;

	if (pDeque->currentElementCount == 0)
		return (FALSE);
	node = pDeque->pRearNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
		pDeque->currentElementCount = 0;
		node->pLLink = 0;
		node->pRLink = 0;
		return (node);
	}
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	node->pLLink = 0;
	pDeque->pRearNode->pRLink = 0;
	pDeque->currentElementCount--;
	return (node);
}