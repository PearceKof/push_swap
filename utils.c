#include "push_swap.h"

int	is_double(char *nbr, char **nbrlist)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (nbrlist[j])
	{
		while (nbrlist[j][i] && nbr[i] && nbrlist[j][i] == nbr[i])
			i++;
		if (nbrlist[j][i] == '\0' && nbr[i] == '\0')
			return (1);
		i = 0;
		j++;
	}
	return (0);
}

int	is_nbr_valid(char **nbr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (nbr[j])
	{
		if (is_double(nbr[j], nbr + (j + 1)))
			return (0);
		while (nbr[j][i])
		{
			if (!ft_isdigit(nbr[j][i++]))
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}
