/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_pointer.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: pnanna <pnanna@student.42bangkok.com>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/22 15:46:31 by pnanna           #+#    #+#              */
/*   Updated: 2026/11/22 15:46:31 by pnanna          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	result;

	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") < 0)
		return (-1);
	result = ft_puthex((uintptr_t) ptr, "0123456789abcdef");
	if (result < 0)
		return (-1);
	return (result + 2);
}
