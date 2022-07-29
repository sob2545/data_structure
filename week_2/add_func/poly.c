#include "./doublylist.h"
#include <stdlib.h>
#include <stdio.h>

int get_pos(DoublyList* poly, int curr_deg)
{
	DoublyListNode  *curr = &poly->headerNode;
    int             pos;

    pos = 1;
    while (curr->pRLink != &poly->headerNode)
    {
		if (getDoublyListLength(poly) == 0)
			return (pos);
		curr = curr->pRLink;
        if (curr_deg > curr->degree)
            break ;
        else if (curr_deg == curr->degree)
        {
            pos *= -1;
            break ;
        }
		pos++;
    }
	return (pos);
}

void	addPolyNode(DoublyList* poly, float coef, int degree)
{
	DoublyListNode  new;
	DoublyListNode*	curr;
    int             pos;

	new.coef = coef;
	new.degree = degree;
	curr = &poly->headerNode;
	// position 받아와야함 
	pos = get_pos(poly, degree);
	for (int i = 0; i < abs(pos); i++)
		curr = curr->pRLink;
	if (pos < 0)
		curr->coef += coef;
	else
	{
		addDLElement(poly, pos, new);
		//printf("===================\n");
		//printf("coef : %.1f || degree : %d || pos : |%d|\n", coef, degree, pos);
		//displayDoublyList(poly);
		//printf("===================\n");
	}

	curr = poly->headerNode.pRLink;
	pos = 1;
	while (curr->pRLink != &poly->headerNode)
	{
		if (curr->coef == 0)
		{
			removeDLElement(poly, pos);
			break ;
		}
		pos++;
		curr = curr->pRLink;
	}
}

int main()
{
	DoublyList*	a =	createDoublyList();
	DoublyList*	b = createDoublyList();
	DoublyListNode* curr;

	addPolyNode(a, -2.5, 5);
	addPolyNode(a, 10, 2);
	addPolyNode(a, 3.7, 3);
	addPolyNode(a, -1, 1);
	addPolyNode(a, 12, 0);
	//displayDoublyList(a);
	
	addPolyNode(b, -3, 7);
	addPolyNode(b, 1, 5);
	addPolyNode(b, -10, 2);
	addPolyNode(b, 10, 1);
	addPolyNode(b, 10, 0);
	//displayDoublyList(b);

	curr = b->headerNode.pRLink;
	while (curr != &b->headerNode)
	{
		addPolyNode(a, curr->coef, curr->degree);
		curr = curr->pRLink;
	}
	displayDoublyList(a);

	//system("leaks a.out");
	//a = -2.5x^5 + 3.7x^3 + 10x^2 - x + 12;
	//b = -3x^7 + x^5 + 4x^2 + 10x^1 + 10;
	// a + b = -3x^7 -1.5x^5 + 3.7x^3 + 9x + 22
	// 한 LinkedList에 element추가
	
	// 두 다항식 더하기	
}