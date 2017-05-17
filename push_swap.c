#include "push_swap.h"

void initstack(t_stack stack)
{
	*stack.a = NULL;
	*stack.b = NULL;
}


int pars_av(char *av, int *value)
{
	int		num;
	int		neg;

	num = 0;
	neg = 0;
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
	if (*av)
		return (1);
	*value = num;
	return (0);
}


int addstackarray(t_list **stack, char *av)
{
	char	**split;
	int		nb;
	int		i;

	i = 0;
	split = ft_strsplit(av, ' ');

	while (split[i])
		i++;
	while (i)
	{
		i--;
		if (!(nb = ft_atoi(split[i])))
			return (1);
		//ft_putendl(split[i]);
		printf("%i\n", nb);
	}


	//ft_lstadd(stack, ft_lstnew(&nb, sizeof(int)));


	return (0);
}

int create_stack(int ac, char **av, t_list **stacka)
{
	//stack = NULL;
	while (--ac)
	{
		if (addstackarray(stacka, av[ac]))
			return (1);
	}
	return (0);
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
	return (0);
}
