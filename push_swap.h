/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:32 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/18 16:28:45 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylib/includes/libft.h"
# include "mylib/includes/ft_printf.h"

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
/*
move.c
*/
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);
/*
init_stack.c
*/
t_stack	*fill_stack_a(char **av);
void	find_target_and_position(t_stack **a, t_stack **b);
/*
sort.c
*/
void	pb_all_but_three(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b, int ac);
int		get_abs(int nb);
void	sort_three(t_stack **a);
/*
stack_utils.c
*/
int		stack_size(t_stack *stack);
t_stack	*new_stack(int nbr);
void	add_stack(t_stack **stack, t_stack *new);
t_stack	*get_last_stack(t_stack *stack);
void	del_stack(t_stack **stack);
/*
actions
*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
/*
utils.c
*/
int		is_nbr_valid(char **nbr);
int		is_sorted(t_stack *stack);
void	quit(int error, t_stack **stack);
#endif