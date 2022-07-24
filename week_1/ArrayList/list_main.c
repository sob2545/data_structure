#include "arraylist.h"
#include <stdio.h>

int	main(void)
{
	ArrayList		*list;
	ArrayListNode	node;

	list = createArrayList(10);
	
	node.data = 42;
	addALElement(list, 0, node);
	displayArrayList(list);
	
}
