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
	char	**nbrlist;
	t_stack	*a;
	int		nb;
	int		i;

	nb = 0;
	a = NULL;
	i = 0;
	if (ft_strchr(*av, ' '))
		nbrlist = ft_split(*av, ' ');
	else
	{
		nbrlist = malloc(ac * sizeof(char *));
		if (!nbrlist)
			return (NULL);
		i = 0;
		while (av[i])
		{
			nbrlist[i] = ft_strdup(av[i]);
			i++;
		}
		nbrlist[i] = NULL;
	}
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(nbrlist[i]);
		if (i == 1)
			a = new_stack(nb);
		else
			add_stack(&a, new_stack(nb));
		i++;
	}
	fill_index(a, ac);
	return (a);
}

void	init_target_pos(t_stack *ptra, t_stack *ptrb)
{
	while (ptra)
	{
		if (ptra->index > ptrb->index)
			ptrb->target_pos = ptra->pos;
		// else if (ptra->index < ptrb->index)
		// 	ptrb->target_pos = ptra->pos;
		ptra = ptra->next;
	}
}

void	init_pos_and_cost(t_stack **a, t_stack **b)
{
	t_stack	*ptra;
	t_stack	*ptrb;
	int		i;

	i = 0;
	ptra = *a;
	ptrb = *b;
	while (ptra)
	{
		ptra->pos = i++;
		ptra = ptra->next;
	}
	i = 0;
	while (ptrb)
	{
		ptra = *a;
		init_target_pos(ptra, ptrb);
		ptrb->pos = i++;
		ptrb = ptrb->next;
	}
}
