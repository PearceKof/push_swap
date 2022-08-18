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

static char	**dup_arg(char **av, int ac)
{
	char	**arg;
	int		i;

	if (ft_strchr(av[1], ' '))
		arg = ft_split(av[1], ' ');
	else
	{
		i = 0;
		arg = malloc(ac * sizeof(char *));
		if (!arg)
			return (NULL);
		while (av[i + 1])
		{
			arg[i] = ft_strdup(av[i + 1]);
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;

	if (ac < 2)
		return (0);
	arg = dup_arg(av, ac);
	if (!arg)
		quit(1, NULL);
	if (!is_nbr_valid(arg))
	{
		ft_freetab(arg);
		quit(1, NULL);
	}
	b = NULL;
	a = fill_stack_a(arg);
	sort_stack(&a, &b, stack_size(a));
	quit(0, &a);
}
