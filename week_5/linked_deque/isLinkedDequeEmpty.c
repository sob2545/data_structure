#include "linkeddeque.h"

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (TRUE);
	if (!pDeque->pFrontNode || !pDeque->pRearNode)
		return (TRUE);
	return (FALSE);
}