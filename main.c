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
/*
typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
*/

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!is_nbr_valid(av))
		quit("All arguments needs to be an unique number", NULL);
	b = NULL;
	a = fill_stack_a(ac, av);
	tmp = a;
	a = tmp;
	sort_stack(&a, &b, ac);
	return (EXIT_SUCCESS);
}
