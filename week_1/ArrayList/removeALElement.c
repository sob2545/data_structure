#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
	if (position >= 0 && position <= pList->currentElementCount - 1)
	{
		if (position == pList->maxElementCount - 1)
			pList->pElement[position].data = 0;
		else
		{
			for (int i = position; i < pList->currentElementCount - 1; i++)
				pList->pElement[i] = pList->pElement[i + 1];
			pList->pElement[pList->currentElementCount - 1].data = 0;
		}
		pList->currentElementCount--;
		return (TRUE);
	}
	else
		return (FALSE);
}
