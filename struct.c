#include "push_swap.h"

int 		*init_array(int size)
{
	int		*ar;

	ar = (int*)malloc(sizeof(int) * size);
	if (!ar)
		return (NULL);
	ft_memset(ar, 0, size * sizeof(int));
	return (ar);
}

void 		reset_stack(t_stack *stack)
{
	stack->t_rots = 0;
	stack->a_rots = 0;
	stack->b_rots = 0;
	stack->b_max = 0;
	stack->b_min = 0;
}

void 	free_stack(t_stack *stack)
{
	free(stack->a);
	stack->a = NULL;
	free(stack->b);
	stack->b = NULL;
	ft_lstfree(stack->ops);
	free(stack);

}

t_stack 	*initstack(void)
{
	t_stack *stack;

	stack = (t_stack*)ft_memalloc(sizeof(t_stack));
	stack->features = 0;
	stack->ops = NULL;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->b_max = 0;
	stack->b_min = 0;
	stack->t_rots = 0;
	stack->a_rots = 0;
	stack->b_rots = 0;

	return (stack);
}
