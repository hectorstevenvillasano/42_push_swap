#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/inc/ft_printf.h"

#include <stdio.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;

}				t_stack;

/** push_swap.c **/
void print_stacks(int *stacka, int *stackb);

/** freeit.c **/
void 	free_split(char ***split);
/** create_stack.c **/
int		create_stack(int ac, char **av, t_stack **st);
int list_len(t_list *ls);
/** solver.c **/


/** struct.c **/
int		*init_array(int size);
t_stack	*initstack(void);

/** sort.c **/
void 	sort_large(t_stack *stack);



#endif
