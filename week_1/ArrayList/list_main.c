#include "arraylist.h"
#include <stdio.h>

int	main(void)
{
	ArrayList		*list;
	ArrayListNode	node;

	/* Create Array */
	printf("----------------------\n");
	printf("   Array List Test    \n");
	printf("----------------------\n");
	list = createArrayList(10);
	
	/* Add node */
	for (int i = 0; i < 10; ++i)
	{
		node.data = i + 10;
		addALElement(list, i, node);
	}
	displayArrayList(list);
	printf("Array len is : %d\n", getArrayListLength(list));
	if (isArrayListFull(list) == TRUE)
		printf("Array is full\n");
	else
		printf("Array is not full\n");
	printf("----------------------\n");
	printf("remvoe idx = 3\n");
	if (removeALElement(list, 3) == TRUE)
		displayArrayList(list);
	else
		printf("remove fail\n");
	printf("----------------------\n");
	node.data = 42;
	printf("add idx = 2\n");
	printf("add node val = 42\n");
	if (isArrayListFull(list) == FALSE)
		addALElement(list, 2, node);
	displayArrayList(list);
	printf("----------------------\n");
	deleteArrayList(list);
	printf("Array deleted\n");
}
