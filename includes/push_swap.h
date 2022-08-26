/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:32 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/26 13:23:39 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_ra;
	int				cost_rb;
	struct s_stack	*next;
}	t_stack;

char	**dup_arg(int ac, char **av);
t_stack	*get_last_stack(t_stack *stack);
t_stack	*fill_stack_a(char **av);
int		is_sorted(t_stack *stack);
int		get_abs(int nb);
int		stack_size(t_stack *stack);
int		is_nbr_valid(char **nbr);
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	find_target_and_position(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b, int ac);
void	quit(int error, t_stack **stack);
void	del_stack(t_stack **stack);
void	pa(t_stack **a, t_stack **b, int printmv);
void	pb(t_stack **a, t_stack **b, int printmv);
void	ss(t_stack **a, t_stack **b, int printmv);
void	sa(t_stack **a, int printmv);
void	sb(t_stack **b, int printmv);
void	ra(t_stack **a, int printmv);
void	rb(t_stack **b, int printmv);
void	rr(t_stack **a, t_stack **b, int printmv);
void	rra(t_stack **a, int printmv);
void	rrb(t_stack **b, int printmv);
void	rrr(t_stack **a, t_stack **b, int printmv);

#endif