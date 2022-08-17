/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:12 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/15 12:54:25 by blaurent         ###   ########.fr       */
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

static void	new_index_and_pos(t_stack *a, int *ind, int *pos)
{
	*ind = a->index;
	*pos = a->pos;
}

static int	get_target_position(t_stack **a, int index_b, int targ_pos)
{
	t_stack	*ptra;
	int		targ_ind;

	targ_ind = INT_MAX;
	ptra = *a;
	while (ptra)
	{
		if (ptra->index > index_b && ptra->index < targ_ind)
			new_index_and_pos(ptra, &targ_ind, &targ_pos);
		ptra = ptra->next;
	}
	if (targ_ind != INT_MAX)
		return (targ_pos);
	ptra = *a;
	while (ptra)
	{
		if (ptra->index < targ_ind)
			new_index_and_pos(ptra, &targ_ind, &targ_pos);
		ptra = ptra->next;
	}
	return (targ_pos);
}

void	find_target_and_position(t_stack **a, t_stack **b)
{
	t_stack	*ptrb;
	int		targ_pos;

	get_pos(*a);
	get_pos(*b);
	targ_pos = 0;
	ptrb = *b;
	while (ptrb)
	{
		targ_pos = get_target_position(a, ptrb->index, targ_pos);
		ptrb->target_pos = targ_pos;
		ptrb = ptrb->next;
	}
}
