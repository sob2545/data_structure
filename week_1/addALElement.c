#include "arraylist.h"

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	if (isArrayListFull(pList) == TRUE && \
		position < 0 && position >= pList->currentElementCount)
		return (FALSE);
	else
	{
		if (position == pList->currentElementCount)
			pList->pElement[position] = element;
		else
		{
			for(int i = pList->currentElementCount - 1; i >= position; i--)
				pList->pElement[i + 1] = pList->pElement[i];
			pList->pElement[position] = element;
		}
		pList->currentElementCount++;
		return (TRUE);
	}
}
