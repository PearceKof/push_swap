/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:20 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 16:25:56 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", STDIN_FILENO);
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", STDIN_FILENO);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", STDIN_FILENO);
}
