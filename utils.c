#include "push_swap.h"

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

int	get_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

long int	ft_atol(const char *str)
{
	char		neg;
	int			i;
	long int	value;

	neg = 1;
	i = 0;
	value = 0;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' 
			&& ((value * neg) > INT_MIN || (value * neg) < INT_MAX))
		value = (value * 10) + str[i++] - '0';
	return (value * neg);
}

int	is_double(long nb, char **nblist)
{
	long	nbbis;
	size_t	i;

	i = 1;
	while (nblist[i])
	{
		nbbis = ft_atol(nblist[i++]);
		if (nb == nbbis)
			return (1);
	}
	return (0);
}

int	is_nbr_valid(char **nbr)
{
	long	nb;
	size_t	i;

	i = 1;
	while (nbr[i])
	{
		nb = ft_atol(nbr[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			quit("All numbers must be in the maxmin int limit", NULL);
		if (is_double(nb, &nbr[i]))
			quit("All numbers must be unique", NULL);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
