/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:11:54 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/10 17:15:15 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(a);
			cost_a--;
		}
		else if (cost_a < 0)
		{
			rra(a);
			cost_a++;
		}
	}
}

static void	rotate_b(t_stack **b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rb(b);
			cost_b--;
		}
		else if (cost_b < 0)
		{
			rrb(b);
			cost_b++;
		}
	}
}

void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
	pa(a, b);
}
