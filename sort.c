#include "push_swap.h"

void	put_in_stack_b(t_stack **a, t_stack **b)
{
	int	size;
	int	med;

	size = stack_size(*a);
	med = size / 2;
	while (size > med && size > 3)
	{
		if ((*a)->index <= med)
			pb(a, b);
		if ((*a)->index > med)
			ra(a);
		size = stack_size(*a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
}

void	sort_stack(t_stack **a, t_stack **b, int ac)
{
	(void)b;
	if (ac == 3 && (*a)->index == 2)
		sa(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac > 4)
	{
		put_in_stack_b(a, b);
		sort_three(a);
		// while (!is_sorted(*a, ac))
		// {
		// }
			init_pos_and_cost(a, b);
	}
}

void	sort_three(t_stack **a)
{
	if ((*a)->index == 1 && (*a)->next->index == 2)
		return ;
	if ((*a)->index < (*a)->next->index && (*a)->next->index > (*a)->next->next->index)
		rra(a);//1 < 3 > 2 || 2 < 3 > 1
	if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
		ra(a);// 3 > 1 < 2 || 3 > 2 > 1
	if ((*a)->index > (*a)->next->index)
		sa(a);// 2 1 3
}
