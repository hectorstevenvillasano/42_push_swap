#include "push_swap.h"

t_stack *initstack(void)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}



void print_stack(t_list *stack)
{
	while(stack)
	{
		ft_putnbr(*(int*)(stack->content));
		if (stack->next)
			ft_putstr(" ");
		stack = stack->next;
	}
	ft_putchar('\n');
}

void print_stacks(t_list *stacka, t_list *stackb)
{
	ft_putstr("a|");
	print_stack(stacka);
	ft_putstr("\n");
	ft_putstr("b|");
	print_stack(stackb);
}


int main(int ac, char **av)
{
//	t_stack	*stack;
	t_list	*a;

	a = NULL;
	//stack = initstack();
	if (create_stack(ac, av, &a)) //&stack)) //|| solver(&stack))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	//print_stack(a);
	return (0);
}
