#include "doublylist.h"
#include <stdlib.h>

DoublyList	*createDoublyList(void)
{
	DoublyList	*list;

	list = calloc(1, sizeof(DoublyList));
	if (list == 0)
		return (0);
	return (list);
}
