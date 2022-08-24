/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:48:13 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 18:11:50 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	result(t_stack *a, t_stack *b, char **arg, char **moves, int error)
{
	if (error)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else 
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	if (a)
		del_stack(&a);
	if (b)
		del_stack(&b);
	if (arg)
		ft_freetab(arg);
	if (moves)
		ft_freetab(moves);
	exit(EXIT_SUCCESS);
}

char	**get_moves()
{
	char	**moves;
	char	*in;

	in = gnl(STDIN_FILENO);
	moves = ft_split(in, '\n');
	return (moves);
}

int	do_move(t_stack **a, t_stack **b, char *moves)
{
	if (!ft_strncmp(moves, "pa", ft_strlen(moves)))
		pa(a, b, 0);
	else if (!ft_strncmp(moves, "pb", ft_strlen(moves)))
		pb(a, b, 0);
	else if (!ft_strncmp(moves, "ss", ft_strlen(moves)))
		ss(a, b, 0);
	else if (!ft_strncmp(moves, "sa", ft_strlen(moves)))
		sa(a, 0);
	else if (!ft_strncmp(moves, "sb", ft_strlen(moves)))
		sb(b, 0);
	else if (!ft_strncmp(moves, "ra", ft_strlen(moves)))
		ra(a, 0);
	else if (!ft_strncmp(moves, "rb", ft_strlen(moves)))
		rb(b, 0);
	else if (!ft_strncmp(moves, "rr", ft_strlen(moves)))
		rr(a, b, 0);
	else if (!ft_strncmp(moves, "rra", ft_strlen(moves)))
		rra(a, 0);
	else if (!ft_strncmp(moves, "rrb", ft_strlen(moves)))
		rrb(b, 0);
	else if (!ft_strncmp(moves, "rrr", ft_strlen(moves)))
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

int	find_move(t_stack **a, t_stack **b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (do_move(a, b, moves[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;
	char	**moves;

	if (ac < 2)
		return (0);
	arg = dup_arg(ac, av);
	if (!arg)
		result(NULL, NULL, NULL, NULL, 1);
	if (!is_nbr_valid(arg))
		result(NULL, NULL, arg, NULL, 1);
	moves = get_moves();
	if (!moves)
		result(NULL, NULL, arg, NULL, 1);
	b = NULL;
	a = fill_stack_a(arg);
	if (!a)
		result(NULL, NULL, arg, moves, 1);
	result(a, b, NULL, moves, find_move(&a, &b, moves));
}