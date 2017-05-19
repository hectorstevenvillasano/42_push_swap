#include "push_swap.h"


static int check_dups(t_list *stack, int *value)
{
	while (stack)
	{
		if (*(int*)stack->content == *value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int list_size(t_list *ls)
{
	int len;

	len = 0;
	while (ls)
	{
		len++;
		ls = ls->next;
	}
	return (len);
}

static int av_to_int(char *av, int *value)
{
	int		num;
	int		neg;

	num = 0;
	neg = 1;
	if (!av)
		return (1);
	if (*av == '-')
	{
		neg = -1;
		av++;
	}
	if (*av == '\0')
		return (1);
	while ('0' <= *av && *av <= '9')
	{
		num = (10 * num) + neg * (*av - '0');
		av++;
		if ((neg == 1 && num < 0) || (neg == -1 && num > 0))
			return (1);
	}
	if (*av != '\0')
		return (1);
	*value = num;
	return (0);
}


static int addstackarray(t_list **stack, char *av)
{
	char	**split;
	int		value;
	int		i;

	i = 0;
	split = ft_strsplit(av, ' ');

	while (split[i])
		i++;
	while (i)
	{
		i--;
		if (av_to_int(split[i], &value) || check_dups(*stack, &value))
		{
			free_split(&split);
			return (1);
		}
		ft_lstadd(stack, ft_lstnew(&value, sizeof(int)));
	}
	free_split(&split);
	return (0);
}

int *moveto_array(t_list *stacka, int stacka_len)
{
	int *a;
	int i;

	i = 0;
	a = (int*)malloc(sizeof(int) * stacka_len + 1);
	while (stacka)
	{
		a[i] = *(int*)stacka->content;
		i++;
		stacka = stacka->next;
	}
	return (a);
}

int create_stack(int ac, char **av, t_list **stack)//, t_stack **ls)
{
	int *ls;
	while (--ac)
	{
		if (addstackarray(stack, av[ac]))
			return (1);
	}
	ls = moveto_array(*stack, list_size(*stack));
	while (*ls)
	{
		printf("%i ", *ls);
		ls++;
	}
	return (0);
}
