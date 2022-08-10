/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:12:32 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/10 17:28:21 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylib/includes/libft.h"
# include "mylib/includes/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
/*
move.c
*/
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);
/*
init_stack.c
*/
void	fill_index(t_stack *a, int size);
t_stack	*fill_stack_a(int ac, char **av);
void	find_target_and_position(t_stack **a, t_stack **b);
/*
sort.c
*/
void	pb_all_but_three(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b, int ac);
void	get_cost(t_stack **a, t_stack **b);
void	move_cheapest(t_stack **a, t_stack **b);
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
push.c
swap.c
rotate.c et +
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
int		is_sorted(t_stack *stack);
int		is_nbr_valid(char **nbr);
long intft_atol(const char *str);
void	quit(char *error, t_stack **stack);
#endif