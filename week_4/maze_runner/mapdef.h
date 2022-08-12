#ifndef _MAP_DEF_
# define _MAP_DEF_

# define WIDTH 8
# define HEIGHT 8

# define DOWN 3
# define RIGHT 4
# define UP 5
# define LEFT 6

enum PosStatus 
{
	NOT_VISIT = 0,
	WALL = 1,
	VISIT = 2, 
	EXIT = -1
};

typedef struct				MapPositionType
{
	int						x;
	int						y;
	int						direction;
	struct	MapPositionType	*next;
}							MapPosition;


typedef struct		LinkedStackType
{
	int				cur_len;
	MapPosition*	head;
} 					LinkedStack;

LinkedStack* 	createLinkedStack();
int				pushLS(LinkedStack* pStack, MapPosition element);
MapPosition*	popLS(LinkedStack* pStack);
MapPosition*	peekLS(LinkedStack* pStack);
//void			deleteLinkedStack(LinkedStack* pStack);
//int				isLinkedStackFull(LinkedStack* pStack);
//int				isLinkedStackEmpty(LinkedStack* pStack);

#endif