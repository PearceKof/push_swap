/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:20 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 17:40:45 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	ptr1->next = ptr1->next->next;
	ptr2->next = ptr1;
	*stack = ptr2;
}

void	ss(t_stack **a, t_stack **b, int printmv)
{
	swap(a);
	swap(b);
	if (printmv)
		ft_putstr_fd("ss\n", 1);
}

void	sa(t_stack **a, int printmv)
{
	swap(a);
	if (printmv)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int printmv)
{
	swap(b);
	if (printmv)
		ft_putstr_fd("sb\n", 1);
}
