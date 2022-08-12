#include "arrayqueue.h"
#include <stdlib.h>

ArrayQueue*	createArrayQueue(int maxElementCount)
{
	ArrayQueue*	arr;
	ArrayQueueNode*	node;

	arr = malloc(sizeof(ArrayQueue));
	if (!arr)
		return (0);
	node = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!node)
	{
		free(arr);
		return (0);
	}
	arr->pElement = node;
	arr->maxElementCount = maxElementCount;
	return (arr);
}
