/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:19:11 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 16:24:40 by blaurent         ###   ########.fr       */
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
	ft_putstr_fd("pa\n", STDIN_FILENO);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", STDIN_FILENO);
}
