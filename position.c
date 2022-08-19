/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:12 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/19 13:06:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

static void	new_index_and_pos(t_stack *a, int *targ_ind, int *targ_pos)
{
	*targ_ind = a->index;
	*targ_pos = a->pos;
}

static int	get_target_position(t_stack **a, int index_b)
{
	t_stack	*ptra;
	int		nearest_ind;
	int		targ_pos;

	targ_pos = 0;
	nearest_ind = INT_MAX;
	ptra = *a;
	while (ptra)
	{
		if (ptra->index > index_b && ptra->index < nearest_ind)
			new_index_and_pos(ptra, &nearest_ind, &targ_pos);
		ptra = ptra->next;
	}
	if (nearest_ind != INT_MAX)
		return (targ_pos);
	ptra = *a;
	while (ptra)
	{
		if (ptra->index < nearest_ind)
			new_index_and_pos(ptra, &nearest_ind, &targ_pos);
		ptra = ptra->next;
	}
	return (targ_pos);
}

void	find_target_and_position(t_stack **a, t_stack **b)
{
	t_stack	*ptrb;

	get_pos(*a);
	get_pos(*b);
	ptrb = *b;
	while (ptrb)
	{
		ptrb->target_pos = get_target_position(a, ptrb->index);
		ptrb = ptrb->next;
	}
}
