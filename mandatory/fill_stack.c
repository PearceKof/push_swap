/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:16 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/25 16:44:28 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*new_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_ra = -1;
	new->cost_rb = -1;
	new->next = NULL;
	return (new);
}

static void	add_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	last = get_last_stack(*stack);
	last->next = new;
}

static void	fill_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		nb;

	while (size > 0)
	{
		ptr = a;
		nb = INT_MIN;
		biggest = NULL;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && !ptr->index)
				ptr->index = 1;
			if (ptr->nbr > nb && !ptr->index)
			{
				biggest = ptr;
				nb = ptr->nbr;
				ptr = a;
			}
			ptr = ptr->next;
		}
		if (biggest)
			biggest->index = size;
		size--;
	}
}

t_stack	*fill_stack_a(char **arg)
{
	t_stack	*a;
	int		i;
	int		nb;

	nb = 0;
	a = NULL;
	i = 0;
	while (arg[i])
	{
		nb = ft_atoi(arg[i]);
		if (!i)
			a = new_stack(nb);
		else
			add_stack(&a, new_stack(nb));
		if (!a)
		{
			ft_freetab(arg);
			quit(1, &a);
		}
		i++;
	}
	ft_freetab(arg);
	fill_index(a, stack_size(a));
	return (a);
}
