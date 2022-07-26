#include "push_swap.h"

t_stack	*fill_stack_a(int ac, char  **av)
{
	t_stack	*a;
	int		i;
	long	nbr;

	i = 1;
	nbr = 0;
	a = NULL;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (i == 1)
			a = new_stack(nbr);
		else
			add_stack(&a, new_stack(nbr));
		i++;
	}
	return (a);
}

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
