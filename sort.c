/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:40 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/19 13:07:12 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*ptr;
	int		biggest;

	if (is_sorted(*a))
		return ;
	ptr = *a;
	biggest = ptr->index;
	while (ptr)
	{
		if (ptr->index > biggest)
			biggest = ptr->index;
		ptr = ptr->next;
	}
	ptr = *a;
	if ((*a)->next->index == biggest)
		rra(a);
	else if ((*a)->index == biggest)
		ra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	pb_all_but_three(t_stack **a, t_stack **b)
{
	t_stack	*last;
	int		size_a;
	int		size_b;
	int		i;

	size_a = stack_size(*a);
	size_b = 0;
	i = 0;
	if (size_a > 6)
	{
		while (i < size_a && size_b < size_a / 2)
		{
			last = get_last_stack(*a);
			if ((*a)->index <= size_a / 2)
			{
				pb(a, b);
				size_b++;
			}
			else
				ra(a);
			i++;
		}
	}
	while (stack_size(*a) > 3)
		pb(a, b);
}

static void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*ptra;
	t_stack	*ptrb;
	int		size_a;
	int		size_b;

	ptra = *a;
	ptrb = *b;
	size_a = stack_size(ptra);
	size_b = stack_size(ptrb);
	while (ptrb)
	{
		if (ptrb->pos > size_b / 2)
			ptrb->cost_b = (size_b - ptrb->pos) * -1;
		else
			ptrb->cost_b = ptrb->pos;
		if (ptrb->target_pos > size_a / 2)
			ptrb->cost_a = (size_a - ptrb->target_pos) * -1;
		else
			ptrb->cost_a = ptrb->target_pos;
		ptrb = ptrb->next;
	}
}

static void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*ptrb;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	ptrb = *b;
	while (ptrb)
	{
		if (get_abs(ptrb->cost_b) + get_abs(ptrb->cost_a) < cheapest)
		{
			cheapest = get_abs(ptrb->cost_b) + get_abs(ptrb->cost_a);
			cost_a = ptrb->cost_a;
			cost_b = ptrb->cost_b;
		}
		ptrb = ptrb->next;
	}
	move(a, b, cost_a, cost_b);
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 2 && (*a)->index == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
	{
		pb_all_but_three(a, b);
		sort_three(a);
		while (*b)
		{
			find_target_and_position(a, b);
			get_cost(a, b);
			move_cheapest(a, b);
		}
		while (!is_sorted(*a))
		{
			if ((*a)->index >= stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
		}
	}
}
