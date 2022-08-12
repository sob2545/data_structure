#include "simlinkedqueue.h"
#include <stdlib.h>
#include <stdio.h>

int	waste_time;

void	init_client(LinkedQueue	*Arrival, int n, int *client_num)
{
	QueueNode	node;

	for (int i = 0; i < *client_num; ++i)
	{
		node.customer = (SimCustomer){0, i, (i / 2 + i), (n - (i - n * (i / n))), 0, 0};
		if (enqueueLQ(Arrival, node) != TRUE)
			clearLinkedQueue(Arrival);
	}
}

void	print_waitlist(LinkedQueue *Wait)
{
	QueueNode	*curr;

	if (Wait->pFrontNode == 0)
		return ;
	curr = Wait->pFrontNode;
	printf("\n%d People waiting...\n", Wait->currentElementCount);
	while (curr)
	{
		printf("%dClient\n", curr->customer.idx);
		curr = curr->pLink;
	}
	printf("\n");
}

void	init_waitlist(LinkedQueue *Arrival, LinkedQueue *Wait, int curr_t)
{
	QueueNode	*curr;

	print_waitlist(Wait);
	if (Arrival->pFrontNode == 0)
		return ;
	if (curr_t == Arrival->pFrontNode->customer.arrivalTime)
	{
		printf("%dClient has arrived\n", Arrival->pFrontNode->customer.idx);
		curr = dequeueLQ(Arrival);
		if (enqueueLQ(Wait, *curr) != TRUE)
			clearLinkedQueue(Wait);
		free(curr);
	}
}

void	end_service(LinkedQueue *Wait, LinkedQueue *Service, int curr_t, int *a_num)
{
	QueueNode	*curr;
	QueueNode	*fin;

	if (Wait->pFrontNode == 0 && Service->pFrontNode == 0)
		return ;
	curr = Service->pFrontNode;
	while(curr)
	{
		fin = curr;
		curr = curr->pLink;
		if (fin->customer.endTime == curr_t)
		{
			printf("%dClient service end\n", fin->customer.idx);
			Service->pFrontNode = curr;
			Service->currentElementCount--;
			fin->pLink = 0;
			free(fin);
			(*a_num)++;
		}
	}
}

void	start_service(LinkedQueue *Wait, LinkedQueue *Service, int curr_t, int *a_num)
{
	QueueNode	*curr;

	if (Wait->pFrontNode == 0 && *a_num <= 0)
		return ;
	printf("\n");
	while (*a_num > 0 && Wait->pFrontNode)
	{
		curr = dequeueLQ(Wait);
		curr->customer.status = START;
		curr->customer.startTime = curr_t;
		curr->customer.endTime = curr_t + curr->customer.serviceTime;
		waste_time = curr->customer.startTime - curr->customer.arrivalTime;
		printf("%dAgent start handle %dClient\n", *a_num, curr->customer.idx);
		enqueueLQ(Service, *curr);
		(*a_num)--;
		free (curr);
	}
}

int	main(int ac, char **av)
{
	LinkedQueue	*Arrival;
	LinkedQueue	*Wait;
	LinkedQueue	*Service;
	int			a_num;
	int			clients_num;
	int			total;
	int			t;

	if (ac != 2)
		return (0);
	a_num = atoi(av[1]);
	if (a_num <= 0)
		return (0);
	t = 0;
	clients_num = 6;
	Arrival = createLinkedQueue();
	Wait = createLinkedQueue();
	Service = createLinkedQueue();
	init_client(Arrival, 3, &clients_num);
	total = Arrival->currentElementCount;
	printf("Bank opened\n");
	printf("%d agents work\n", a_num);
	printf("%d clients will visit\n", total);
	for(; t < 11; ++t)
	{
		printf("\n======[ %d%d:00 ]======\n", (t + 9) / 10, (t + 9) % 10);
		init_waitlist(Arrival, Wait, t);
		end_service(Wait, Service, t, &a_num);
		start_service(Wait, Service, t, &a_num);
	}
	while (Wait->pFrontNode)
	{
		waste_time += t - Wait->pFrontNode->customer.arrivalTime;
		free(dequeueLQ(Wait));
	}
	printf("\n======[ %d%d:00 ]======\n", (t + 9) / 10, (t + 9) % 10);
	printf("Bank closed\n");
	printf("\n");
	if (Service->pFrontNode)
		printf("Agent(s) have to overwork today\n");
	printf("%d clients finished their service\n", total - (Wait->currentElementCount + Service->currentElementCount));
	printf("%d clients can't finished their service\n", Wait->currentElementCount + Service->currentElementCount);
	printf("The average time to wait : %.2f hours\n", (float)waste_time / clients_num);
}
