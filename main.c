
#include "push_swap.h"

/*typedef struct s_stack
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

void	quit(char *error, t_stack **stack)
{
	if (stack)
		del_stack(stack);
	if (error)
	{
		ft_fprintf(STDERR_FILENO, "ERROR\n%s\n", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	// t_stack	*b;

	if (ac < 2)
		return (0);
	if (!is_nbr_valid(av))
		quit("All arguments needs to be an unique number", NULL);
	// b = NULL;
	a = fill_stack_a(ac, av);
	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	// if (ac == 3)
	// else if (ac > 3)
	return (0);
}
