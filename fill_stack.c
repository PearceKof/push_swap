/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:16 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/18 16:39:45 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		nb;
	int		i;

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
