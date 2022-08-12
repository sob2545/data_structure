#include "linkeddeque.h"

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	while (!isLinkedDequeEmpty(pDeque))
		free(deleteFrontLD(pDeque));
}


