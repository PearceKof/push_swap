/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:40 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/29 14:40:09 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack **a)
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
	if ((*a)->next->index == biggest)
		rra(a, 1);
	else if ((*a)->index == biggest)
		ra(a, 1);
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
}

void	pb_all_but_three(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = 0;
	while (size_a > 6 && size_b < size_a / 2)
	{
		if ((*a)->index <= size_a / 2)
		{
			pb(a, b, 1);
			size_b++;
		}
		else
			ra(a, 1);
	}
	while (stack_size(*a) > 3)
		pb(a, b, 1);
}

static void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*ptrb;
	int		size_a;
	int		size_b;

	ptrb = *b;
	size_a = stack_size(*a);
	size_b = stack_size(ptrb);
	while (ptrb)
	{
		if (ptrb->pos > size_b / 2)
			ptrb->cost_rb = (size_b - ptrb->pos) * -1;
		else
			ptrb->cost_rb = ptrb->pos;
		if (ptrb->target_pos > size_a / 2)
			ptrb->cost_ra = (size_a - ptrb->target_pos) * -1;
		else
			ptrb->cost_ra = ptrb->target_pos;
		ptrb = ptrb->next;
	}
}

static void	move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*ptrb;
	int		cheapest;
	int		cost_ra;
	int		cost_rb;

	cheapest = INT_MAX;
	ptrb = *b;
	while (ptrb)
	{
		if (get_abs(ptrb->cost_rb) + get_abs(ptrb->cost_ra) < cheapest)
		{
			cheapest = get_abs(ptrb->cost_rb) + get_abs(ptrb->cost_ra);
			cost_ra = ptrb->cost_ra;
			cost_rb = ptrb->cost_rb;
		}
		ptrb = ptrb->next;
	}
	move(a, b, cost_ra, cost_rb);
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 2 && (*a)->index == 2)
		sa(a, 1);
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
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
}
