#include "linkeddeque.h"
#include <stdlib.h>

LinkedDeque* createLinkedDeque()
{
	LinkedDeque*	deque;

	deque = malloc(sizeof(LinkedDeque));
	if (!deque)
		return (0);
	return (deque);
}