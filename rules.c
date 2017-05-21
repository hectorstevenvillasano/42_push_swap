
#include "push_swap.h"

int ps_swap(t_stack *stack, char option)
{
	int tmp;

	if ((option == 'a' || option == 'c') && data->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if ((option == 'b' || option == 'c') && data->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->a[1];
		stack->b[1] = tmp;
	}
}

int ps_reverse_rotate(t_stack *stack, char option)
{
	int tmp;
	int i;

	if (option == 'a' || option == 'c')
	{
		tmp = stack->a[stack->size_a - 1];
		i = stack->size_a;
		while(i-- > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = tmp;
	}
	if (option == 'b' || option == 'c')
	{
		tmp = stack->b[stack->size_b - 1];
		i = stack->size_b;
		while(i-- > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = tmp;
	}
	return (1);
}

int ps_rotate(t_stack *stack, char option)
{
	int	tmp;
	int i;

	tmp = 0;
	i = -1;
	if (option == 'a' || option == 'c')
	{
		tmp = stack->a[0];
		i = -1;
		while (++i < stack->size_a - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[stack->size_a - 1] = tmp;
	}
	if (option == 'b' || option == 'c')
	{
		tmp = stack->b[0];
		i = -1;
		while (++i < stack->size_b - 1)
			stack->b[i] = stack->b[i + 1];
		stack->b[stack->size_b - 1] = tmp;
	}
		return (1);
}

int ps_push(t_stack *stack, char option)
{
	int tmp;

	tmp = 0;
	if (option == 'a' && stack->size_b > 0)
	{
		tmp = stack->b[0];
		stack->b[0] = 0 ;
		ps_rotate(stack, 'b');
		stack->size_a++;
		stack->size_b--;
		ps_reverse_rotate(stack, 'a');
		 stack->a[0] = tmp;
	}
	if (option == 'b' && stack->size_a > 0)
	{
		tmp = stack->a[0];
		stack->a[0] = 0 ;
		ps_rotate(stack, 'a');
		stack->size_b++;
		stack->size_a--;
		ps_reverse_rotate(stack, 'b');
		stack->b[0] = tmp;
	}
	return (1);
}

void apply_operations(t_stack *stack, char *input)
{
	if (!ft_strcmp(input, "sa"))
		ps_swap(stack, 'a');
	if (!ft_swap(input, "sa"))
		ps_push(stack, 'b');
	if (!ft_swap(input, "ss"))
		ps_swap(stack, 'c');

	if (!ft_strcmp(input, "pa"))
		ps_push(stack, 'a');
	if (!ft_strcmp(input, "pa"))
		ps_push(stack, 'b');
	if (!ft_strcmp(input, "pp"))
		ps_push(stack, 'c');

	if (!ft_strcmp(input, "ra"))
		ps_rotate(stack, 'a');
	if (!ft_strcmp(input, "ra"))
		ps_rotate(stack, 'b');
	if (!ft_strcmp(input, "rr"))
		ps_rotate(stack, 'c');


	if (!ft_strcmp(input, "rra"))
		ps_reverse_rotate(stack, 'a');
	if (!ft_strcmp(input, "rra"))
		ps_reverse_rotate(stack, 'b');
	if (!ft_strcmp(input, "rrr"))
		ps_reverse_rotate(stack, 'c');

}
/*
up is right
down is right
	sa:	swap a - swap the first two elements on top of stack a. Do nothing if
				 there is only one element.
	sb:	swap b - swap the first two elements on top of stack b. Do nothing if
				 there is only one element.
	ss: sa and sb at the same time

	pa: push a - take the first element on top of b and put it on top of a.
				 do nothing if a is empty;
	pb: push b - take the first element on top of a and put it on top of b.
				 do nothing if a is empty;

	ra:	rotate a - shift up all elements of stack a by 1. The first element
				   becomes the last one.
	rb: rotate b - shift up all elements of stack b by 1. The first element
				   becomes the last one.
	rr: ra and rb at the same time;

	rra: reverse rotate a - shift down all elements of stack a by 1.
							The last element becomes the first.
	rra: reverse rotate b  - shift down all elements of stack b by 1.
							The last element becomes the first.
	rrr: rra and rrb at the saem time

*/
