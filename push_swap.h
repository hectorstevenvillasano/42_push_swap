#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/inc/ft_printf.h"

#include <stdio.h>


#define ft_abs(x) x < 0 ? -x : x

typedef struct s_stack
{
	t_list	*ops;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int 	b_max;
	int		b_min;

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

/** rulse.c **/
void 	apply_operations(t_stack *stack, char *input);
int 	ps_swap(t_stack *stack, char option);
int 	ps_push(t_stack *stack, char option);
int 	ps_rotate(t_stack *stack, char option);
int 	ps_reverse_rotate(t_stack *stack, char option);

/** help.c **/
void 	find_min_max(t_stack *stack);
int 	calc_positions(t_stack *stack, int num);




#endif
