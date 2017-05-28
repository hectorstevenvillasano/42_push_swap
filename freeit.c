/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <hvillasa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 01:24:20 by hvillasa          #+#    #+#             */
/*   Updated: 2017/05/27 16:20:23 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
	*split = NULL;
}

void prints(t_stack *stack, char *input)
{
	if (stack->features == 1)
	{
		ft_putstr("\n\noperation: ");
		ft_putstr(input);
		ft_putstr("\n");
		print_stacks(stack);
	}
}
