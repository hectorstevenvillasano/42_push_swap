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



int 	*ft_intdup(int *array, int size)
{
	int *cpy;
	int i;

	cpy = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		cpy[i] = array[i];
		i++;
	}
	return (cpy);
}


void ft_lstprint(t_list *head)
{
	while (head)
	{
		ft_putendl(head->content);
		head = head->next;
	}
}

void ft_lstfree(t_list *head)
{
	t_list *tmp;

	while (head)
	{
		tmp = head;
		free(head->content);
		head = head->next;
		free(tmp);
	}
}


static void print_array(int *stack, int size, int color)
{
	int i;

	i = 0;
	if (size == 0)
		printf("\e[1;%dmEmpty\e[0m", color);
	while (i < size)
	{
		printf("\e[1;%dm%d\e[0m ", color, stack[i]);
		i++;
	}
	ft_putstr("\n");
}

void 	display_stack(t_stack *stack, int *a_copy)
{
	int 	color;
	t_list 	*tmp;

	color = 0;
	free(stack->a);
	stack->a = ft_intdup(a_copy, stack->size_a);
	tmp = stack->ops;
	while (tmp != NULL)
	{
		apply_operations(stack, tmp->content);
		if (stack->features == 2 || stack->features == 3)
			color = sort_check(stack) ? 32 : 31;
		//printf("\e[0m%s\n", tmp->content);
		printf("\e[1;%dmStack A (%d): ", color, stack->size_a);
		print_array(stack->a, stack->size_a, color);
		printf("\e[1;%dmStack B (%d): ", color, stack->size_b);
		print_array(stack->b, stack->size_b, color);
		tmp = tmp->next;
	}
	free(stack->a);
}
