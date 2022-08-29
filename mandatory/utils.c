/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:48 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/29 13:42:31 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**dup_arg(int ac, char **av)
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

void	quit(int error, t_stack **stack)
{
	if (stack)
		del_stack(stack);
	if (error)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

static int	is_double(long nb, char **nblist)
{
	long	nbbis;
	int		i;

	i = 1;
	while (nblist[i])
	{
		nbbis = ft_atol(nblist[i++]);
		if (nb == nbbis)
			return (1);
	}
	return (0);
}

int	is_nbr_valid(char **nbr)
{
	long	nb;
	size_t	i;
	size_t	j;

	i = 0;
	while (nbr[i])
	{
		j = 0;
		if ((nbr[i][0] == '-' || nbr[i][0] == '+') && nbr[i][1])
			j++;
		else if (!nbr[i][0])
			return (0);
		while (nbr[i][j])
		{
			if (!ft_isdigit(nbr[i][j]))
				return (0);
			j++;
		}
		nb = ft_atol(nbr[i]);
		if ((nb < INT_MIN || nb > INT_MAX) || is_double(nb, &nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
