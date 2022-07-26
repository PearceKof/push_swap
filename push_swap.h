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
}	t_stack;

int		is_nbr_valid(char **nbr);
void	quit(char *error, t_stack **stack);

t_stack	*fill_stack_a(int ac, char  **av);
t_stack *new_stack(int nbr);
void	add_stack(t_stack **stack, t_stack *new);
t_stack	*get_last_stack(t_stack *stack);
void	del_stack(t_stack **stack);

#endif