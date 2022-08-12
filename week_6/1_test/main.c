#include "simlinkedqueue.h"

int	main(void)
{
	LinkedQueue	*Arrival;
	LinkedQueue	*Wait;
	QueueNode	*curr;
	int	t = 0;
	int	user = 0;
	int	wait_time = 0;
	
	Arrival = createLinkedQueue();
	Wait = createLinkedQueue();
	insertCustomer(0, 3, Arrival);
	insertCustomer(2, 2, Arrival);
	insertCustomer(4, 1, Arrival);
	insertCustomer(6, 1, Arrival);
	insertCustomer(8, 3, Arrival);
	curr = 0;
	while (t < 10)
	{
		printf("??\n");
		processArrival(t, Arrival, Wait);
		processServiceNodeEnd(t, curr, &user, &wait_time);
		if (curr && curr->customer.status == END)
		{
			free(curr);
			curr = processServiceNodeStart(t, Wait);
		}
		printWaitQueueStatus(t, Wait);
		t++;
	}
	printReport(Wait, user, wait_time);
}
