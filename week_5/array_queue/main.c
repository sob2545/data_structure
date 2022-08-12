#include "arrayqueue.h"

void print_arr(ArrayQueue *arr)
{
	printf("==========================\n");
	printf("This array has %d volume\n", arr->maxElementCount);
	for (int i = 0; i < arr->maxElementCount; i++)
		printf("element : |%d|\n", arr->pElement[i].data);
	printf("==========================\n");
}

int main()
{
	ArrayQueue	*arr;
	int			i;
	
	i = 0;
	arr = createArrayQueue(5);
	while (i < 5)
		enqueueAQ(arr, (ArrayQueueNode){i++ + '0'});
	print_arr(arr);

	i = 0;
	printf("====== deque element ======\n");
	while (i < 5)
	{
		printf("deque element : %c\n", dequeueAQ(arr)->data);
		i++;
	}
	print_arr(arr);

	printf("======deleteArray=====\n");
	deleteArrayQueue(arr);
}