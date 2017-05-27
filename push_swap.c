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

	stack = initstack();
	if (ac == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	if (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'c'))
		if (set_features(stack, av) && ac--)
			av++;
	if (create_stack(ac, av, &stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack->b = init_array(stack->size_a);
	(stack->size_a > 7) ? sort_large(stack) : sort_small(stack);
	ft_lstprint(stack->ops);
	free_stack(stack);
	return (0);
}
