/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:25:00 by hvillasa          #+#    #+#             */
/*   Updated: 2017/05/27 18:09:47 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack *stack, int ab)
{
	int		i;

	i = 0;
	if (ab == 0)
	{
		while (i < stack->size_a)
		{
			ft_putstr(ft_itoa(stack->a[i]));
			ft_putstr(" ");
			i++;
		}
	}
	if (ab == 1)
	{
		while (i < stack->size_b)
		{
			ft_putstr(ft_itoa(stack->b[i]));
			ft_putstr(" ");
			i++;
		}
	}
	ft_putchar('\n');
}

void		print_stacks(t_stack *stack)
{
	ft_putstr("a|");
	(stack->a[0] != '\0') ? print_stack(stack, 0) : ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("b|");
	(stack->b[0] != '\0') ? print_stack(stack, 1) : ft_putstr("\n");
}

int			*ft_intdup(int *array, int size)
{
	int	*cpy;
	int	i;

	cpy = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		cpy[i] = array[i];
		i++;
	}
	return (cpy);
}

void		ft_lstprint(t_list *head)
{
	while (head)
	{
		ft_putstr(head->content);
		ft_putstr("\n");
		head = head->next;
	}
}

void		ft_lstfree(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		free(head->content);
		head = head->next;
		free(tmp);
	}
}
