

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
	}
	return (1);
}

static void calc_rotation(t_stack *stack)
{
	int i;
	int a;
	int b;
	int rots;
	int  flag;

	rots = 0;
	i = -1;
	flag = 0;
	while (++i < stack->size_b)
	{
		find_min_max(stack);
		a = (i < (stack->size_a + 1) / 2) ? i : (i - stack->size_a);
		b = calc_positions(stack, stack->a[i]);
		if (a * b < 0 )
			rots = 1 + ft_abs(a) + ft_abs(b);
		else
			rots = ft_abs(a) > ft_abs(b) ? ft_abs(a) + 1 : ft_abs(b) + 1;
		if (rots < stack->t_rots || flag == 0)
		{
			flag = 1;
			stack->t_rots = rots;
			stack->a_rots = a;
			stack->b_rots = b;
		}
	}

	printf("a:%i b:%i flag:%i rots:%i t_rots:%i a_rots:%i b_rots:%i\n\n", a, b, flag, rots, stack->t_rots, stack->a_rots, stack->b_rots);
}

void 	sort_large(t_stack *stack)
{
	if (sort_check(stack))
	{
		ft_printf("is sorted\n");
		return ;
	}
	apply_operations(stack, "pb");
	stack->ops = ft_lstnew("pb", 2);
//	while (stack->size_a > 0)
//	{
		calc_rotation(stack);
		//rotate_both(stack);
//	}
}
