/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:48 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/17 16:23:31 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int error, t_stack **stack)
{
	if (stack)
		del_stack(stack);
	if (error)
	{
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
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
