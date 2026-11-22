/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_number.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: pnanna <pnanna@student.42bangkok.com>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/22 15:29:28 by pnanna           #+#    #+#              */
/*   Updated: 2026/11/22 15:45:56 by pnanna          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long long	nb;
	int			count;
	int			result;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		count++;
		nb = -nb;
	}
	result = ft_putbase((uintptr_t) nb, "0123456789", 10);
	if (result < 0)
		return (-1);
	return (count + result);
}

int	ft_putunbr(unsigned int n)
{
	return (ft_putbase(n, "0123456789", 10));
}

int	ft_puthex(uintptr_t n, const char *digits)
{
	return (ft_putbase(n, digits, 16));
}
