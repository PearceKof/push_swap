#include "push_swap.h"

void	fill_index(t_stack *a, int size)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		nb;

	while(size-- > 0)
	{
		ptr = a;
		nb = INT_MIN;
		biggest = NULL;
		while (ptr)
		{
			if (ptr->nbr == INT_MIN && !ptr->index)
				ptr->index = 1;
			if (ptr->nbr > nb && !ptr->index)
			{
				biggest = ptr;
				nb = ptr->nbr;
				ptr = a;
			}
			ptr = ptr->next;
		}
		if (biggest)
			biggest->index = size;
	}
}

t_stack	*fill_stack_a(int ac, char  **av)
{
	t_stack	*a;
	int		nb;
	int		i;

	nb = 0;
	a = NULL;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			a = new_stack(nb);
		else
			add_stack(&a, new_stack(nb));
		i++;
	}
	fill_index(a, ac);
	return (a);
}
