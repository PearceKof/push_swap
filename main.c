/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:03 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/10 17:12:03 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_double(long nb, char **nblist)
{
	long	nbbis;
	size_t	i;

	i = 1;
	while (nblist[i])
	{
		nbbis = ft_atol(nblist[i++]);
		if (nb == nbbis)
			return (1);
	}
	return (0);
}

static int	is_nbr_valid(char **nbr)
{
	long	nb;
	size_t	i;
	size_t	j;

	i = 1;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i][j])
		{
			while (nbr[i][j] == '-' || nbr[i][j] == '+')
				j++;
			if (!ft_isdigit(nbr[i][j++]))
				return (0);
		}
		nb = ft_atol(nbr[i]);
		if ((nb < INT_MIN || nb > INT_MAX) || is_double(nb, &nbr[i++]))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!is_nbr_valid(av))
		quit(1, NULL);
	b = NULL;
	a = fill_stack_a(ac, av);
	sort_stack(&a, &b, stack_size(a));
	return (EXIT_SUCCESS);
}
