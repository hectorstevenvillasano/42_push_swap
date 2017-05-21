

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
	//while (++i < stack->size_b > 0)
	//{
		find_min_max(stack);
		a = (i < (stack->size_a + 1) / 2) ? i : (i - stack->size_a);
		b = calc_positions(stack, stack->a[i]);
		if (a * b < 0 )
			rots = 1 + ft_abs(a) + ft_abs(b);
	//}

	printf("a:%i b:%i flag:%i rots:%i\n", a, b, flag, rots);
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
//	}
}
