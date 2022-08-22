#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (position < 0 && position > pList->currentElementCount - 1)
		return (FALSE);
	else
		return (pList->pElement + position);
}
