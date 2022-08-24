/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:14 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 18:19:23 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rra(t_stack **a, int printmv)
{
	reverse_rotate(a);
	if (printmv)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int printmv)
{
	reverse_rotate(b);
	if (printmv)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b, int printmv)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (printmv)
		ft_putstr_fd("rrr\n", 1);
}
