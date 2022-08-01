#include "push_swap.h"

void	super_sort_ultimax(t_stack **a, t_stack **b, int index_max)
{
	printf("MAX INED= %d\n", index_max);
	while (stack_size(*a) > (index_max / 2) && stack_size(*a) > 3)
	{
		if ((*a)->index <= (index_max / 2))
			pb(a, b);
		else
			ra(a);
		printf("\nFIRST\n");
		print_stack(*a, *b);
	}
	while (stack_size(*a) > 3)
	{
		pb(a, b);
		printf("\nSECOND\n");
		print_stack(*a, *b);
	}
	sort_three(a);
}

void	sort_stack(t_stack **a, t_stack **b, int ac)
{
	(void)b;
	if (ac == 3 && (*a)->index == 2)
		sa(a);
	else if (ac == 4)
		sort_three(a);
	else if (ac > 4)
		super_sort_ultimax(a, b, ac);
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
