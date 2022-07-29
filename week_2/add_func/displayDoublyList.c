#include "doublylist.h"
#include <stdio.h>
#include <math.h>

static void displayCoefAndDegree(int place, float coef, int degree)
{
    if (degree == 0)
    {
        if (place == 1)
            printf("%.1f ", coef);
        else
            printf("%.1f ", (float)fabs(coef));
    }
    else
    {
		if (coef == 1)
		{
			printf("x^%d ", degree);
			return ;
		}
        if (place == 1)
            printf("%.1fx^%d ", coef, degree);
		else if (degree == 1)
			printf("%.1fx ", coef);
        else 
			printf("%.1fx^%d ", (float)fabs(coef), degree);
    }
}

void displayDoublyList(DoublyList* lst)
{
	DoublyListNode *node;
	int 	i;
	
	i = 1;
	node = lst->headerNode.pRLink;
	while(node && i < lst->currentElementCount + 1)
	{
		displayCoefAndDegree(i, node->coef, node->degree);
		i++;
		node = node->pRLink;
        if (i != lst->currentElementCount + 1) 
            node->coef >= 0 ? printf("+ ") : printf("- ");
	}
	printf("\n");
}