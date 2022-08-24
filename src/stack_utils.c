/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:43 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 15:22:17 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_size(t_stack *stack)
{
	if (stack)
		return (1 + stack_size(stack->next));
	else
		return (0);
}

t_stack	*get_last_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	del_stack(t_stack **stack)
{
	if (*stack)
	{
		del_stack(&((*stack)->next));
		free(*stack);
		*stack = NULL;
	}
}
