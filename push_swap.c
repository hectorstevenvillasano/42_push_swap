#include "push_swap.h"

void initstack(t_stack stack)
{
	*stack.a = NULL;
	*stack.b = NULL;
}

void printls(t_list *stack)
{
	while(stack)
	{
		printf("%i\n", *(int*)(stack->content));
		stack = stack->next;
	}
}


int main(int ac, char **av)
{
	t_stack	stack;
	t_list	*a;
	t_list	*b;

	stack.a = &a;
	stack.b = &b;
	initstack(stack);
	if (create_stack(ac, av, &a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	printls(*stack.a);
	return (0);
}
