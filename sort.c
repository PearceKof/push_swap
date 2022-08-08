#include "push_swap.h"

void	pb_all_but_three(t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(*a);
	b_size = 0;
	while (a_size > 6 && b_size < a_size / 2)
	{
		if ((*a)->index <= a_size / 2)
		{
			pb(a, b);
			b_size++;
		}
		else
			ra(a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
}

void	sort_stack(t_stack **a, t_stack **b, int ac)
{
	if (ac == 3 && (*a)->index == 2)
		sa(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac > 4)
	{
		pb_all_but_three(a, b);
		sort_three(a);
		while (*b)
		{
			find_target_and_position(a, b);
			get_cost(a, b);
		}
	}
}

static int	get_biggest_index(t_stack *stack)
{
	int	biggest;

	biggest = stack->index;
	while (stack)
	{
		if (stack->index > biggest)
			biggest = stack->index;
		stack = stack->next;
	}
	return (biggest);
}

void	sort_three(t_stack **a)
{
	int	biggest;

	if (is_sorted(*a))
		return ;
	biggest = get_biggest_index(*a);
	if ((*a)->next->index == biggest)
		rra(a);
	else if ((*a)->index == biggest)
		ra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}
