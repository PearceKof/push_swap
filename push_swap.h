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
init_stack.c
*/
void	fill_index(t_stack *a, int size);
t_stack	*fill_stack_a(int ac, char  **av);
void	init_target_pos(t_stack *ptra, t_stack *ptrb);
void	init_pos_and_cost(t_stack **a, t_stack **b);
/*
sort.c
*/
void	sort_stack(t_stack **a, t_stack **b, int ac);
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
int		is_nbr_valid(char **nbr);
long int	ft_atol(const char *str);
void	quit(char *error, t_stack **stack);
void print_stack(t_stack *a, t_stack *b);
int	is_sorted(t_stack *stack, int ac);
#endif