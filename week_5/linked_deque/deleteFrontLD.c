#include "linkeddeque.h"

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode*	node;

	if (pDeque->currentElementCount == 0)
		return (FALSE);
	node = pDeque->pFrontNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
		pDeque->currentElementCount = 0;
		node->pLLink = 0;
		node->pRLink = 0;
		return (node);
	}
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	node->pRLink = 0;
	pDeque->pFrontNode->pLLink = 0;
	pDeque->currentElementCount--;
	return (node);
}