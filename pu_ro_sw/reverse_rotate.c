/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:14 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 16:25:01 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr_fd("rra\n", STDIN_FILENO);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", STDIN_FILENO);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", STDIN_FILENO);
}
