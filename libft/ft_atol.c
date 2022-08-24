/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:52:57 by blaurent          #+#    #+#             */
/*   Updated: 2022/08/24 18:13:56 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *str)
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
