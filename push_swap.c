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

int main(int ac, char **av)
{
	t_stack	*stack;
	int		*a_copy;

	stack = initstack();
	if (create_stack(ac, av, &stack)) //| solver(&stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}

	ft_putendl("stack start!");
	print_stacks(stack->a, stack->b);
	ft_putendl("\n");

	stack->b = init_array(stack->size_a);
	a_copy = stack->a;
	sort_large(stack);
//	(stack->size_a > 7) ? sort_large(stack) : sort_small(stack);

	print_stacks(a_copy, stack->b);
	return (0);
}
