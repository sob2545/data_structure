#include "linkedlist.h"
#include <stdlib.h>

LinkedList	*createLinkedList(void)
{
	LinkedList	*list;

	list = calloc(1, sizeof(LinkedList));
	if (list == NULL)
		return (NULL);
	return (list);
}
