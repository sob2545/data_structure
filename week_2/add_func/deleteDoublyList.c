#include "doublylist.h"
#include <stdlib.h>

void	deleteDoublyList(DoublyList *pList)
{
	clearDoublyList(pList);
	free(pList);
}
