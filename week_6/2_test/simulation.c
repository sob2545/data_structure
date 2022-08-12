#include "linkeddeque.h"
#include "stdio.h"
#include "stdlib.h"

int	client_num = 0;
int	time_spent = 0;

DequeNode	create_node(int arrival, int service, int start, int end, int idx)
{
	DequeNode temp;

	temp.data.idx = idx;
	temp.data.arrivalTime = arrival;
	temp.data.serviceTime = service;
	temp.data.startTime = start;
	temp.data.endTime = end;

	return (temp);
}
LinkedDeque	*create_clients() //클라이언트 시뮬레이션 정보 삽입
{
	LinkedDeque	*ret;
	DequeNode	temp;
	ret = createLinkedDeque();
	temp = create_node(0, 4, 0, 0, 1);
	insertRearLD(ret, temp);
	temp = create_node(1, 4, 0, 0, 2);
	insertRearLD(ret, temp);
	temp = create_node(1, 5, 0, 0, 3);
	insertRearLD(ret, temp);
	temp = create_node(2, 1, 0, 0, 4);
	insertRearLD(ret, temp);
	temp = create_node(4, 2, 0, 0, 5);
	insertRearLD(ret, temp);
	temp = create_node(5, 2, 0, 0, 6);
	insertRearLD(ret, temp);
	temp = create_node(7, 2, 0, 0, 7);
	insertRearLD(ret, temp);
	temp = create_node(8, 2, 0, 0, 8);
	insertRearLD(ret, temp);
	return (ret);
}

void	check_arrival(LinkedDeque *clients, LinkedDeque *service_que, LinkedDeque *wait_que, int time)
{
	if (clients->currentElementCount == 0)
		return ;
	while (clients->currentElementCount != 0 && peekFrontLD(clients)->data.arrivalTime == time)
	{
		printf("[%d시] Client%d 도착, 대기\n", time, peekFrontLD(clients)->data.idx);
		insertRearLD(wait_que, *peekFrontLD(clients));
		client_num++;
		deleteFrontLD(clients);
	}
}

LinkedDeque *check_service(LinkedDeque *service_que, int time, int agent_num)
{
	LinkedDeque *new;
	int	cnt = service_que->currentElementCount;
	int	i = 0;

	if (service_que->currentElementCount == 0)
		return (service_que);
	new = createLinkedDeque();
	while (i < cnt)
	{
		if (service_que->pFrontNode->data.endTime == time)
		{
			peekFrontLD(service_que)->data.status = end;
			printf("[%d시] Client%d 서비스 완료, free agent : %d\n", time, peekFrontLD(service_que)->data.idx, agent_num - service_que->currentElementCount + 1);
			time_spent += peekFrontLD(service_que)->data.startTime - peekFrontLD(service_que)->data.arrivalTime;
			deleteFrontLD(service_que);
		}
		else
		{
			insertRearLD(new, *peekFrontLD(service_que));
		}
		i++;
	}
	return (new);
}

void	start_service(LinkedDeque *service_que, LinkedDeque *wait_que, int time, int agent_num)
{
	while (service_que->currentElementCount < agent_num && wait_que->currentElementCount != 0)
	{
		printf("[%d시] Client%d 서비스 시작, free agent : %d\n", time, peekFrontLD(wait_que)->data.idx, agent_num - service_que->currentElementCount - 1);
		peekFrontLD(wait_que)->data.status = start;
		peekFrontLD(wait_que)->data.startTime = time;
		peekFrontLD(wait_que)->data.endTime = time + peekFrontLD(wait_que)->data.serviceTime;
		insertRearLD(service_que, *peekFrontLD(wait_que));
		deleteFrontLD(wait_que);
	}
}

int main(int argc, char **argv)
{
	LinkedDeque *service_que;
	LinkedDeque *wait_que;
	LinkedDeque *clients;
	int			time = 0;
	int			closure_time = 10;
	int			agent_num;

	if (argc != 2)
		return (FALSE);
	agent_num = atoi(argv[1]);
	if (agent_num <= 0)
		return (FALSE);
	service_que = createLinkedDeque();
	wait_que = createLinkedDeque();
	clients = create_clients();

	printf("\n=========== 영업시작 ===========\n");
	while (time <= closure_time)
	{
		check_arrival(clients, service_que, wait_que, time); //각 시간에 도착한 고객을 대기큐로 이동
		service_que = check_service(service_que, time, agent_num); //서비스중인 고객이 서비스 종료되었으면 삭제
		start_service(service_que, wait_que, time, agent_num); //빈 자리가 생기면 대기중인 고객 서비스 시작
		time = time + 1; //시간이 흐른다s
	}

	printf("\n========= [%d]시 영업종료 =========\n", time - 1);
	printf("서비스 완료하지 못한 고객 : %d\n", service_que->currentElementCount + wait_que->currentElementCount);

	while (wait_que->currentElementCount != 0)
	{
		time_spent += time - peekFrontLD(wait_que)->data.arrivalTime;
		deleteFrontLD(wait_que);
	}
	printf("평균 고객 대기시간: %f\n\n", (float)time_spent / (float)client_num);
}
