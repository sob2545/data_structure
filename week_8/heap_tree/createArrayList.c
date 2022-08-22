#include "arraylist.h"
#include <stdlib.h>

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*pList;

	pList = calloc(1, sizeof(ArrayList));
	pList->maxElementCount = maxElementCount;
	pList->currentElementCount = 1;
	pList->pElement = calloc(maxElementCount, sizeof(ArrayListNode));
	return (pList);
}
