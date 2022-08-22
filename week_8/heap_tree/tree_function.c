#include "arraylist.h"
#include <math.h>

void	insertCurIndex(ArrayList *list, ArrayListNode node)
{
	int	tmp;
	int	n;
	int	x = 0;

	n = 1;
	while (n < list->currentElementCount)
	{
		n = pow(2, x);
		x++;
	}
	if (n != 1)
		n /= 2;
	while (n <= list->currentElementCount)
	{
		if (list->pElement[n].data == 0)
			break ;
		n++;
	}
	list->pElement[n].data = node.data;
	list->currentElementCount++;
	while (n != 1)
	{
		tmp = list->pElement[n].data;
		if (tmp > list->pElement[n / 2].data)
		{
			list->pElement[n].data = list->pElement[n / 2].data;
			list->pElement[n / 2].data = tmp;
		}
		else
			break ;
		n /= 2;
	}
}

void	deleteCurIndex(ArrayList *list, int i)
{
	int cur = list->currentElementCount;

	list->currentElementCount--;
	while (i < cur)
	{
		if (list->pElement[i * 2].data > list->pElement[i * 2 + 1].data)
		{
			list->pElement[i].data = list->pElement[i * 2].data;
			list->pElement[i * 2].data = 0;
			i *= 2;
		}
		else if (list->pElement[i * 2].data < list->pElement[i * 2 + 1].data)
		{
			list->pElement[i].data = list->pElement[i * 2 + 1].data;
			list->pElement[i * 2 + 1].data = 0;
			i = i * 2 + 1;
		}
		else
			break ;
	}
}
