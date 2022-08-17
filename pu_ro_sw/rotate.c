/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:17 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 16:25:26 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = get_last_stack(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", STDIN_FILENO);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", STDIN_FILENO);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDIN_FILENO);
}
