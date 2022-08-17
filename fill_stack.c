/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:16 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 14:33:10 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		nb;

	while (size-- > 0)
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
	}
}

static char	**dup_arg(char **av, int ac)
{
	char	**arg;
	int		i;

	if (ft_strchr(av[1], ' '))
		arg = ft_split(av[1], ' ');
	else
	{
		av++;
		i = 0;
		arg = malloc(ac * sizeof(char *));
		if (!arg)
			return (NULL);
		while(av[i])
		{
			arg[i] = ft_strdup(av[i]);
			if (!arg[i])
			{
				ft_freetab(arg);
				return (NULL);
			}
			i++;
		}
		arg[i] = NULL;
	}
	return (arg);
}

t_stack	*fill_stack_a(int ac, char **av)
{
	char	**arg;
	t_stack	*a;
	int		nb;
	int		i;

	nb = 0;
	a = NULL;
	arg = dup_arg(av, ac);
	if (!arg)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		nb = ft_atoi(arg[i]);
		if (!i)
			a = new_stack(nb);
		else
			add_stack(&a, new_stack(nb));
		i++;
	}
	fill_index(a, stack_size(a));
	return (a);
}
