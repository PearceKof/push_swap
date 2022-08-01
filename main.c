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
	printf("\na:\n");
	while (a)
	{
		printf("%d %d\n", a->nbr, a->index);
		a = a->next;
	}
	printf("b:\n");
	while (b)
	{
		printf("%d %d\n", b->nbr, b->index);
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
	print_stack(a, b);
	a = tmp;
	sort_stack(&a, &b, ac);
	print_stack(a, b);
	return (0);
}
