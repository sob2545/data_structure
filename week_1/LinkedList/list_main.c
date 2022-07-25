#include "linkedlist.h"
#include <stdio.h>

int	main(void)
{
	LinkedList	*list;
	ListNode	node;
	ListNode	*curr;
	ListNode	*check;

	list = createLinkedList();
	printf("------------------------\n");
	printf("   Linked List Test   \n");
	printf("------------------------\n");
	for (int i = 1; i <= 3; ++i)
	{
		node.data = i;
		if (addLLElement(list, i, node) == FALSE)
		{
			deleteLinkedList(list);
			return (0);
		}
	}
	curr = &list->headerNode;
	for (int i = 1; i <= 3; ++i)
	{
		curr = curr->pLink;
		printf("idx%d : %d\n", i, curr->data);
	}
	printf("------------------------\n");
	check = getLLElement(list, 2);
	printf("pos%d : %d\n", 2, check->data);
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
	printf("Linked list deleted\n");
}
