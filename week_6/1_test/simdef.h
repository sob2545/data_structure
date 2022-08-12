#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType
{
	ARRIVAL,
	START,
	END
}	SimStatus;

typedef struct SimCustomerType
{
	SimStatus	status;
	int			arrivalTime;
	int			serviceTime;
	int			startTime;
	int			endTime;
}	SimCustomer;

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
