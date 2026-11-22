/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnanna <pnanna@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 15:46:13 by pnanna            #+#    #+#             */
/*   Updated: 2026/11/22 16:00:12 by pnanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_putchar((char) va_arg(*args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (spec == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (spec == 'X')
		return (ft_puthex(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (spec == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_parse(const char *format, va_list *args)
{
	int	count;
	int	result;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result = ft_convert(*format, args);
		}
		else
			result = ft_putchar(*format);
		if (result < 0)
			return (-1);
		count += result;
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	result = ft_parse(format, &args);
	va_end(args);
	return (result);
}
