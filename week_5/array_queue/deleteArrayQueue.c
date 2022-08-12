#include "arrayqueue.h"

 void deleteArrayQueue(ArrayQueue* pQueue)
 {
	free(pQueue->pElement);
	pQueue->pElement = 0;
	free(pQueue);
 }