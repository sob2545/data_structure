#include "linkedlist.h"
#include <stdio.h>

int	main(void)
{
	LinkedList	*list;
	ListNode	node_1;
	ListNode	node_2;
	ListNode	node_3;
	ListNode	*curr;
	ListNode	*check;

	list = createLinkedList();
	node_1.data = 1;
	node_2.data = 3;
	node_3.data = 5;
	if (addLLElement(list, 1, node_1) == FALSE)
	{
		deleteLinkedList(list);
		return (0);
	}
	if (addLLElement(list, 2, node_2) == FALSE)
	{
		deleteLinkedList(list);
		return (0);
	}
	if (addLLElement(list, 3, node_3) == FALSE)
	{
		deleteLinkedList(list);
		return (0);
	}

	curr = &list->headerNode;
	for (int i = 1; i <= 3; ++i)
	{
		curr = curr->pLink;
		printf("idx%d : %d\n", i, curr->data);
	}
	printf("------------------------\n");
	check = getLLElement(list, 2);
	printf("%dpos : %d\n", 2, check->data);
	printf("len : %d\n", getLinkedListLength(list));

	printf("------------------------\n");
	removeLLElement(list, 1);
	printf("delete node is %d\n", 1);
	curr = &list->headerNode;
	for (int i = 1; i <= 2; ++i)
	{
		curr = curr->pLink;
		printf("idx%d : %d\n", i, curr->data);
	}
	printf("len : %d\n", getLinkedListLength(list));
	printf("------------------------\n");
	deleteLinkedList(list);
	printf("Linked list deleted");
}
