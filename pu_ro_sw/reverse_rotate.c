#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*last;
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	new_last = *stack;
	while (new_last->next->next)
		new_last = new_last->next;
	last = get_last_stack(*stack);
	*stack = last;
	last->next = first;
	new_last->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}