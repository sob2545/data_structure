#include "arraylist.h"
#include <stdlib.h>

void clearArrayList(ArrayList* pList)
{
	pList->maxElementCount = 0;
	pList->currentElementCount = 0;
	free(pList->pElement);
	pList->pElement = 0;
}
