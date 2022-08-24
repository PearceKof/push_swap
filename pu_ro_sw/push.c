/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:11 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 18:19:15 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b, int printmv)
{
	push(b, a);
	if (printmv)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b, int printmv)
{
	push(a, b);
	if (printmv)
		ft_putstr_fd("pb\n", 1);
}
