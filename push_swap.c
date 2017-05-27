#include "push_swap.h"




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
	if (ac == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	if (av[1][0] == '-')
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
