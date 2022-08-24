/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:17 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 18:19:27 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ra(t_stack **a, int printmv)
{
	rotate(a);
	if (printmv)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int printmv)
{
	rotate(b);
	if (printmv)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int printmv)
{
	rotate(a);
	rotate(b);
	if (printmv)
		ft_putstr_fd("rr\n", 1);
}
