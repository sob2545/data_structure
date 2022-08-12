#include "linkeddeque.h"

void print_lst(LinkedDeque *lst)
{
	DequeNode* curr;

	curr = lst->pFrontNode;
	printf("======[lst curent : %d]=========\n", lst->currentElementCount);
	while(curr)
	{
		printf("element : |%c|\n", curr->data);
		curr = curr->pRLink;
	}
	printf("==========================\n");
}

int main()
{
	LinkedDeque	*link;
	DequeNode	*curr;
	DequeNode	tmp;

	link = createLinkedDeque();
	for (int i = 0; i < 4; ++i)
	{
		tmp.data = i + 'a';
		insertFrontLD(link, tmp);
	}
	for (int i = 0; i < 4; ++i)
	{
		tmp.data = i + 'A';
		insertRearLD(link, tmp);
	}
	curr = link->pFrontNode;
	printf("-------- before delete ---------\n");
	print_lst(link);
	curr = deleteFrontLD(link);
	printf("del front : %c\n", curr->data);
	free(curr);
	curr = deleteRearLD(link);
	printf("del rear : %c\n", curr->data);
	free(curr);
	curr = link->pFrontNode;
	printf("------- after delete -------\n");
	print_lst(link);
	printf("Empty check : %s\n", isLinkedDequeEmpty(link) ? "EMPTY" : "NOT EMPTY");
	deleteLinkedDeque(link);
	printf("------- delete list --------\n");
	printf("Empty check : %s\n", isLinkedDequeEmpty(link) ? "EMPTY" : "NOT EMPTY");
	for (int i = 0; i < 4; ++i)
	{
		tmp.data = i + '0';
		insertFrontLD(link, tmp);
	}
	print_lst(link);
}


