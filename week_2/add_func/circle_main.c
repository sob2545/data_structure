#include <stdio.h>
#include "doublylist.h"

int	main(void)
{
	DoublyList	*list;
	DoublyListNode	node;
	DoublyListNode	*curr;
	int				i = 1;

	list = createDoublyList();
	printf("--------------------\n");
	printf("    circular list   \n");
	printf("--------------------\n");
	for (; i < 7; ++i)
	{
		node.data = i;
		if (addDLElement(list, i, node) == 0)
			deleteDoublyList(list);
	}
	printf("list size = %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	printf("--------------------\n");
	printf("add node in idx 2\n");
	node.data = 42;
	if (addDLElement(list, 2, node) == 0)
		deleteDoublyList(list);
	printf("list size = %d\n", getDoublyListLength(list));
	displayDoublyList(list);

	curr = &list->headerNode;
	while (curr->pRLink != &list->headerNode)
	{
		curr = curr->pRLink;
		printf("CUR : %d\nCUR L : %d\nCUR R : %d\n", curr->data, curr->pLLink->data, curr->pRLink->data);
		printf("\n");
	}

	curr = &list->headerNode;
	printf("HEAD NODE\n");
	printf("CUR : %d\nCUR L : %d\nCUR R : %d\n", curr->data, curr->pLLink->data, curr->pRLink->data);

	printf("--------------------\n");
	printf("delete node 1\n");
	removeDLElement(list, 1);
	printf("list size = %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	curr = &list->headerNode;
	while (curr->pRLink != &list->headerNode)
	{
		curr = curr->pRLink;
		printf("CUR : %d\nCUR L : %d\nCUR R : %d\n", curr->data, curr->pLLink->data, curr->pRLink->data);
		printf("\n");
	}

	printf("\ndelete node 4\n");
	curr = &list->headerNode;
	removeDLElement(list, 4);
	curr = &list->headerNode;
	while (curr->pRLink != &list->headerNode)
	{
		curr = curr->pRLink;
		printf("CUR : %d\nCUR L : %d\nCUR R : %d\n", curr->data, curr->pLLink->data, curr->pRLink->data);
		printf("\n");
	}

	printf("list size = %d\n", getDoublyListLength(list));
	displayDoublyList(list);
	printf("--------------------\n");
	deleteDoublyList(list);
	printf("delete list\n");
}
