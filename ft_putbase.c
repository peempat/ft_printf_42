/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putbase.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: pnanna <pnanna@student.42bangkok.com>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/22 15:46:10 by pnanna           #+#    #+#              */
/*   Updated: 2026/11/22 15:48:08 by pnanna          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(uintptr_t n, const char *digits, unsigned int base)
{
	int	count;
	int	result;

	count = 0;
	if (n >= base)
	{
		result = ft_putbase(n / base, digits, base);
		if (result < 0)
			return (-1);
		count += result;
	}
	if (ft_putchar(digits[n % base]) < 0)
		return (-1);
	return (count + 1);
}
