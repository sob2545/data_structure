#include "arraylist.h"
#include "stdio.h"

int	main(void)
{
	ArrayList		*list;
	ArrayListNode	node;

	list = createArrayList(15);
	for (int i = 1; i <= 14; ++i)
	{
		node.data = i;
		insertCurIndex(list, node);
	}
	printf("================\n");
	displayArrayList(list);
	printf("================\n");
	deleteCurIndex(list, 3);
	displayArrayList(list);
	node.data = 30;
	printf("================\n");
	insertCurIndex(list, node);
	displayArrayList(list);
}
