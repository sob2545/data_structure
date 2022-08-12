#include "simlinkedqueue.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

int	waste_time;
int	fin_count = 0;

int	isAgentFree(SimAgent Service, int a_num)
{
	for (int i = 0; i < a_num; i++)
	{
		if (Service.serviceNode[i])
			return (FALSE);
	}
	return (TRUE);
}

void	init_client(LinkedQueue	*Arrival, int *client_num)
{
	QueueNode	node;

	srand(time(NULL));
	for (int i = 0; i < *client_num; ++i)
	{
		/* node.customer = (SimCustomer){0, i, (i / 2 + i), (n - (i - n * (i / n))), 0, 0}; */
		node.customer = (SimCustomer){0, i, i, 1 + rand() % 5, 0, 0};
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

void	end_service(LinkedQueue *Wait, SimAgent *Service, int curr_t, int a_num)
{
	QueueNode	*fin;

	(void)*Wait;
	if (isAgentFree(*Service, a_num))
		return ;
	for (int i = 0; i < a_num; i++)
	{
		fin = Service->serviceNode[i];
		if (fin && fin->customer.endTime == curr_t)
		{
			printf("%dClient service end\n", fin->customer.idx);
			Service->availAgentCount++;
			free(fin);
			Service->serviceNode[i] = NULL;
			fin_count++;
		}
	}
}

void	start_service(LinkedQueue *Wait, SimAgent *Service, int curr_t, int a_num)
{
	QueueNode	*curr;

	if (Wait->pFrontNode == 0 && Service->availAgentCount <= 0)
		return ;
	printf("\n");
	while (Service->availAgentCount > 0 && Wait->pFrontNode)
	{
		curr = dequeueLQ(Wait);
		curr->customer.status = START;
		curr->customer.startTime = curr_t;
		curr->customer.endTime = curr_t + curr->customer.serviceTime;
		waste_time += curr->customer.startTime - curr->customer.arrivalTime;
		for (int i = 0; i < a_num; i++)
		{
			if (Service->serviceNode[i] == NULL)
			{
				printf("%dAgent start handle %dClient\n", i, curr->customer.idx);
				Service->serviceNode[i] = curr;
				Service->availAgentCount--;
				break ;
			}
		}
	}
}

int	main(int ac, char **av)
{
	LinkedQueue	*Arrival;
	LinkedQueue	*Wait;
	SimAgent	Service;
	int			a_num;
	int			clients_num;
	int			total;
	int			t;

	if (ac != 3)
		return (0);
	a_num = atoi(av[1]);
	clients_num = atoi(av[2]);
	if (a_num <= 0 || clients_num <= 0)
		return (0);
	memset(&Service, 0, sizeof(SimAgent));
	Service.availAgentCount = a_num;
	Service.serviceNode = calloc(Service.availAgentCount, sizeof(QueueNode *));
	if (!Service.serviceNode)
		return (1);
	Arrival = createLinkedQueue();
	Wait = createLinkedQueue();
	init_client(Arrival, &clients_num);
	total = Arrival->currentElementCount;
	printf("Bank opened\n");
	printf("%d agents work\n", a_num);
	printf("%d clients will visit\n", total);
	t = 0;
	for(; t + START_TIME < END_TIME; ++t)
	{
		/* printf("\n======[ %d%d:00 ]======\n", (t + 9) / 10, (t + 9) % 10); */
		printf("\n======[ %02d:00 ]======\n", t + START_TIME);
		init_waitlist(Arrival, Wait, t);
		end_service(Wait, &Service, t, a_num);
		start_service(Wait, &Service, t, a_num);
	}
	printf("\n======[ %02d:00 ]======\n", t + START_TIME);
	printf("Bank closed\n");
	printf("\n");
	if (!isAgentFree(Service, a_num))
		printf("Agent(s) have to overwork today\n");
	printf("%d clients finished their service\n", fin_count);
	printf("%d clients can't finished their service\n", Wait->currentElementCount + a_num - Service.availAgentCount);
	while (Wait->pFrontNode)
	{
		waste_time += t - Wait->pFrontNode->customer.arrivalTime;
		free(dequeueLQ(Wait));
	}
	printf("The average time to wait : %.2f hours\n", (float)waste_time / (fin_count + Wait->currentElementCount + a_num - Service.availAgentCount));
}
