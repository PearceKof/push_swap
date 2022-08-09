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

void print_stack(t_stack *a, t_stack *b)
{
	printf("a:\n");
	while (a)
	{
		printf("nbr: %d index: %d target : %d\n", a->nbr, a->index, a->target_pos);
		a = a->next;
	}
	printf("b:\n");
	while (b)
	{
		printf("nbr: %d index: %d cost_b: %d, cost_a: %d\n", b->nbr, b->index, b->cost_b, b->cost_a);
		b = b->next;
	}
}

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
	// print_stack(a, b);
	return (EXIT_SUCCESS);
}
