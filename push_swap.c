#include "push_swap.h"



void print_stack(int *stack)
{
	while(*stack)
	{
		ft_printf("%i ", *stack);
		stack++;
	}
	ft_putchar('\n');
}

void print_stacks(int *stacka, int *stackb)
{

	ft_putstr("a|");
	(stacka != '\0') ? print_stack(stacka) : ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("b|");
	(stackb != '\0') ? print_stack(stackb) : ft_putstr("\n");

}

static int set_features(t_stack *stack, char **av)
{
	if (!ft_strcmp(av[1], "-v"))
		stack->features = 1;
	else if (!ft_strcmp(av[1], "-c"))
		stack->features = 2;
	else if (!ft_strcmp(av[2], "-cv" || !ft_strcmp(av[2], "-vc"))
		stack->features = 3;
	else
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	t_stack	*stack;
	int		*a_copy;

	stack = initstack();
	if (set_features(stack, av) && ac--)
		av++;
	if (create_stack(ac, av, &stack)) //| solver(&stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}

	// ft_putendl("stack start!");
	// print_stacks(stack->a, stack->b);
	// ft_putendl("\n");
	a_copy = stack->a;
	stack->b = init_array(stack->size_a);
	(stack->size_a > 7) ? sort_large(stack) : sort_small(stack);

	// if (stack->features == 1 || stack->features == 3)
	// 	display_stack(stack, a_copy);



	// ft_putendl("\nfinal stacks:");
	// print_stacks(stack->a, stack->b);
	// ft_putendl("");
	// while (stack->ops)
	// {
	// 	ft_putendl(stack->ops->content);
	// 	stack->ops = stack->ops->next;
	// }
	return (0);
}
