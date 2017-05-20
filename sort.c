

#include "push_swap.h"

int		sort_check(t_stack *stack)
{
	int i;


	if (stack->size_b != 0)
		return (0);
	i = -1;
	while (++i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
	 		return (0);
		printf("if %i > %i\n", stack->a[i], stack->a[i + 1]);
	}
	return (1);
}


void 	sort_large(t_stack *stack)
{
	if (sort_check(stack))
	{
		ft_printf("is sorted\n");
		return ;
	}

}
