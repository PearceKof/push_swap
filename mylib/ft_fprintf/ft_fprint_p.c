/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:15:52 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/04 14:15:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fprint_p(va_list param, int *size, char *base, int std)
{
	void	*ad;

	ad = (void *)va_arg(param, void *);
	*size += write(std, "0x", 2);
	*size += ft_putnbr_base((unsigned long long)ad, 16, base, std);
}
