#include "arraylist.h"
#include <stdlib.h>

void	deleteArrayList(ArrayList* pList)
{
	free(pList->pElement);
	free (pList);
	pList = 0;
}
