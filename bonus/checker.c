/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:48:13 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 20:29:14 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static void	result(t_stack *a, t_stack *b, char **arg, int error)
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
	if (error)
		exit(255);
	exit(EXIT_SUCCESS);
}

static int	do_move(t_stack **a, t_stack **b, char *moves)
{
	if (!ft_strncmp(moves, "pa\n", ft_strlen(moves)))
		pa(a, b, 0);
	else if (!ft_strncmp(moves, "pb\n", ft_strlen(moves)))
		pb(a, b, 0);
	else if (!ft_strncmp(moves, "ss\n", ft_strlen(moves)))
		ss(a, b, 0);
	else if (!ft_strncmp(moves, "sa\n", ft_strlen(moves)))
		sa(a, 0);
	else if (!ft_strncmp(moves, "sb\n", ft_strlen(moves)))
		sb(b, 0);
	else if (!ft_strncmp(moves, "ra\n", ft_strlen(moves)))
		ra(a, 0);
	else if (!ft_strncmp(moves, "rb\n", ft_strlen(moves)))
		rb(b, 0);
	else if (!ft_strncmp(moves, "rr\n", ft_strlen(moves)))
		rr(a, b, 0);
	else if (!ft_strncmp(moves, "rra\n", ft_strlen(moves)))
		rra(a, 0);
	else if (!ft_strncmp(moves, "rrb\n", ft_strlen(moves)))
		rrb(b, 0);
	else if (!ft_strncmp(moves, "rrr\n", ft_strlen(moves)))
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

static int	get_moves(t_stack **a, t_stack **b)
{
	char	*file;
	char	*in;

	file = NULL;
	in = gnl(&file, STDIN_FILENO);
	while (in)
	{
		if (do_move(a, b, in))
		{
			free(file);
			free(in);
			return (1);
		}
		free(in);
		in = gnl(&file, STDIN_FILENO);
	}
	if (in)
		free(in);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;

	if (ac < 2)
		return (0);
	arg = dup_arg(ac, av);
	if (!arg)
		result(NULL, NULL, NULL, 1);
	if (!is_nbr_valid(arg))
		result(NULL, NULL, arg, 1);
	b = NULL;
	a = fill_stack_a(arg);
	if (!a)
		result(NULL, NULL, arg, 1);
	if(get_moves(&a, &b))
		result(a, b, NULL, 1);
	result(a, b, NULL, 0);
}