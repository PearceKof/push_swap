/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:11 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/10 17:19:12 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
