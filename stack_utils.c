#include "push_swap.h"

t_stack *new_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	add_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	last = get_last_stack(*stack);
	last->next = new;
}

int	stack_size(t_stack *stack)
{
	if (stack)
		return (1 + stack_size(stack->next));
	else
		return (0);
}

t_stack	*get_last_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	del_stack(t_stack **stack)
{
	if (*stack)
	{
		del_stack(&((*stack)->next));
		free(*stack);
		*stack = NULL;
	}
}
