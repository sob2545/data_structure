#include "arraylist.h"
#include <stdlib.h>

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*pList;

	pList = malloc(sizeof(ArrayList));
	pList->maxElementCount = maxElementCount;
	pList->currentElementCount = 0;
	pList->pElement = calloc(maxElementCount, sizeof(ArrayListNode));
	return (pList);
}
