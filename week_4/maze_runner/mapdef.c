#include "mapdef.h"
#include <stdio.h>
#include <stdlib.h>

int maze[8][8] = {{0, 0, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 1, 1, 1},
                  {1, 1, 1, 0, 1, 0, 0, 0},
                  {1, 1, 1, 0, 1, 0, 1, 0},
                  {1, 0, 0, 0, 0, 0, 0, 0},
                  {1, 0, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0},
                  {1, 1, 1, 1, 1, 1, 1, EXIT}};

int maze2[8][8] = {{0, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, EXIT, 1, 0, 0, 0},
					{1, 1, 1, 1, 1, 1, 1, 1}};

int maze3[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0, 0, 1, 1},
							{1, 0, 1, 1, 1, 1, 1, 1},
							{1, 0, 1, 1, 1, 1, 1, 1},
							{1, 0, 1, 1, 1, 1, 1, 1},
							{1, 0, 1, 1, 1, 1, 1, 1},
							{1, 0, 1, 1, 0, 0, 0, EXIT},
							{1, 0, 0, 1, 0, 1, 1, 1},
							{1, 1, 0, 0, 0, 1, 1, 1}};

void	observer(int x, int y, LinkedStack *stack, int map[8][8], int direction)
{
	MapPosition curr;
	MapPosition	*tmp;

	
	if (x > 7 || x < 0 || y < 0 || y > 7)
		return ;
	if (map[x][y] == WALL || map[x][y] == VISIT)
		return ;
	if (map[x][y] == EXIT)
	{
		for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
                printf(" %d ", maze[i][j]);
            printf("\n");
        }
		printf("-[EXIT]-\n");
		exit(1);
	}
	map[x][y] = VISIT;
	curr.x = x;
	curr.y = y;
	curr.direction = direction;
	pushLS(stack, curr);
	observer(x + 1, y, stack, map, DOWN);
	observer(x, y + 1, stack, map, RIGHT);
	observer(x, y - 1, stack, map, UP);
	observer(x - 1, y, stack, map, LEFT);
	tmp = popLS(stack);
	map[x][y] = 0;
	tmp->direction = 0;
	tmp->next = 0;
	tmp->x = 0;
	tmp->y = 0;
	free(tmp);
}

int main()
{
	LinkedStack	*last_memory;

	last_memory = createLinkedStack();
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        	printf(" %d ", maze[i][j]);
        printf("\n");
    }
    printf("----------------------------\n");
	observer(0, 0, last_memory, maze, DOWN);
}



