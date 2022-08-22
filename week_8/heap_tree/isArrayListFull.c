#include "arraylist.h"

int	isArrayListFull(ArrayList *pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}
