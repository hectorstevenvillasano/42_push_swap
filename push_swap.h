#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/inc/ft_printf.h"

#include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;

}				t_stack;

/** freeit.c **/
void free_split(char ***split);
/** create_stack.c **/
int create_stack(int ac, char **av, t_list **stack);

/** solver.c **/


#endif
