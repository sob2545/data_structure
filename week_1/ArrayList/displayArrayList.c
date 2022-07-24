#include <stdio.h>
#include "arraylist.h"

void	displayArrayList(ArrayList *pList)
{
	for(int i = 0; i < pList->currentElementCount; i++)
		printf("idx %d : %d\n", i, pList->pElement[i].data);
}
