#include "push_swap.h"

void find_min_max(t_stack *stack)
{
	int i;
	int min;
	int max;

	i = 0;
	min = 0;
	max = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[max])
			max = i;
		if (stack->b[i] < stack->b[min])
			min = i;
		i++;
	}
	stack->b_max = max;
	stack->b_min = min;

}
int ft_abs(int num)
{
	return (num < 0 ? -num : num);
}

int calc_positions(t_stack *stack, int num)
{
	int i;
	int next;

	i = stack->size_b - 1;
	next = stack->b_min;
	if (num > stack->b[stack->b_max] || num < stack->b[stack->b_min])
		return (stack->b_max <  (stack->size_b + 1) / 2 ?
			stack->b_max : stack->b_max - stack->size_b);
	while ( i >= 0)
	{
		if (stack->b[i] < num && stack->b[i] > stack->b[next])
			next = i;
		i--;
	}
	return (next < (stack->size_b + 1) / 2) ? next : next - stack->size_b;
}
