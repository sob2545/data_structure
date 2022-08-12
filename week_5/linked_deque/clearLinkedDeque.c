#include "linkeddeque.h"

void clearLinkedDeque(LinkedDeque* pDeque)
{
	deleteLinkedDeque(pDeque);
    free(pDeque);
}
