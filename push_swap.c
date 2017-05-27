#include "push_swap.h"



void print_stack(t_stack *stack, int ab)
{
	int i;

	i = 0;
	if (ab == 0)
	{
		while(i < stack->size_a)
		{
			ft_putstr(ft_itoa(stack->a[i]));
			ft_putstr(" ");
			i++;
		}
	}
	if (ab == 1)
	{
		while(i < stack->size_b)
		{
			ft_putstr(ft_itoa(stack->b[i]));
			ft_putstr(" ");
			i++;
		}
	}
	ft_putchar('\n');
}

void print_stacks(t_stack *stack)
{
	ft_putstr("a|");
	(stack->a[0] != '\0') ? print_stack(stack, 0) : ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("b|");
	(stack->b[0] != '\0') ? print_stack(stack, 1) : ft_putstr("\n");

}

static int set_features(t_stack *stack, char **av)
{
	if (!ft_strcmp(av[1], "-v"))
		stack->features = 1;
	else if (!ft_strcmp(av[1], "-c"))
		stack->features = 2;
	else if (!ft_strcmp(av[2], "-cv") || !ft_strcmp(av[2], "-vc"))
		stack->features = 3;
	else
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	t_stack	*stack;
	//int		*a_copy;

	stack = initstack();
	if (set_features(stack, av) && ac--)
		av++;
	if (create_stack(ac, av, &stack)) //| solver(&stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack->b = init_array(stack->size_a);

	ft_putstr("STACKS TART\n");
	print_stacks(stack);

	//a_copy = ft_intdup(stack->a, stack->size_a);
	(stack->size_a > 7) ? sort_large(stack) : sort_small(stack);
//	if (stack->features == 1 || stack->features == 3)
//	 	display_stack(stack, a_copy);
	//else



	// ft_putstr("\n");
	// ft_putstr("STACKS END\n");
	// print_stacks(stack);
	ft_putstr("\n");
	ft_lstprint(stack->ops);
	free_stack(stack);
	return (0);
}
