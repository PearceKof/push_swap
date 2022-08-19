/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:48 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/19 11:30:11 by blaurent         ###   ########.fr       */
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

int	is_nbr_valid(char **nbr)
{
	long	nb;
	size_t	i;
	size_t	j;

	i = 0;
	while (nbr[i])
	{
		j = 0;
		if (nbr[i][0] == '-' || nbr[i][0] == '+')
			j++;
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

int	get_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
