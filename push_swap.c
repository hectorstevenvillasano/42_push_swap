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
	(*stacka != '\0') ? print_stack(stacka) : ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("b|");
	(stackb != '\0') ? print_stack(stackb) : ft_putstr("\n");

}


int main(int ac, char **av)
{
	t_stack	*stack;

	stack = initstack();
	if (create_stack(ac, av, &stack)) //&stack)) //|| solver(&stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack->b = NULL;
	print_stacks(stack->a, stack->b);
	return (0);
}
